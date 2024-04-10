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

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    ll cost = 0;
    vector<vector<ll>> a(n+1,vector<ll>(m+1)),ans = a;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int _=1;_<=m;++_)
    {
        int x = -1,y = -1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(x == -1)
                    x = i,y = j;
                else if(a[i][j] < a[x][y])
                    x = i,y = j;
            }
        }
        ans[x][_] = a[x][y];
        a[x][y] = INF;
        // vector<ll> ans;
        for(int i=1;i<=n;++i)
        {
            if(i == x)
            {
                continue;
            }
            pll mx = {-INF,-INF};
            for(int j=1;j<=m;++j)
            {
                if(a[i][j] == INF)
                    continue;
                amax(mx,make_pair(a[i][j],1ll*j));
            }
            ans[i][_] = a[i][mx.S];
            // ans.push_back(mx.S);
            a[i][mx.S] = INF;
        }
        // for(auto j:ans)
        //     cout<<j<<" ";
        // cout<<"\n";
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cout<<ans[i][j]<<" ";
        }
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}