#include <bits/stdc++.h>

using namespace std;
using Point = complex<long long>;

int main() {
    int n; long long m; cin >> n >> m;
    m %= 2 * n;
    
    long long x, y; cin >> x >> y;
    Point now{x, y};

    vector<Point> P;
    for (int i = 0; i < n; ++i) {
        long long x, y; cin >> x >> y;
        P.emplace_back(x, y);
    }

    for (int i = 0; i < m; ++i) {
        now = P[i % n] * 2LL - now;
    }
    cout << now.real() << " " << now.imag() << endl;

    return 0;
}