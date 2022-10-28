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

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}

const int N = 5005;

ll x[N],y[N];
int n;

void go_(pll u,vector<bool> &vis,vector<int> &ans)
{
    ll dis = -1,v=-1;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            ll d = (x[i]-u.F)*(x[i]-u.F) + (y[i]-u.S)*(y[i]-u.S);
            if(d>dis)
                dis = d,v = i;
        }
    }
    if(v == -1)
        return ;
    ans.pb(v);
    vis[v] = true;
    go_({x[v],y[v]},vis,ans);
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i];
    }
    bool pos = false;
    // 1 -> 2
    ll u = x[1]-x[2],v = y[1]-y[2];
    ll dis = -1;
    pll ans;
    for(int i=3;i<=n;++i)
    {
        ll xx = x[i]-x[2],yy = y[i]-y[2];
        if(xx*u+yy*v>0)
        {
            pos = true;
            ll d = xx*xx+yy*yy;
            if(d>dis)
            {
                dis = d;
                ans.F = x[i],ans.S = y[i];
            }
        }
    }
    vector<int> p{1,2};
    vector<bool> done(n+1,false);
    done[1] = done[2] = true;
    for(int i=3;i<=n;++i)
    {
        if(ans.F == x[i] && ans.S == y[i])
        {
            done[i] = true;
            p.pb(i);
        }
    }
    if(pos)
    {
        go_(ans,done,p);
    }
    else
    {   
        p.clear();
        for(int i=3;i<=n;++i)
            done[i] = false;
        p.pb(2);
        p.pb(1);
        go_({x[1],y[1]},done,p);
    }
    assert(sz(p) == n);
    for(auto j:p)
        cout<<j<<" ";
    cout<<"\n";
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