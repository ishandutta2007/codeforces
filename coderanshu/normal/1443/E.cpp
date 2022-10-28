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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

const int N = 200005;

ll a[N];
ll fac[20];

int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    for(int i=1;i<=n;++i)
        a[i] = a[i-1] + i;
    fac[0] = 1;
    for(int i=1;i<=14;++i)
        fac[i] = fac[i-1] * i;

    ll cur = 0;

    auto permute = [&]()
    {
        int l = n - 13;
        amax(l,1);
        ordered_set<int> s;
        for(int i=l;i<=n;++i)
            s.insert(i);
        ll x = cur;
        for(int i=l;i<=n;++i)
        {
            ll y = fac[n-i];
            a[i] = *s.find_by_order(x/y);
            s.erase(a[i]);
            x %= y;
        }
        assert(x==0);
        for(int i=l;i<=n;++i)
            a[i] = a[i-1] + a[i];
    };
    for(int i=1;i<=Q;++i)
    {
        int tt,l,r,x;
        cin>>tt;
        if(tt==1)
        {
            cin>>l>>r;
            cout<<a[r]-a[l-1]<<"\n";
        }
        else
        {
            cin>>x;
            cur += x;
            permute();
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}