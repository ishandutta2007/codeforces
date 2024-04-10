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
    vector<int> a(n+1),b(n+1);
    vector<bool> done(n+1,false);
    vector<vector<int>> el(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
        if(a[i] != b[i])
            el[b[i]].pb(i);
    }
    vector<int> c(m+1),ans(m+1);
    for(int i=1;i<=m;++i)
        cin>>c[i];
    vector<int> req(n+1,0);
    int x = -1;
    for(int i=1;i<=n;++i)
    {
        if(a[i] != b[i])
            ++req[b[i]];
        else if(b[i] == c[m])
            x = i;
    }
    if(req[c[m]] == 0 && x == -1)
    {
        cout<<"NO\n";return 0;
    }
    if(req[c[m]])
    {
        ans[m] = el[c[m]].back();
        el[c[m]].pop_back();
    }
    else
        ans[m] = x;
    for(int i=m-1;i>=1;--i)
    {
        if(el[c[i]].empty())
            ans[i] = ans[m];
        else
            ans[i] = el[c[i]].back(),el[c[i]].pop_back();
    }
    for(int i=1;i<=n;++i)
    {
        if(sz(el[i]))
        {
            cout<<"NO\n";return 0;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<" ";
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