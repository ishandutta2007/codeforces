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

int fac[200005], ifac[200005];
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = Mul(fac[i - 1], i);
    ifac[n] = power(fac[n], P - 2);
    for (int i = n; i; --i) ifac[i - 1] = Mul(ifac[i], i);
}
int binom(int n, int m) {
    return Mul(fac[n], Mul(ifac[m], ifac[n - m]));
}
int ibinom(int n, int m) {
    return Mul(ifac[n], Mul(fac[m], fac[n - m]));
}

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> suf(n + 2), pre(n + 2);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i; --i) {
        suf[i] = suf[i + 1] + a[i];
    }

    int ans = 1;
    map<ll, int> left, right;
    for (int i = 1; i <= n; ++i) {
        ++right[suf[i]];
    }

    auto C = [&](ll x) {
        return binom(left[x] + right[x], left[x]);
    };
    auto iC = [&](ll x) {
        return ibinom(left[x] + right[x], left[x]);
    };

    int coef = 1;
    for (int i = 1; i <= n; ++i) {
        mul(coef, iC(suf[i]));
        --right[suf[i]];
        mul(coef, C(suf[i]));
        sub(ans, coef);
        mul(coef, iC(pre[i]));
        ++left[pre[i]];
        mul(coef, C(pre[i]));
        add(ans, coef);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(200000);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}