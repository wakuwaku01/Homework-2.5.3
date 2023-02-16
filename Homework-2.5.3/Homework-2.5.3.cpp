#include <iostream>
#include <string>

class Figure {
private:
    int sides;
    std::string name = "Фигура:";

public:
    Figure(int sides) { this->sides = sides; }
    virtual void print_name() { std::cout << name << std::endl; }
    virtual void print_sides() {
        std::cout << "Количество сторон: " << sides << std::endl;
    }
    virtual void print_angles() {}
    virtual bool check() {
        if (sides == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Triangle : public Figure {
private:
    std::string name = "Треугольник:";

protected:
    int sides;
    int side_a, side_b, side_c;
    int angle_A, angle_B, angle_C;

public:
    Triangle(int sides, int side_a, int side_b, int side_c, int angle_A,
        int angle_B, int angle_C)
        : Figure(0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
    }

    bool check() {
        if ((sides == 3) && (angle_A + angle_B + angle_C == 180))
            return true;
        else
            return false;
    }

    void print_name() { std::cout << name << std::endl; }

    void print_sides() {
        std::cout << "Количество сторон: " << sides << std::endl;
        std::cout << "Стороны: "
            << "a=" << side_a << " "
            << "b=" << side_b << " "
            << "c=" << side_c << " " << std::endl;
    }

    void print_angles() {
        std::cout << "Углы: "
            << "A=" << angle_A << " "
            << "B=" << angle_B << " "
            << "C=" << angle_C << " " << std::endl;
    }
};

class RightTriangle : public Triangle {
private:
    std::string name = "Прямоугольный треугольник:";

public:
    RightTriangle(int sides, int side_a, int side_b, int side_c, int angle_A,
        int angle_B, int angle_C)
        : Triangle(0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
    }
    bool check() {
        if (Triangle::check() && angle_C == 90)
            return true;
        else
            return false;
    }

    void print_name() { std::cout << name << std::endl; }
};

class IsoscelesTriangle : public Triangle {
private:
    std::string name = "Равнобедренный треугольник:";

public:
    IsoscelesTriangle(int sides, int side_a, int side_b, int side_c, int angle_A,
        int angle_B, int angle_C)
        : Triangle(0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
    }
    bool check() {
        if (Triangle::check() && (angle_A == angle_C && side_a == side_c))
            return true;
        else
            return false;
    }

    void print_name() { std::cout << name << std::endl; }
};

class EquilateralTriangle : public Triangle {
private:
    std::string name = "Равносторонний треугольник:";

public:
    EquilateralTriangle(int sides, int side_a, int side_b, int side_c,
        int angle_A, int angle_B, int angle_C)
        : Triangle(0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
    }
    bool check() {
        if (Triangle::check() && (side_a == side_b && side_b == side_c) &&
            (angle_A == angle_B && angle_B == angle_C))
            return true;
        else
            return false;
    }

    void print_name() { std::cout << name << std::endl; }
};

class Quadrangle : public Figure {
private:
    std::string name = "Четырёхугольник";

protected:
    int sides;
    int side_a, side_b, side_c, side_d;
    int angle_A, angle_B, angle_C, angle_D;

public:
    Quadrangle(int sides, int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Figure(0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;
    }
    bool check() {
        if ((sides == 4) && (angle_A + angle_B + angle_C + angle_D == 360))
            return true;
        else
            return false;
    }
    void print_name() { std::cout << name << std::endl; }
    void print_sides() {
        std::cout << "Количество сторон: " << sides << std::endl;
        std::cout << "Стороны: "
            << "a=" << side_a << " "
            << "b=" << side_b << " "
            << "c=" << side_c << " "
            << "d=" << side_d << std::endl;
    }
    void print_angles() {
        std::cout << "Углы: "
            << "A=" << angle_A << " "
            << "B=" << angle_B << " "
            << "C=" << angle_C << " "
            << "D=" << angle_D << std::endl;
    }
};

class Rectangle : public Quadrangle {
private:
    std::string name = "Прямоугольник:";

public:
    Rectangle(int sides, int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrangle(0, 0, 0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;
    }
    void print_name() { std::cout << name << std::endl; }
    bool check() {
        if (Quadrangle::check() &&
            ((angle_A == 90 && angle_B == 90) &&
                (angle_C == 90 && angle_D == 90)) &&
            (side_a == side_c && side_b == side_d))
            return true;
        else
            return false;
    }
};

class Square : public Quadrangle {
private:
    std::string name = "Квадрат:";

public:
    Square(int sides, int side_a, int side_b, int side_c, int side_d, int angle_A,
        int angle_B, int angle_C, int angle_D)
        : Quadrangle(0, 0, 0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;
    }
    void print_name() { std::cout << name << std::endl; }
    bool check() {
        if (Quadrangle::check() && (angle_A == 90 && angle_B == 90) &&
            (angle_C == 90 && angle_D == 90) && (side_a == side_b &&
                side_b == side_c && side_c == side_d))
            return true;
        else
            return false;
    }
};

class Parallelogram : public Quadrangle {
private:
    std::string name = "Параллелограмм:";

public:
    Parallelogram(int sides, int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrangle(0, 0, 0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;
    }
    void print_name() { std::cout << name << std::endl; }
    bool check() {
        if (Quadrangle::check() && (angle_A == angle_C && angle_B == angle_D) &&
            (side_a == side_c && side_b == side_d))
            return true;
        else
            return false;
    }
};

class Rhombus : public Quadrangle {
private:
    std::string name = "Ромб:";

public:
    Rhombus(int sides, int side_a, int side_b, int side_c, int side_d,
        int angle_A, int angle_B, int angle_C, int angle_D)
        : Quadrangle(0, 0, 0, 0, 0, 0, 0, 0, 0) {
        this->sides = sides;
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;
    }
    void print_name() { std::cout << name << std::endl; }
    bool check() {
        if (Quadrangle::check() && (angle_A == angle_C && angle_B == angle_D) &&
            (side_a == side_b) && (side_b == side_c) &&
            (side_c == side_d))
            return true;
        else
            return false;
    }
};

void print_info(Figure& figure) {
    figure.print_name();
    if (figure.check()) {
        std::cout << "Правильная" << std::endl;
    }
    else {
        std::cout << "Неправильная" << std::endl;
    }
    figure.print_sides();
    figure.print_angles();
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Figure figure(0);
    print_info(figure);

    Triangle triangle(3, 10, 15, 20, 50, 60, 70);
    print_info(triangle);

    RightTriangle right_triangle(3, 10, 15, 20, 30, 60, 90);
    print_info(right_triangle);

    IsoscelesTriangle isosceles_triangle(3, 10, 15, 10, 50, 80, 50);
    print_info(isosceles_triangle);

    EquilateralTriangle equilateral_triangle(3, 20, 20, 20, 60, 60, 60);
    print_info(equilateral_triangle);

    Quadrangle quadrangle(4, 10, 15, 20, 30, 70, 80, 90, 120);
    print_info(quadrangle);

    Rectangle rectangle(4, 10, 15, 10, 15, 90, 90, 90, 90);
    print_info(rectangle);

    Square square(4, 10, 10, 10, 10, 90, 90, 90, 90);
    print_info(square);

    Parallelogram parallelogram(4, 10, 15, 10, 15, 70, 110, 70, 110);
    print_info(parallelogram);

    Rhombus rhombus(4, 20, 20, 20, 20, 70, 110, 70, 110);
    print_info(rhombus);
}