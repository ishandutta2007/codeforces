#include<bits/stdc++.h>
using namespace std ;

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

const int M=1000000007;
const int MM=998244353;
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
    long long l,r,ans=0;
    cin>>l>>r;
    if(r<10)
    {
        cout<<r-l+1;return 0;
    }
    if(l<10)
        ans+=10-l,l=10;
    auto f=[&](long long n)
    {
        if(n<10)
            return 0ll;
        ll val=0;
        string s=to_string(n);
        ll len=2;
        while(len<s.size())
        {
            val+=9*power(10,len-2);
            ++len;
        }
        int x=1;
        while(x<s[0]-'0')
        {
            val+=power(10,len-2);
            ++x;
        }
        for(int i=1;i<len-1;++i)
        {
            val+=(s[i]-'0')*power(10,len-i-2);
        }
        string t=s;
        t.back()=t[0];
        if(t<=s)
            ++val;
        return val;
    };

    ans+=f(r)-f(l-1);
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