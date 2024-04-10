#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    long double x;
    cin >> x;
    for (int a = 1; a <= 10; ++a)
     for (int h = 1; h <= 10; ++h) {
         long double S = a * h * 0.5;
         long double L = sqrt((a * a * 0.25) + h * h);
         if (fabs(S / L - x) < 1e-5) {
             cout << a << " " << h << endl;
             return 0;
         }
     }
    return 0;
}