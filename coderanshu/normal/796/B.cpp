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
    int n,m,k;
    cin>>n>>m>>k;
    int ans = 1;
    vector<int> v(n+1,0);
    for(int i=1;i<=m;++i)
    {
        int x;
        cin>>x;
        v[x] = 1;
    }
    if(v[1] == 1)
    {
        cout<<"1\n";return 0;
    }
    for(int i=1;i<=k;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x == ans || y == ans)
        {
            ans = x^y^ans;
        }
        if(v[ans] == 1)
        {
            cout<<ans<<"\n";
            return 0;
        }
    }
    cout<<ans;
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