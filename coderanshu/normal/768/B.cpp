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

long long get(long long n)
{
    if(n <= 1)
        return 1;
    return 1 + 2 * get(n/2);
}
long long get2(long long n)
{
    if(n <= 1)
        return n;
    return n%2 + 2 * get2(n/2);
}

long long ans = 0;

void go(ll n,ll l,ll r)
{
    if(l > r)
        return ;
    if(r == 0)
        return ;
    if(n <= 1)
    {
        ans += n;
        return ;
    }
    if(l == 1 && r == get(n))
    {
        ans += get2(n);
        return ;
    }
    ll left = get(n/2);
    if(left >= r)
    {
        go(n/2,l,r);
        return ;
    }
    if(left + 2 <= l)
    {
        go(n/2,l-left-1,r-left-1);
        return ;
    }
    ans += n % 2;
    go(n/2,l,left);
    go(n/2,1,r-left-1);
}

int _runtimeTerror_()
{
    long long n,l,r;
    cin>>n>>l>>r;
    go(n,l,r);
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}