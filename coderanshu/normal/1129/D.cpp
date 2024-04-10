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

    
const int MOD=998244353;
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

const int B = 450;

Mint psum[B+1][2*B+10];
int sum[B+1];

int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), b(n+1, 0);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<Mint> dp(n+1);
    dp[0] = 1;
    map<int,vector<int>> occs;
    auto upd = [&](int id, int val) {
        int bid = (id - 1) / B;
        sum[bid] = 0;
        for(int j=0;j<=2*B;++j) {
            psum[bid][j] = 0;
        }
        b[id] = val;
        for(int j=min((bid+1)*B,n);j>=bid*B+1;--j) {
            sum[bid] += b[j];
            psum[bid][sum[bid]+B] += dp[j-1];
        }
        for(int j=1;j<=2*B;++j) {
            psum[bid][j] += psum[bid][j-1];
        }
    };
    auto query = [&](int r) {   
        int cnt = 0;
        Mint ans = 0;
        while(r % B) {
            cnt += b[r];
            if(cnt <= k) {
                ans += dp[r-1];
            }
            --r;
        }
        while(r > 0) {
            int want = k - cnt + B;
            r -= B;
            cnt += sum[r/B];
            if(want < 0) {
                continue;
            }
            ans += psum[r/B][min(want,2*B)];
        }
        return ans;
    };
    for(int i=1;i<=n;++i) {
        if(occs[a[i]].size() >= 2) {
            upd(occs[a[i]][sz(occs[a[i]])-2], 0);
        }
        if(occs[a[i]].size() >= 1) {
            upd(occs[a[i]].back(), -1);
        }
        upd(i, 1);
        occs[a[i]].push_back(i);
        dp[i] = query(i);
    }
    cout << dp[n] << "\n";
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