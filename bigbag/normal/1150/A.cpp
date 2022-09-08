#include <bits/stdc++.h>

using namespace std;

const int max_n = 33, inf = 1000111222;

int n, m, r, x = inf, y = -inf, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        x = min(x, c);
    }
    for (int i = 0; i < m; ++i) {
        cin >> c;
        y = max(y, c);
    }
    cout << max(r, r / x * y + r % x) << endl;
    return 0;
}