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


bool can(vector<int> &msk,int x)
{
    for(int i=0;i<5;++i)
    {
        if((x&(1<<i)) == 0)
            continue;
        if(!msk[i])
        {
            msk[i] = x;
            return true;
        }
        x ^= msk[i];
    }
    return false;
}

void reduce(vector<int> &v)
{
    for(int i=0;i<5;++i)
    {
        int u = v[i];
        for(int j=i+1;j<5;++j)
        {
            if(u&(1<<j))
                u ^= v[j];
        }
        v[i] = u;
    }
}
vector<vector<int>> ans;

void go(ll mask,int pos,vector<int> msk)
{
    if(pos == 32)
        return ;

    go(mask,pos+1,msk);
    if(can(msk,pos))
    {
        mask |= (1LL<<pos);
        reduce(msk);
        ans.pb(msk);
        go(mask,pos+1,msk);
    }
}

map<vector<int>,int> id;
int sum[375][375];
const int N = 100005;
vector<pii> v[N];

Mint dp[N][375];

bool co1[N];
int root[N];
int pxor[N],par[N];
bool no[N];
bool vis[N];

void setRoot(int s,int p,int r,int val)
{
    root[s] = r;
    vis[s] = true;
    pxor[s] = val;
    par[s] = p;
    for(auto [j,k]:v[s])
    {
        if(j!=p && !co1[j] && !vis[j])
        {
            setRoot(j,s,r,val^k);
        }
    }
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<pair<pii,int>> edges;
    vis[1] = true;
    for(int i=1;i<=m;++i)
    {   
        int x,y,w;
        cin>>x>>y>>w;
        edges.pb({{x,y},w});
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    for(auto j:v[1])
        co1[j.F] = true;
    for(auto j:v[1])
        setRoot(j.F,0,j.F,0);
    vector<vector<int>> b(n+1,vector<int>(5,0));
    auto add = [&](int r,vector<int> &b,int x)
    {
        for(int j=0;j<5;++j)
        {
            if((x&(1<<j)) == 0)
                continue;
            if(!b[j])
            {
                b[j] = x;
                return ;
            }
            x ^= b[j];
        }
        no[r] = true;
    };    
    for(auto& [j,k]:edges)
    {
        if(par[j.F] == j.S || par[j.S] == j.F || (co1[j.F] && co1[j.S]) || j.F==1 || j.S==1)
            continue;
        add(root[j.F],b[root[j.F]],pxor[j.F]^pxor[j.S]^k);
    }
    vector<int> upar(n+1,0);
    for(auto j:v[1])
    {
        reduce(b[j.F]);
        upar[j.F] = j.S;
    }
    dp[0][0] = 1;
    vector<bool> done(n+1,false);
    for(int i=1;i<=sz(v[1]);++i)
    {
        if(done[v[1][i-1].F])
        {
            for(int j=0;j<374;++j)
                dp[i][j] = dp[i-1][j];
            continue;
        }
        auto [x,y] = v[1][i-1];
        int have = -1,w = -1;
        for(auto &j:v[x])
            if(co1[j.F])
                have = j.F,w =j.S;
        if(have == -1)
        {
            int idx = id[b[x]];
            for(int j=0;j<374;++j)
            {
                if(no[x] || sum[idx][j] == -1)
                    dp[i][j] += dp[i-1][j];
                else
                {
                    dp[i][sum[idx][j]] += dp[i-1][j];
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        else
        {
            done[have] = true;
            vector<int> tsum(5,0);
            int weight = y^w^upar[have];
            if(weight)
                tsum[int(log2(weight&-weight))] = weight;
            reduce(tsum);
            int th = id[tsum];
            int id1 = id[b[x]],id2 = id[b[have]];
            for(int j=0;j<374;++j)
            {
                dp[i][j] += dp[i-1][j];
                int fx = sum[id1][id2];
                if(!no[have] && !no[x] && fx!=-1 && sum[fx][j]!=-1)
                {
                    dp[i][sum[fx][j]] += 2*dp[i-1][j];
                }
                if(!no[x] && !no[have] && sum[id1][id2] != -1 && sum[sum[id1][id2]][j]!=-1 && weight)
                {
                    int ux = sum[j][sum[id1][id2]];
                    if(sum[ux][th]!=-1)
                        dp[i][sum[ux][th]] += dp[i-1][j];
                }
            }

        }
    }
    Mint ans = 0;
    for(int i=0;i<374;++i)
        ans += dp[sz(v[1])][i];
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
    vector<int> x(5,0);
    go(0,1,x);
    ans.pb({0,0,0,0,0});
    sort(all(ans));
    ans.resize(unique(all(ans))-ans.begin());
    for(int i=0;i<sz(ans);++i)
        id[ans[i]] = i;
    auto add = [&](vector<int> a,vector<int> b)
    {
        for(auto &j:a)
        {
            if(j == 0)
                continue;
            bool depen = true;
            for(int i=0;i<5;++i)
            {
                if((j&(1<<i)) == 0)
                    continue;
                if(!b[i])
                    b[i] = j,depen = false;
                j ^= b[i];
            }
            if(depen)
                return -1;
        }
        reduce(b);
        return id[b];
    };
    for(int i=0;i<sz(ans);++i)
    {
        for(int j=0;j<sz(ans);++j)
        {
            sum[i][j] = add(ans[i],ans[j]);
        }
    }
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}

// bc insane 4hrs code ..........