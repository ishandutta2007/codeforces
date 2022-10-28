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


template<typename T>
struct Gauss
{
    vector<vector<T>> v;
    vector<T> ans;
    // n -> number of variables
    // m-> number of equations
    int n,m;
    Gauss(int n,int m)
    {
        this->n = n;
        this->m = m;
        v.resize(m);
        for(auto &j:v)
            j.resize(n+1);
    }
    bool solve()
    {
        ans.resize(n);
        vector<int> where(n,-1);
        int row = 0;
        for(int i=0;i<n;++i)
        {
            if(row == m)
                continue;
            int r;
            for(r = row;r<m;++r)
                if(v[r][i] != 0)
                    break;
            if(r == m)
                continue;
            where[i] = row;
            swap(v[row],v[r]);
            for(int r=row+1;r<m;++r)
            {
                if(v[r][i] != 0)
                {
                    T u = v[r][i]/v[row][i];
                    for(int j=i;j<n+1;++j)
                        v[r][j] -= v[row][j]*u;
                }
            }
            ++row;
        }
        for(int x=row;x<m;++x)
        {
            if(v[x][n] != 0)
                return false;
        }
        for(int i=n-1;i>=0;--i)
        {
            if(where[i] == -1)
            {
                // free variable
            }
            T x = v[where[i]][n];
            for(int j=i+1;j<n;++j)
                x -= v[where[i]][j]*ans[j];
            x /= v[where[i]][i];
            ans[i] = x;
        }
        return true;
    }
};
// Gauss<double> g(n,m);

const int N = 100005;

vector<int> v[N];
int cnt[N];
int mx = -1;
bool vis[N];
int dp[N];

void dfs(int s)
{
    vis[s] = true;
    set<int> q;
    for(auto j:v[s])
    {
        if(!vis[j])
            dfs(j);
        q.insert(dp[j]);
    }
    for(int i=0;;++i)
    {
        if(!q.count(i))
        {
            dp[s] = i;
            break;
        }
    }
    ++cnt[dp[s]];
    amax(mx,dp[s]);
}



int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
            dfs(i);
    }
    mx <<= 1;
    Gauss<Mint> g(mx+1,mx+1);
    Mint f = Mint(n+1).inv();
    for(int i=0;i<=mx;++i)
    {
        if(i)
            g.v[i][mx+1] -= f;
        g.v[i][i] = -1;
        for(int j=0;j<=mx;++j)
        {
            g.v[i][j] += f*cnt[j^i];
        }
    }
    g.solve();
    cout<<g.ans[0]<<"\n";
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