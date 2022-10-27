#include <bits/stdc++.h>
using namespace std;
 
const int P = 998244353;

inline void add(int &x, int y) {
    (x += y) >= P && (x -= P);
}
inline int Add(int x, int y) {
    return add(x, y), x;
}
inline void sub(int &x, int y) {
    (x -= y) < 0 && (x += P);
}
inline int Sub(int x, int y) {
    return sub(x, y), x;
}
inline void mul(int &x, int y) {
    x = 1ll * x * y % P;
}
inline int Mul(int x, int y) {
    return 1ll * x * y % P;
}
inline int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, mul(a, a)) {
        if (b & 1) {
            mul(res, a);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++zeros;
        }
    }

    int cnt = 0;
    for (int i = 0; i < zeros; ++i) {
        if (a[i] == 0) {
            ++cnt;
        }
    }

    int ans = 0;
    for (int i = cnt; i < zeros; ++i) {
        int x = 1ll * n * (n - 1) / 2 % P;
        int y = 1ll * (zeros - i) * (zeros - i) % P;
        add(ans, Mul(x, power(y, P - 2)));
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}