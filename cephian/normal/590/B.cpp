#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double X1, X2, Y1, Y2;
double vmax, t;
double vx, vy, wx, wy;

double s(double a){
    return a*a;
}

double ok(double time) {
        double xp = X2, yp = Y2;
        xp -= vx * min(time, t) + wx * max(time - t, 0.0);
        yp -= vy * min(time, t) + wy * max(time - t, 0.0);
        return sqrt(s(xp-X1) + s(yp-Y1)) <= vmax*time;
}

int main() {
    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> vmax >> t;
    cin >> vx >> vy >> wx >> wy;

    double lo = 0;
    double hi = 1e18;
    for(int i = 0; i < 100; ++i) {
        double mid = (lo+hi)/2;
        if(ok(mid)) hi = mid;
        else lo = mid;
    }
    cout << setprecision(15) << fixed;
    cout << lo << "\n";

    return 0;
}