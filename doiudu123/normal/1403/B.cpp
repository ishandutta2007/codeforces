#include <bits/stdc++.h>
using namespace std;
const int N = 400001, mod = 998244353;
#define lli long long int

lli fac[N], facp[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

void build() {
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod, facp[i] = modpow(fac[i], mod - 2);
}

lli C(int n, int m) {
    return fac[n] * facp[n - m] % mod * facp[m] % mod;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int now = 0, a = 0, b = 0, del = 0;
    bool is = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') now++;
        else {
            if (is) {
                if (now & 1) now--, del++;
            }
            while (now >= 2) now -= 2, a++;
            if (now == 1) now--, b++;
            is = false;
        }
    }
    if (now & 1) now--, del++;
    while (now >= 2) now -= 2, a++;
    if (now == 1) b++;
    n -= del;
    cout << C(n - a - b, a) << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}