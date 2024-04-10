#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int n, t, k, d;

int GetSoloTime() {
    int epoches = (n / k) + (n % k != 0);
    return epoches * t;
}

int GetBothTime() {
    const int MAX_TIME = 1e6;
    for (int c = d; c <= MAX_TIME; ++c) {
        int v = (c / t) * k;
        v += ((c - d) / t) * k;
        if (v >= n) {
            return c;
        }
    }
    assert(false);
}

void Solve() {
    if (GetSoloTime() <= GetBothTime()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

bool Read() {
    if (!(cin >> n >> t >> k >> d)) {
        return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}