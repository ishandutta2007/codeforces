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

const int N = 5002;

Mint dp[N][N];

vector<int> v[N];

int n,k;
int dep[N],mxdep[N];

// dp[i][j] -> vertex i and max chain j

void dfs(int s,int p)
{
    vector<Mint> tmp,tt;
    Mint val = 1;
    Mint tsum = 1;
    vector<Mint> pro(k+1,1);
    mxdep[s] = dep[s];
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            dfs(j,s);
            Mint sum = 0;
            amax(mxdep[s],mxdep[j]);
            for(int i=0;i<=k;++i)
            {
                sum += dp[j][i];
            }
            tsum *= sum;
            tmp.push_back(sum);
            sum = 0;
            for(int i=0;i<=k;++i)
            {
                sum += dp[j][i];
                pro[i] *= tmp.back()+sum;
            }
        }
    }
    int d = mxdep[s] - dep[s];
    // cout<<s<<" "<<d<<"\n";
    // if(s == 1)
    // {
    //     for(auto &j:pro)
    //         cout<<j<<" ";
    //     cout<<"\n";
    // }
    // sabko uda dia
    dp[s][0] += tsum;
    for(int i=1;i<=min(k/2,d);++i)
    {
        dp[s][i] += pro[i-1] - (i-1>0?pro[i-2]:tsum);
    }
    int cur = 0;
    for(auto j:v[s])
    {
        if(j==p)
            continue;
        vector<Mint> x(min(k,d)+1);
        Mint sum = 0;
        for(int i=0;i<=min(k,d);++i)
        {
            sum += dp[j][i];
            x[i] = tmp[cur]+sum;
        }
        for(int i=k/2+1;i<=k && i<=d;++i)
        {
            int up = k-i-1;
            if(up < 0)
                dp[s][i] += dp[j][i-1] * (tsum / tmp[cur]);
            else
            {
                dp[s][i] += dp[j][i-1] * pro[up] / x[up];
            }
        }
        ++cur;
    }
}

int _runtimeTerror_()
{
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    if(k == 0)
    {
        cout<<"1\n";return 0;
    }
    dfs(1,0);
    // for(int i=1;i<=n;++i)
    // {
    //     cout<<"v : "<<i<<"\n";
    //     for(int j=0;j<=k;++j)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<dp[1][0]<<"\n";
    Mint ans = 0;
    for(int i=0;i<=k;++i)
        ans += dp[1][i];
    cout<<ans<<"\n";
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