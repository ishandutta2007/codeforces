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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> dps(n+1,vector<int>(2,0)),dpf(n+1,vector<int>(2,0));
    dps[n][0] = dps[n][1] = 0;
    for(int i=n-1;i>=0;--i)
    {
        if(s[i]=='L')
            dps[i][1] = 0,dps[i][0] = 1 + dps[i+1][1];
        else
            dps[i][0] = 0,dps[i][1] = 1 + dps[i+1][0];
    }
    dpf[0][0] = dpf[0][1] = 0;
    for(int i=1;i<=n;++i)
    {
        if(s[i-1] == 'L')
        {
            dpf[i][0] = dpf[i-1][1] + 1;
            dpf[i][1] = 0;
        }
        else
            dpf[i][1] = dpf[i-1][0] + 1,dpf[i][0] = 0;
    }
    for(int i=0;i<=n;++i)
        cout<<dpf[i][0]+dps[i][1]+1<<" ";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}