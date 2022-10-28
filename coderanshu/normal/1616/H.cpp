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

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif

    
const int MOD=MM;
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


int n, x;
Mint pw[1000000];
Mint ans = 0;

Mint dfs2(vector<int> &l, vector<int> &r, int bit) {
    if(l.empty() || r.empty()) {
        return 0;
    }
    if(bit == -1) {
        return (pw[sz(l)] - 1) * (pw[sz(r)] - 1);
    }
    vector<int> Lx, Rx, Ly, Ry;
    for(int i:l) {
        if(i & (1 << bit)) {
            Lx.push_back(i);
        }
        else {
            Rx.push_back(i);
        }
    }
    for(int i:r) {
        if(i & (1 << bit)) {
            Ly.push_back(i);
        }
        else {
            Ry.push_back(i);
        }
    }
    Mint val = 0;
    if(x & (1 << bit)) {
        Mint l = dfs2(Rx, Ly, bit - 1);
        Mint r = dfs2(Lx, Ry, bit - 1);

        val += (pw[sz(Rx)] - 1) * (pw[sz(Ry)] - 1);
        val += l * pw[sz(Ry)];
        val += (pw[sz(Lx)] - 1) * (pw[sz(Ly)] - 1);
        val += r * pw[sz(Ly)];
        val += l * r;
        val += l * (pw[sz(Lx)] - 1);
        val += r * (pw[sz(Rx)] - 1);
    }
    else {
        val += dfs2(Lx, Ly, bit - 1);
        val += dfs2(Rx, Ry, bit - 1);
    }
    return val;
}


void dfs1(vector<int> &a, int bit) {

    if(a.empty()) {
        return;
    }
    if(bit == -1) {
        ans += pw[sz(a)] - 1;
        return ;
    }
    vector<int> l, r;
    for(int i:a) {
        if(i & (1 << bit)) {
            l.push_back(i);
        }
        else {
            r.push_back(i);
        }
    }
    if(x & (1 << bit)) {    
        ans += pw[sz(l)] - 1;
        ans += pw[sz(r)] - 1;
        ans += dfs2(l, r, bit - 1);
        return ;
    }
    dfs1(l, bit - 1);
    dfs1(r, bit - 1);
}

int _runtimeTerror_()
{
    pw[0] = 1;
    for(int i=1;i<1e6;++i) {
        pw[i] = pw[i-1] * 2;
    }
    cin >> n >> x;  
    vector<int> a;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    dfs1(a, 29);
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
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}