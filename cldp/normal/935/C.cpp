#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long distL(int a, int b, int c, int d) {
    return 1LL * (a - c) * (a - c) + 1LL * (b - d) * (b - d);
}

double dist(double a, double b, double c, double d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
    ios_base::sync_with_stdio(false);
    int R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if (distL(x1, y1, x2, y2) >= 1LL * R * R) {
        cout << x1 << " " << y1 << " " << R << endl;
    } else 
    if (x1 != x2 || y1 != y2) {
        double D = dist(x1, y1, x2, y2);
        double x3 = x1 - 0.5 * (R - D) * (x2 - x1) / D;
        double y3 = y1 - 0.5 * (R - D) * (y2 - y1) / D;
        double R3 = 0.5 * (R + D);
        cout << fixed << setprecision(10) << x3 << " " << y3 << " " << R3 << endl;
    } else {
        cout << x1 + R * 0.5 << " " << y1 << " " << R * 0.5 << endl;
    }
    return 0;
}