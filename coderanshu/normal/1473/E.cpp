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

vector<pll> v[N];

ll dis[N][4];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<4;++j)
            dis[i][j] = INF;
    }
    dis[1][0] = 0;
    set<pair<ll,pll>> s;
    s.insert({0,{1,0}});
    while(!s.empty())
    {
        auto [x,y] = *s.begin();
        s.erase(s.begin());
        // y.F vertex
        for(auto [j,k]:v[y.F])
        {
            // normal use
            if(x+k<dis[j][y.S])
            {
                s.erase({dis[j][y.S],{j,y.S}});
                dis[j][y.S] = x+k;
                s.insert({dis[j][y.S],{j,y.S}});
            }
            if(y.S%2==0)
            {
                if(x<dis[j][y.S^1])
                {
                    s.erase({dis[j][y.S^1],{j,y.S^1}});
                    dis[j][y.S^1] = x;
                    s.insert({dis[j][y.S^1],{j,y.S^1}});   
                }
            }
            if((y.S&2)==0)
            {
                if(x+2*k<dis[j][y.S^2])
                {
                    s.erase({dis[j][y.S^2],{j,y.S^2}});
                    dis[j][y.S^2] = x+2*k;
                    s.insert({dis[j][y.S^2],{j,y.S^2}});   
                }
            }
        }
    }
    // cout<<dis[2][2]<<"\n";
    for(int i=2;i<=n;++i)
    {
        cout<<min(dis[i][0],dis[i][3])<<" ";
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