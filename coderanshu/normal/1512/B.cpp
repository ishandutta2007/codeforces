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


const int N = 500;
char c[N][N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<pii> a;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>c[i][j];
            if(c[i][j] == '*')
                a.push_back({i,j});
        }
    }
    if(a[0].F == a[1].F)
    {
        int cur = 1;
        if(a[0].F == 1)
            cur = n;
        c[cur][a[0].S] = c[cur][a[1].S] = '*';
    }
    else if(a[0].S == a[1].S)
    {
        int cur = 1;
        if(a[0].S == 1)
            cur = n;
        c[a[0].F][cur] = c[a[1].F][cur] = '*';
    }
    else
    {
        c[a[0].F][a[1].S] = c[a[1].F][a[0].S] = '*';
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cout<<c[i][j];
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