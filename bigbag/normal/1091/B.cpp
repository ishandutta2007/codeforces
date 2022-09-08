#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, a[max_n], b[max_n];
pair<int, int> p[max_n], p2[max_n];

bool eq() {
    for (int i = 0; i < n; ++i) {
        if (p[i] != p2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        int x = p[0].first + a[i];
        int y = p[0].second + b[i];
        for (int j = 0; j < n; ++j) {
            p2[j] = {x - a[j], y - b[j]};
        }
        sort(p2, p2 + n);
        if (eq()) {
            cout << x << " " << y << "\n";
            return 0;
        }
    }
    return 0;
}