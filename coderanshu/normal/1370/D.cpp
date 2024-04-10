#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

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
const int N=200005;
ll a[N];
int n,k;
bool func(ll ii,ll jj,ll check,ll m)
{
    int cnt=0;
    for(int i=ii;i<=jj;++i)
    {
        if(a[i]>m)
            continue;
        int j=i;
        while(j<=jj && a[j]<=m)
            ++j;
        --j;
        cnt+=(j-i+1)/2+(j-i+1)%2;
        i=j;
    }
    return cnt>=check;
}
int _runtimeTerror_()
{
    cin>>n>>k;
    ll lo=INF,hi=-1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        amin(lo,a[i]);
        amax(hi,a[i]);
    }
    ll ans=INF;
    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        bool x=false;
        if(k&1)
        {
            x = x || func(0,n-1,k/2+1,mid);
            x = x || func(1,n-2,k/2,mid);
        }
        else
        {
            x=x || func(0,n-2,k/2,mid);
            x=x || func(1,n-1,k/2,mid);
        }
        if(x)
            ans=mid,hi=mid-1;
        else lo=mid+1;
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