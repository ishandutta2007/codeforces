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
    vector<ll> a(n+1);
    vector<ll> e,o;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x&1)
            o.pb(x);
        else
            e.pb(x);
    }
    sort(all(o)),reverse(all(o));
    sort(all(e)),reverse(all(e));
    ll alice = 0,bob = 0;
    int l = 0,r = 0;
    int cur = 1;
    while(l<sz(e) || r<sz(o))
    {
        if(cur == 1)
        {
            if(l<sz(e) && r<sz(o))
            {
                if(e[l]>o[r])
                    alice += e[l],++l;
                else
                    ++r;
            }
            else if(l<sz(e))
            {
                alice += e[l],++l;
            }
            else
                ++r;
        }
        else
        {
            if(l<sz(e) && r<sz(o))
            {
                if(e[l]<o[r])
                    bob += o[r],++r;
                else
                    ++l;
            }
            else if(r<sz(o))
                bob += o[r],++r;
            else
                ++l;
        }
        cur ^= 1;
    }
    if(alice>bob)
        cout<<"Alice\n";
    else if(bob>alice)
        cout<<"Bob\n";
    else
        cout<<"Tie\n";
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