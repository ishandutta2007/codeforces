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
#define debug(...) 3000
#endif


// const int MOD = 1000000007;
const int MOD = 998244353;

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


const int N = 17;

Mint pw[N][(1 << N) + 1];
Mint dp[N][(1 << N) + 1];

int pal[1005][1005], mask[1005][1005];
bool pos[1005][1005];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=0;i<17;++i) {
        pw[i][0] = 1;
        for(int j=1;j<=(1 << 17);++j) {
            pw[i][j] = pw[i][j-1] * (i + 1);
        }
    }
    string s;
    cin >> s;
    vector<int> psum(n + 1, 0);
    for(int i=1;i<=n;++i) {
        psum[i] = psum[i - 1] + (s[i - 1] == '?');
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=i;++j) {
            pos[i][j] = 1;
        }
    }
    for(int len=1;len<=n;++len) {
        for(int l=1;l+len-1<=n;++l) {
            int r = l + len - 1;
            if(len == 1) {
                pos[l][r] = 1;
                pal[l][r] = s[l - 1] == '?';
                mask[l][r] = 0;
            }
            else {
                if(s[l - 1] == '?' or s[r - 1] == '?') {
                    pos[l][r] = pos[l + 1][r - 1];
                    if(s[l - 1] == '?' and s[r - 1] == '?') {
                        mask[l][r] = mask[l + 1][r - 1];
                        pal[l][r] = pal[l + 1][r - 1] + 1;
                    }
                    else {
                        pal[l][r] = pal[l + 1][r - 1];
                        mask[l][r] = mask[l + 1][r - 1];
                        if(s[l - 1] != '?') {
                            mask[l][r] |= (1 << (s[l - 1] - 'a'));
                        }
                        if(s[r - 1] != '?') {
                            mask[l][r] |= (1 << (s[r - 1] - 'a'));
                        }
                    }

                }
                else if(s[l - 1] != s[r - 1]) {
                    pos[l][r] = 0;
                }
                else {
                    mask[l][r] = mask[l + 1][r - 1];
                    pos[l][r] = pos[l + 1][r - 1];
                    pal[l][r] = pal[l + 1][r - 1];
                }
            }
            if(pos[l][r]) {
                // debug(l,r,mask[l][r],pal[l][r]);
                for(int k=0;k<17;++k) {
                    dp[k][mask[l][r]] += pw[k][pal[l][r] + psum[n] - (psum[r] - psum[l - 1])];
                }
            }
        }
    }
    // for(int i=0;i<(1<<3);++i) {
        // cout << dp[0][i] << " ";
    // }
    // cout << "\n";
    for(int i=0;i<17;++i) {
        for(int j=0;j<17;++j) {
            for(int k=0;k<(1 << 17);++k) {
                if(k & (1 << j)) {
                    dp[i][k] += dp[i][k ^ (1 << j)];
                }
            }
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        string t;
        cin >> t;
        int m = 0;
        for(auto &i:t) {
            m |= (1 << (i - 'a'));
        }
        // debug(sz(t)-1,m);
        cout << dp[sz(t) - 1][m] << "\n";
    }
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