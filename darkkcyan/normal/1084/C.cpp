#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define defop(type, op) \
    inline friend type operator op(type u, const type& v) { return u op ##= v; } \
    type& operator op ##= (const type& o)

template<int mod> 
struct modint {
    int x;
    modint(int x_ = 0): x(x_) {}
    modint(ll x_): x((int)(x_ % mod)) {}
    defop(modint, +) {
        if ((x += o.x) >= mod) x-= mod;
        return *this;
    }
    defop(modint, -) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }
    defop(modint, *) {
        return *this = modint(1ll * x * o.x);
    }
};

using mint = modint<(int)1e9 + 7>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s;
    cin >> s;
    vector<mint> dp(s.size() + 1);
    mint sum_dp = 1;
    int f = 0; 
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'a') dp[i] = sum_dp;
        else if (s[i] == 'b') {
            while (f < i) sum_dp += dp[f++];
        }
    }
    while (f < (int)s.size()) sum_dp += dp[f++];
    cout << (sum_dp - 1).x;
    
    return 0;
}