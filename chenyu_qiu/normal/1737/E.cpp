#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;
 
inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}
 
inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}
 
inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}
 
inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}
 
inline int mul(int x, int y) { return 1ull * x * y % md; }
 
inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int inv2 = (md + 1) / 2;

void solve() {
    int n;
    cin >> n;

    vector<int> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = mul(pw[i - 1], inv2);

    vector<int> dp(n + 2), sum(n + 2);
    dp[n] = sum[n] = 1;
    for (int i = n - 1; i; --i) {
        sum[i] = sum[i + 1];
        dp[i] = sub(sum[i], sum[min(n + 1, i * 2)]);
        addx(sum[i], dp[i]);
    }

    for (int i = 1; i <= n; ++i) {
        int res = (i > 1 && i < n) ? inv2 : 1;
        if (i > 1) {
            res = mul(res, pw[i - 1 - i / 2]);
        }
        res = mul(res, mul(dp[i], pw[n - i]));
        if (i < n) {
            res = mul(res, 2);
        }
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}