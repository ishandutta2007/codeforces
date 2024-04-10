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
    int n,m,x;
    cin>>n>>m>>x;
    vector<ll> a(n+1),ans(m+1),uu(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    set<pll> s;
    for(int i=1;i<=m;++i)
    {
        ans[i] += a[i];
        uu[i] = i;
        s.insert({ans[i],i});
    }
    int cur = m+1;
    if(m == 1)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;++i)
            cout<<"1 ";
        cout<<"\n";
        return 0;
    }
    while(cur <= n)
    {
        auto [aa,bb] = *s.begin();
        s.erase(s.begin());
        auto [u,v] = *s.begin();
        ll pos = u + x;
        for(cur;cur<=n;++cur)
        {
            if(aa + a[cur]> pos)
                break;
            aa += a[cur];
            uu[cur] = bb;
            ans[bb] += a[cur];
        }
        s.insert({aa,bb});
    }
    cout<<"YES\n";
    for(int i=1;i<=n;++i)
        cout<<uu[i]<<" ";
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