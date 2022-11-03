#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long x, y, p, q;

void Solve() {
    if (p == 0) {
        if (x != 0) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }
    if (p == q) {
        if (x != y) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }
    long long t1 = (y - x) / (q - p);
    if (t1 * (q - p) < y - x) {
        ++t1;
    }
    long long t2 = y / q;
    if (t2 * q < y) {
        ++t2;
    }
    long long t3 = x / p;
    if (t3 * p < x) {
        ++t3;
    }
    long long t = max(t1, max(t2, t3));
    long long dy = t * q - y;
    cout << dy << endl;
}

bool Read() {
    if (!(cin >> x >> y >> p >> q)) {
        return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (Read()) {
        Solve();
    }

    return 0;
}