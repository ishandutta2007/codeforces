// Har Har Mahadev
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


const int N = 305;

vector<int> v[N];


vector<Mint> dp[N],dp2[N];
int sub[N];
int R;

void dfs_sz(int s,int p)
{
    sub[s] = 1;
    for(auto j:v[s])
        if(j!=p)
            dfs_sz(j,s),sub[s] += sub[j];
}

void dfs(int s,int p)
{
    for(auto j:v[s])
    {
        if(j == p)
            continue;
        dfs(j,s);
    }
    dp[s].assign(1,1);
    dp2[s].assign(1,1);
    int cur = 1;
    for(int j:v[s])
    {
        if(j == p)
            continue;
        int sz = max(cur,sub[j]+1);
        vector<Mint> dpp(sz),dpp2(sz);
        for(int i=0;i<sz(dp[s]);++i)
        {
            for(int k=0;k<sz(dp[j]);++k)
            {
                dpp[min(i,k+1)] += dp[s][i] * dp[j][k];
            }
        }
        for(int i=0;i<sz(dp[s]);++i)
        {
            for(int k=0;k<sz(dp2[j]);++k)
            {
                if(i+k+1 <= R)
                {
                    dpp[i] += dp[s][i] * dp2[j][k];
                }
                else
                {
                    dpp2[k+1] += dp[s][i] * dp2[j][k];
                }
            }
        }
        for(int i=0;i<sz(dp2[s]);++i)
        {
            for(int k=0;k<sz(dp[j]);++k)
            {
                if(i+k+1 <= R)
                    dpp[k+1] += dp2[s][i] * dp[j][k];
                else
                    dpp2[i] += dp2[s][i] * dp[j][k];
            }
        }
        for(int i=0;i<sz(dp2[s]);++i)
        {
            for(int k=0;k<sz(dp2[j]);++k)
            {
                dpp2[max(i,k+1)] += dp2[s][i] * dp2[j][k];
            }
        }
        cur += sub[j];
        swap(dp[s],dpp);
        swap(dp2[s],dpp2);
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs_sz(1,0);
    vector<Mint> ans(n+1,0);
    for(R = 1;R <= n;++R)
    {
        dfs(1,0);
        for(Mint j:dp[1])
            ans[R-1] += j;
    }
    Mint val = 0;
    val += n-1;
    for(int i=1;i<n;++i)
        val += i * (ans[i] - ans[i-1]);
    val /= Mint(2).power(n);
    cout<<val<<"\n";
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