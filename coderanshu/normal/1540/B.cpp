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
#define debug(...) 2351
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



const int N = 205;

vector<int> v[N];

int in[N],out[N],dep[N],par[N][11];
int cur = 1;
void dfs(int s,int p)
{
    par[s][0] = p;
    for(int i=1;i<=10;++i)
        par[s][i] = par[par[s][i-1]][i-1];
    in[s] = cur++;  
    for(auto &j:v[s])
    {
        if(j!=p)
            dep[j] = dep[s] + 1,dfs(j,s);
    }
    out[s] = cur-1;
}

Mint dp[N][N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<=n;++i)
        dp[i][0] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i][j] = Mint(1)/2 * (dp[i-1][j] + dp[i][j-1]);
        }
    }
    auto lca = [&](int u,int v)
    {
        if(dep[v] < dep[u])
            swap(u,v);
        int d = dep[v] - dep[u];
        for(int i=0;i<10;++i)
            if(d&(1<<i))
                v = par[v][i];
        for(int i=9;i>=0;--i)
        {
            if(par[u][i] != par[v][i])
                v = par[v][i],u = par[u][i];
        }
        return par[u][0];
    };
    auto is_anc = [&](int x,int y)
    {
        return in[y] >= in[x] && in[y] <= out[x];
    };
    Mint ans = 0;
    for(int i=1;i<=n;++i)
    {
        cur = 1;
        dfs(i,0);
        for(int j=1;j<=n;++j)
        {
            for(int k=j+1;k<=n;++k)
            {
                if(is_anc(j,k))
                    continue;
                if(is_anc(k,j))
                    ans += Mint(1)/n;
                else
                {
                    int l = dep[lca(j,k)];
                    ans += Mint(1)/n * dp[dep[j] - l][dep[k] - l];
                }
            }
        }
    }
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