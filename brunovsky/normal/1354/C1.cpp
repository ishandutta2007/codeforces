#include <bits/stdc++.h>
#define pi 3.14159265358979323846264338327950288

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    double phi = pi / N;

    if (N % 2 == 1) {
        double alpha = phi / 4;
        double side = sqrt(2 * (1 - cos(phi)));
        return 2 * cos(alpha) / side;
    } else {
        return 1.0 / tan(phi / 2);
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cout << setprecision(10) << fixed;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}