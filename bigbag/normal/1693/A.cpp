/**
 *  created: 16/06/2022, 17:36:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int t, n, a[max_n];

bool ok() {
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            last = i;
        }
    }
    if (last == -1) {
        return true;
    }
    if (a[last] > 0) {
        return false;
    }
    long long x = abs(a[last]);
    for (int i = last - 1; i >= 0; --i) {
        long long y = x - a[i];
        if (!i) {
            return y == 0;
        }
        if (y <= 0) {
            return false;
        }
        x = y;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (ok()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}