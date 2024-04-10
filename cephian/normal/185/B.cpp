#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int s, a, b, c;
const double c1 = 1/3.0;
const double c2 = 2/3.0;
double eval(double x, double y) {
    return a*log(x) + b*log(y) + c*log(s - x - y);
}

double ts1(double x) {
    double lo = 0;
    double hi = s-x;
    for(int i = 0; i < 100; ++i) {
        double m1 = c2 * lo + c1 * hi;
        double m2 = c1 * lo + c2 * hi;
        if(eval(x, m1) < eval(x, m2)) lo = m1;
        else hi = m2;
    }
    return (lo+hi)/2;
}

int main() {
    cin >> s >> a >> b >> c;
    double lo = 0;
    double hi = s;
    for(int i = 0; i < 100; ++i) {
        double m1 = c2 * lo + c1 * hi;
        double m2 = c1 * lo + c2 * hi;
        if(eval(m1, ts1(m1)) < eval(m2, ts1(m2)))
            lo = m1;
        else hi = m2;
    }
    lo = (lo+hi)/2;
    cout << setprecision(15) << fixed;
    cout << lo << " " << ts1(lo) << " " << s-lo-ts1(lo) << "\n";

    return 0;
}