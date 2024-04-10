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

const int N = 200005;

vector<int> v[N];
int sub[N],chain[N],tail[N],dep[N],par[N][20];
int heavy[N];

void dfs_sz(int s=1,int p=0)
{
    par[s][0] = p;
    for(int i=1;i<20;++i)
        par[s][i] = par[par[s][i-1]][i-1];
    sub[s] = 1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            dfs_sz(j,s);
            sub[s] += sub[j];
        }
    }
}
int cur = 1;
void dfs(int s,int p)
{
    chain[s] = cur;
    tail[cur] = s;
    int mx = -1;
    heavy[s] = -1;
    for(auto j:v[s])
    {
        if(j!=p && sub[j]>mx)
            mx = sub[j],heavy[s] = j;
    }
    if(heavy[s]!=-1)
        dfs(heavy[s],s);
    for(auto j:v[s])
        if(j!=p && j!=heavy[s])
            ++cur,dfs(j,s);
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs_sz();
    dfs(1,0);
    int h = -1;
    cout<<"d 1\n"<<flush;
    cin>>h;
    if(h==0)
    {
        cout<<"! 1\n"<<flush;return 0;
    }
    auto kth = [&](int u,int k)
    {
        for(int i=0;i<20;++i)
            if(k&(1<<i))
                u = par[u][i];
        return u;
    };
    int cur = 1;
    while(true)
    {
        int v = tail[chain[cur]];
        cout<<"d "<<v<<"\n"<<flush;
        int d;
        cin>>d;
        int x = (dep[v]+h-d)/2;
        int ver = kth(v,dep[v]-x);
        if(dep[ver]==h)
        {
            cout<<"! "<<ver<<"\n"<<flush;
            return 0;
        }
        cout<<"s "<<ver<<"\n"<<flush;
        cin>>d;
        cur = d;
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