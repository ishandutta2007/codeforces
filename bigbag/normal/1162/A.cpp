#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, h, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> h >> m;
    for (int i = 0; i < n; ++i) {
        a[i] = h;
    }
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        for (int j = l; j < r; ++j) {
            a[j] = min(a[j], x);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * a[i];
    }
    cout << ans << endl;
    return 0;
}