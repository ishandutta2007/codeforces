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

ll ans = 0;
const int N = 100005;

vector<int> v[N];
ll a[N];
ll mx[N],mn[N];

void dfs(int s,int p)
{
    ll mxm = 0,mnm = 0;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            amax(mxm,mx[j]);
            amin(mnm,mn[j]);
        }
    }
    a[s] += mxm+mnm;
    mx[s] = mxm;
    mn[s] = mnm;
    if(a[s]<0)
        mx[s] -= a[s];
    else
        mn[s] -= a[s];
    amax(ans,mx[s]-mn[s]);
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
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dfs(1,0);
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