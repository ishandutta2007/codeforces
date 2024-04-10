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
    ll cur = 0;
    ll ans = 0;
    vector<ll> t(n),x(n);
    for(int i=0;i<n;++i)
        cin>>t[i]>>x[i];
    t.pb(INF);
    bool on = false;
    bool l = false,r = false;
    ll des = -1;
    for(int i=0;i<n;++i)
    {
        if(on)
        {
            if(cur<des && x[i]>=cur && x[i]<=des && abs(x[i]-cur)<=t[i+1]-t[i])
                ++ans;
            if(cur>des && x[i]>=des && x[i]<=cur && abs(x[i]-cur)<=t[i+1]-t[i])
                ++ans;
            if(abs(cur-des)<=t[i+1]-t[i])
                cur = des,on = false;
            else
            {
                if(cur > des)
                    cur -= t[i+1]-t[i];
                else
                    cur += t[i+1]-t[i];
            }
        }
        else
        {
            if(abs(cur-x[i])<=t[i+1]-t[i])
            {
                cur = x[i],++ans;
            }
            else
            {
                on = true;
                des = x[i];
                if(cur>x[i])
                    cur -= t[i+1]-t[i];
                else
                    cur += t[i+1]-t[i];
            }
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