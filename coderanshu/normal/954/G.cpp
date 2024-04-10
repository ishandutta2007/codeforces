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
#define PI 3.1415926536
#define INF 9000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
template<typename T, typename U> static inline void setmin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void setmax(T &x, U y){ if(x<y) x=y; }

const int N=500004;
ll a[N],n,r,k,temp[N];
bool check(ll m)
{
    ll val=k,i,j;
    ll cnt=0;
    for(int i=0;i<=n+2;++i)
        temp[i]=0;
    for(i=0;i<n;++i)
    {
        cnt+=temp[i];
        if(a[i]+cnt<m)
        {
            if(m-a[i]-cnt>val)
                return false;
            val-=m-a[i]-cnt;
            temp[min(i+2*r+1,n)]-=m-a[i]-cnt;
            cnt+=m-a[i]-cnt;
        }
    }
    return true;
}
int _runtimeTerror_()
{
    ll i;
    cin>>n>>r>>k;
    for(i=0;i<n;++i)
        cin>>a[i];
    ll psum[n+1];
    psum[0]=0;
    for(i=1;i<=n;++i)
        psum[i]=psum[i-1]+a[i-1];
    for(i=0;i<n;++i)
    {
        ll up=i+r+1,lo=i-r;
        if(i+r+1>n)up=n;
        if(lo<0)lo=0;
        a[i]=psum[up]-psum[lo];
    }
    ll lo=0,hi=5000000000000000000;
    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        if(check(mid))
            lo=mid+1;
        else hi=mid-1;
    }
    cout<<lo-1;
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
    cerr<<"\n"<<_time_;
    return 0;
}