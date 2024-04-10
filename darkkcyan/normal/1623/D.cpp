#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// I swear that I type this everytime, so this is not count as template :))
#define defop(type, op) \
    inline friend type operator op (type u, const type& v) { return u op ##= v; } \
    type& operator op##=(const type& o)
template<int mod>
struct modint {
    int x;
    // note that there is no correction, simply for speed
    modint(int xx = 0): x(xx) {}
    modint(ll xx): x(int(xx % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, * ) { return *this = modint(1ll * x * o.x); }
    modint pow(ll exp) const {
        modint ans = 1, base = *this;
        for (; exp > 0; exp >>= 1, base *= base)
            if (exp & 1) ans *= base;
        return ans;
    }
    defop(modint, /) { return *this *= o.pow(mod - 2); }
};
using mint = modint<(int)1e9 + 7>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m, rb, cb, rd, cd;
        mint p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p.x;
        p = 1 - p / 100;  // probability of not cleaning
        int dr = -1, dc = -1;
        mint u = 0, v = 1;
        for (int i = 0; i < 4 * (n - 1) * (m - 1); ++i) {
            if (!(1 <= rb + dr and rb + dr <= n)) dr = -dr;
            if (!(1 <= cb + dc and cb + dc <= m)) dc = -dc;
            rb += dr;
            cb += dc;
            u += 1;
            if (rb == rd or cb == cd) {
                u *= p;
                v *= p;
            }
        }
        cout << (u / (1 - v)).x << '\n';
    }
    
    return 0;
}