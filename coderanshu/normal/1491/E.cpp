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

set<int> v[N];

vector<int> fib{1,1};
int sub[N],par[N];

void dfs_sz(int s,int p)
{
    sub[s] = 1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs_sz(j,s);
            sub[s] += sub[j];
            par[j] = s;
        }
    }
}

pii dfs2(int s,int p,int f)
{
    if(sub[s] == fib[f-1])
        return {s,par[s]};
    if(sub[s] == fib[f-2])
        return {par[s],s};
    for(auto j:v[s])
    {
        if(j!=p)
        {
            auto x = dfs2(j,s,f);
            if(x.F != -1)
                return x;
        }
    }
    return {-1,-1};
}

bool dfs(int s,int f)
{
    if(f < 0)
        return false;
    if(fib[f] == 1)
        return true;
    dfs_sz(s,0);
    pii aux = dfs2(s,0,f);
    if(aux.F == -1)
        return false;
    v[aux.F].erase(aux.S);
    v[aux.S].erase(aux.F);
    return dfs(aux.F,f-1) && dfs(aux.S,f-2);
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    while(fib.back() < 10*n)
    {
        fib.push_back(fib[sz(fib)-1] + fib[sz(fib)-2]);
    }
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].insert(y),v[y].insert(x);
    }
    int x = -1;
    for(int i=0;i<sz(fib);++i)
    {
        if(fib[i] == n)
            x = i;
    }
    bool ans = dfs(1,x);
    cout<<(ans?"YES":"NO")<<"\n";
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