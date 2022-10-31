#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    double a,b,c;
    cin >> a >> b >> c;
    double d = sqrt(b*b-4*a*c);
    cout << setprecision(15) << fixed;
    double x = (0.5)*(-b + d)/a;
    double y = (0.5)*(-b - d)/a;
    if(x < y) swap(x,y);
    cout << x << "\n" << y << "\n";
    return 0;
}