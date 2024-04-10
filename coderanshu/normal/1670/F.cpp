#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


const int MOD=1000000007;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};

#define NCR
const int NC = 100005;
Mint fac[NC], fac_inv[NC], inv[NC];
void initncr() {
    fac[0] = fac_inv[0] = inv[1] = 1;
    for(int i=2;i<NC;++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i];
    }
    for(int i=1;i<NC;++i) {
        fac[i] = fac[i-1] * i;
        fac_inv[i] = fac_inv[i-1] * inv[i];
    }
}
Mint ncr(int n, int r) {
    if(n < r) {
        return 0;
    }
    return fac[n] * fac_inv[r] * fac_inv[n - r];
}


Mint dp[65][1000][2];

int n;
ll z;

Mint solve(ll r) {
    // cout << r << "\n";
    for(int i=0;i<62;++i) {
        for(int j=0;j<1000;++j) {
            for(int k=0;k<2;++k) {
                dp[i][j][k] = 0;
            }
        }
    }
    // 0 <= 
    // 1 > 
    if(r < 0) {
        return Mint(0);
    }
    dp[0][0][0] = 1;
    // cout << dp[1][0][0] << "\n";
    for(int i=0;i<60;++i) {
        for(int j=0;j<1000;++j) {
            for(int l=0;l<2;++l) {
                if(dp[i][j][l] == 0) {
                    continue;
                }
                // cerr << i << " " << j << " " << l << " " << dp[i][j][l] << "\n";
                for(int k=0;k<=n;k+=2) {
                    int cur = (j + k);
                    int bit = cur & 1;
                    int rem = cur / 2;
                    int take = k;
                    if(z & (1ll << i)) {
                        ++take;
                    }
                    // cerr << i << " " << j << " " << l << " " << dp[i][j][l] << "\n";
                    // cerr << bit << " " << rem << "\n";
                    if(bit == 0) {
                        if(r & (1ll << i)) {
                            dp[i + 1][rem][0] += dp[i][j][l] * ncr(n, take);
                        }
                        else {
                            dp[i + 1][rem][l] += dp[i][j][l] * ncr(n, take);
                        }
                    }
                    else {
                        if(r & (1ll << i)) {
                            dp[i + 1][rem][l] += dp[i][j][l] * ncr(n, take);
                        }
                        else {
                            dp[i + 1][rem][1] += dp[i][j][l] * ncr(n, take);
                        }
                    }
                }
            }
        }
    }
    return dp[60][0][0];
}

int _runtimeTerror_()
{
    ll l, r;
    cin >> n >> l >> r >> z;
    if(r < z) {
        cout << "0\n";
        return 0;
    }
    r -= z;
    Mint ans = solve(r);
    l -= z;
    if(l > 0) {
        ans -= solve(l - 1);
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}