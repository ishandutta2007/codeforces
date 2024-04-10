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

const int N = 405;

    
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

ll dis[N][N];
vector<int> v[N];

Mint ans[N][N];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dis[i][j] = INF;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    auto bfs = [&](int u)
    {
        dis[u][u] = 0;
        vector<int> q;
        q.push_back(u);
        for(int i=0;i<q.size();++i)
        {
            for(auto j:v[q[i]])
            {
                if(dis[u][j] > dis[u][q[i]] + 1)
                {
                    dis[u][j] = dis[u][q[i]] + 1;
                    q.push_back(j);
                }
            }
        }
    };
    for(int i=1;i<=n;++i)
    {
        bfs(i);
    }   
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            int ccc = 0;
            bool upd = true;
            int fx = dis[i][j];
            for(auto &k:cnt)
                k = 0;
            Mint ff = 1;
            for(int k=1;k<=n;++k)
            {
                if(dis[i][k] + dis[k][j] == fx)
                {
                    if(cnt[dis[i][k]] > 0)
                    {
                        upd = false;
                        break;
                    }
                    ++cnt[dis[i][k]];
                }
                else
                {
                    if(dis[i][k] != dis[k][j] + fx && dis[i][k] + fx != dis[j][k])
                    {
                        Mint fo = 0;
                        for(auto &l:v[k])
                            fo += dis[i][l] + 1 == dis[i][k] && dis[l][j] + 1 == dis[j][k];
                        ff *= fo;
                    }
                    else if(dis[i][k] != dis[k][j] + fx)
                    {
                        Mint fo = 0;
                        for(auto &l:v[k])
                            fo += dis[i][l] + 1 == dis[i][k];
                        ff *= fo;
                    }
                    else
                    {
                        Mint fo = 0;
                        for(auto &l:v[k])
                            fo += dis[j][l] + 1 == dis[j][k];
                        ff *= fo;
                    }
                }
                if(!upd)
                    break;
            }
            if(!upd)
                continue;
            ans[i][j] += ff;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j)
            ans[i][j] = ans[j][i];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
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
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}