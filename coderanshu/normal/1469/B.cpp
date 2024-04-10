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
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;++i)
        cin>>b[i];
    int ans = 0;
    int sum = 0;
    for(int i=0;i<m;++i)
        sum += b[i],amax(ans,sum);
    sum = 0;
    for(int i=0;i<n;++i)
    {
        sum += a[i];
        amax(ans,sum);
        int x = 0;
        for(int j=0;j<m;++j)
        {
            x += b[j];
            amax(ans,sum+x);
        }
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}