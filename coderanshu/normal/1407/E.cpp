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

const int N = 500005;

ll dis[N][2];
vector<int> v[N][2];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    string ans(n+1,'0');
    for(int i=1;i<=m;++i)
    {
        int x,y,t;
        cin>>x>>y>>t;
        v[y][t].push_back(x);
    }
    for(int i=1;i<=n-1;++i)
        dis[i][0] = dis[i][1] = INF;
    vector<int> q;
    q.push_back(n);
    for(int i=0;i<sz(q);++i)
    {
        int u = q[i];
        for(int j=0;j<2;++j)
        {
            for(int &k:v[u][j])
            {
                ll already = max(dis[k][0],dis[k][1]);
                amin(dis[k][j],max(dis[u][0],dis[u][1])+1);
                if(already > max(dis[k][j],dis[k][j^1]))
                {
                    q.push_back(k);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        ans[i] = dis[i][0] > dis[i][1]?'0':'1';

    cout<<(max(dis[1][0],dis[1][1]) == INF?-1:max(dis[1][0],dis[1][1]))<<"\n";
    ans.erase(ans.begin());
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