#include <iostream>
#include <map>
#include <string>

class Car {
private:
    std::string make;
    std::string model;

public:
    Car(const std::string& make, const std::string& model) : make(make), model(model) {}

    void displayInfo() const {
        std::cout << "Car: " << make << " " << model << std::endl;
    }
};

class Driver {
private:
    std::string name;

public:
    Driver(const std::string& name) : name(name) {}

    void displayInfo() const {
        std::cout << "Driver: " << name << std::endl;
    }

    // Comparison operator for Driver class
    bool operator<(const Driver& other) const {
        return name < other.name;
    }
};

class DriverCarManager {
private:
    std::map<Driver, Car> driverCarMap;

public:
    void addDriverCar(const Driver& driver, const Car& car) {
        driverCarMap[driver] = car;
    }

    void removeDriverCar(const Driver& driver) {
        driverCarMap.erase(driver);
    }

    void displayAll() const {
        std::cout << "All Drivers and Cars:\n";
        for (const auto& pair : driverCarMap) {
            pair.first.displayInfo();
            pair.second.displayInfo();
            std::cout << "---------------------\n";
        }
        std::cout << "Number of elements: " << driverCarMap.size() << std::endl;
    }
};

int main() {
    Driver driver1("Alice");
    Car car1("Toyota", "Camry");

    Driver driver2("Bob");
    Car car2("Honda", "Accord");

    DriverCarManager driverCarManager;

    driverCarManager.addDriverCar(driver1, car1);
    driverCarManager.addDriverCar(driver2, car2);

    driverCarManager.displayAll();

    driverCarManager.removeDriverCar(driver1);

    std::cout << "\nAfter removing a driver:\n";
    driverCarManager.displayAll();

    return 0;
}
