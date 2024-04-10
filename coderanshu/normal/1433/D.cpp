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

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> v(n);
    set<int> s;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        s.insert(v[i]);
    }
    if(sz(s)==1)
    {
        cout<<"NO\n";return 0;
    }
    cout<<"YES\n";
    int x = *s.begin();
    s.erase(s.begin());
    int y = *s.begin();
    int u = -1;
    for(int i=0;i<n;++i)
    {
        if(v[i]==x)
        {
            u = i+1;break;
        }
    }
    int xx = -1;
    for(int i=0;i<n;++i)
    {
        if(v[i]==y)
        {
            xx = i+1;
            cout<<u<<" "<<i+1<<"\n";
        }
    }
    for(int i=0;i<n;++i)
    {
        if(v[i]!=y && i+1!=u)
        {
            cout<<xx<<" "<<i+1<<"\n";
        }
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