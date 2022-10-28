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

const int N = 2005;

ll one[N][N],nn[N][N];

ll a[N][N];

int _runtimeTerror_()
{
    int n,m,w;

    vector<int> dx{1,-1,0,0},dy{0,0,1,-1};
    auto valid = [&](int x,int y)
    {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    cin>>n>>m>>w;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            one[i][j] = nn[i][j] = INF;
        }
    }
    one[1][1] = nn[n][m] = 0;
    vector<pii> q;
    q.push_back({1,1});
    for(int i=0;i<sz(q);++i)
    {
        auto [x,y] = q[i];
        for(int j=0;j<4;++j)
        {
            int u = x + dx[j],v = y + dy[j];
            if(valid(x+dx[j],y+dy[j]) && one[x+dx[j]][y+dy[j]] > one[x][y] + w && a[u][v] != -1)
            {
                one[x+dx[j]][y+dy[j]] = one[x][y] + w;
                q.push_back({x+dx[j],y+dy[j]});
            }
        }
    }
    q.clear();
    q.push_back({n,m});
    for(int i=0;i<sz(q);++i)
    {
        auto [x,y] = q[i];
        for(int j=0;j<4;++j)
        {
            int u = x + dx[j],v = y + dy[j];
            if(valid(x+dx[j],y+dy[j]) && nn[x+dx[j]][y+dy[j]] > nn[x][y] + w && a[u][v] != -1)
            {
                nn[x+dx[j]][y+dy[j]] = nn[x][y] + w;
                q.push_back({x+dx[j],y+dy[j]});
            }
        }
    }
    ll ans = INF;
    amin(ans,one[n][m]);
    ll A = INF,B = INF;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j] > 0)
            {
                amin(A,one[i][j] + a[i][j]);
                amin(B,nn[i][j] + a[i][j]);
            }
        }
    }
    amin(ans,A+B);
    if(ans == INF)
        ans = -1;
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