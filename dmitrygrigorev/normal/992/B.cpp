#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x != 0){
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    int n = y / x;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            int c = n / d;
            if (l <= c * x && c * x <= r && l <= d * x && d * x <= r && gcd(c, d) == 1) {
                if (d * d == n) ++ans;
                else ans += 2;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}