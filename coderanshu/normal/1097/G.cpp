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
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

    
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

const int N = 100005;

Mint dp[N][201],dp2[N][201];
int sub[N];
vector<int> v[N];
int k;
Mint ans[201];
Mint S[201][201];
Mint pow_2[N];
int n;

void dfs(int s,int p)
{
    sub[s] = 1;
    dp[s][0] = 1;   
    vector<Mint> t(k+1);
    for(int j:v[s])
    {
        if(j == p)
            continue;
        dfs(j,s);
        for(int i=0;i<=k;++i)
            t[i] = 0;
        for(int i=min(sub[s],k);i>=0;--i)
        {
            for(int l=0;l<=min(sub[j],k) && i+l<=k;++l)
            {
                t[i+l] += dp[s][i]*dp[j][l];
                if(i+l+1<=k)
                    t[i+l+1] += dp[s][i]*(dp[j][l] - (l==0));
            }
        }
        sub[s] += sub[j];
        for(int i=0;i<=min(sub[s],k);++i)
            dp[s][i] = t[i];
    }
    for(int i=0;i<=min(sub[s],k);++i)
    {
        dp2[s][i] = dp[s][i];
        dp[s][i] *= 2;
    }
    for(int j:v[s])
    {
        if(j!=p)
        {
            for(int i=1;i<=min(sub[j],k);++i)
            {
                dp2[s][i] -= dp[j][i]*pow_2[sub[s]-1-sub[j]];
                ans[i] += (dp[j][i-1] - (i==1))*(pow_2[n-sub[j]]-1);
                dp2[s][i] -= (dp[j][i-1] - (i==1))*pow_2[sub[s]-1-sub[j]];
            }
        }
    }
    for(int i=1;i<=min(sub[s],k);++i)
    {
        ans[i] += dp2[s][i] * pow_2[n-sub[s]+1];
    }
}

int _runtimeTerror_()
{
    cin>>n>>k;    
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    pow_2[0] = 1;
    for(int i=1;i<=n;++i)
        pow_2[i] = pow_2[i-1]*2;
    dfs(1,0);
    S[0][0] = 1;
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=i;++j)
        {
            S[i][j] = j*(S[i-1][j-1] + S[i-1][j]);
        }
    }
    Mint A = 0;
    for(int i=1;i<=k;++i)
    {
        A += ans[i]*S[k][i];
    }
    cout<<A<<"\n";
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
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}