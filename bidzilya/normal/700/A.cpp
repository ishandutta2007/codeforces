#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ITR = 100;

bool Check(int n, double l, double v1, double v2, int k, double t) {
    if (t > l / v1) {
        return true;
    }

    double tmin = (l - v1 * t) / (v2 - v1);

    double curPos = 0.0;

    while (n > 0) {
        int c = min(n, k);
        n -= c;

        double ct = (l - curPos) / v2;

        if (ct > tmin) {
            double autoPos = curPos + tmin * v2;
            curPos += tmin * v1;

            double tadd = (autoPos - curPos) / (v1 + v2);

            curPos += tadd * v1;
        } else {
            return false;
        }

        if (curPos > l) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    double tl = 0.0;
    double tr = 1.0 * l / v1 + 100.0;
    for (int itr = 0; itr < MAX_ITR; ++itr) {
        double tm = (tl + tr) / 2.0;

        if (Check(n, l, v1, v2, k, tm)) {
            tr = tm;
        } else {
            tl = tm;
        }
    }

    cout << fixed << setprecision(15) << tl << endl;

    return 0;
}