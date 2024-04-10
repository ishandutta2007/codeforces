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


const int SZ = 1e6+10;
struct EERTREE {

    int len[SZ], link[SZ], slink[SZ], diff[SZ];
    char s[SZ];

    int last, sz, n;

    map<char, int> to[SZ];

    // Extra variables here to be stored in states of tree
    Mint sans[SZ];

    EERTREE() {
        len[1] = -1, link[1] = 0;
        len[0] = 0, link[0] = 1;
        last = 0;
        sz = 2;
        s[0] = -1;
        // to make sure that link works correctly if on adding ith char, i-1 th prefix is palindrome
        n = 1;
    }

    void addChar(char c) {
        s[n++] = c;
        while(s[n - 1] != s[n - 2 - len[last]]) {
            last = link[last];
        }
        if(!to[last].count(c)) {
            int tmp = link[last];
            while(s[n - 1] != s[n - 2 - len[tmp]]) {
                tmp = link[tmp];
            }
            // must have been present
            link[sz] = to[tmp][c];
            len[sz] = len[last] + 2;
            diff[sz] = len[sz] - len[link[sz]];
            if(diff[sz] == diff[link[sz]]) {
                slink[sz] = slink[link[sz]];
            }
            else {
                slink[sz] = link[sz];
            }
            to[last][c] = sz++;
        }   
        last = to[last][c];
        // do cnt[last]++ if need to count occurences
    }
}pt;

int _runtimeTerror_()
{
    string t;
    cin >> t;
    string s;
    for(int i=0;i<sz(t)/2;++i) {
        s += t[i];
        s += t[sz(t) - 1 - i];
    }
    int n = s.size();
    vector<Mint> ans(n+1, 0);
    ans[0] = 1;
    for(int i=1;i<=n;++i) {
        pt.addChar(s[i - 1]);

        for(int v=pt.last;pt.len[v]>0;v=pt.slink[v]) {
            pt.sans[v] = ans[i - (pt.len[pt.slink[v]] + pt.diff[v])];
            if(pt.diff[v] == pt.diff[pt.link[v]]) {
                pt.sans[v] += pt.sans[pt.link[v]];
            }
            ans[i] += pt.sans[v];
        }
        if(i & 1) {
            ans[i] = 0;
        }
    }
    cout << ans[n] << "\n";
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