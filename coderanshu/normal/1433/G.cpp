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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 1005;

int n,m,k;

vector<pll> v[N];

ll dis[N][2][N];

void djikstra(int x,int ix,int jx)
{
    set<pll> s;
    for(int i=0;i<=n;++i)
        dis[ix][jx][i] = INF;
    dis[ix][jx][x] = 0;
    s.insert({0,x});
    while(!s.empty())
    {
        auto u = *s.begin();
        s.erase(s.begin());
        for(auto &j:v[u.S])
        {
            if(dis[ix][jx][j.F] > dis[ix][jx][u.S] + j.S)
            {
                s.erase({dis[ix][jx][j.F],j.F});
                dis[ix][jx][j.F] = dis[ix][jx][u.S] + j.S;
                s.insert({dis[ix][jx][j.F],j.F});
            }
        }
    }
}

int _runtimeTerror_()
{
    cin>>n>>m>>k;
    vector<pii> ed;
    for(int i=1;i<=m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        ed.pb({x,y});
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    vector<pii> sp(k);
    for(int i=0;i<k;++i)
    {
        cin>>sp[i].F>>sp[i].S;
    }
    ll ans = 0;
    for(int i=0;i<k;++i)
    {
        djikstra(sp[i].F,i,0);
        ans += dis[i][0][sp[i].S];
        djikstra(sp[i].S,i,1);
    }
    // cout<<ans<<"\n";
    for(auto &j:ed)
    {
        ll val = 0;
        for(int i=0;i<k;++i)
        {
            ll u = dis[i][0][sp[i].S];
            amin(u,dis[i][0][j.F] + dis[i][1][j.S]);
            amin(u,dis[i][0][j.S] + dis[i][1][j.F]);
            val += u;
        }
        amin(ans,val);
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