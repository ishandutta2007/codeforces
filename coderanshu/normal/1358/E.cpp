#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
#define memf(a)    memset(a,false,sizeof(a))
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }


int _runtimeTerror_()
{
    ll n;
    cin>>n;
    ll a[n],sum=0;
    for(int i=0;i<(n+1)/2;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll x;
    cin>>x;
    sum+=x*(n/2);
    if(sum>0)
    {
        cout<<n<<endl;return 0;
    }
    ll b[n+1];
    for(int i=0;i<(n+1)/2;++i){b[i]=a[i];a[i]-=x;}
    for(int i=(n+1)/2;i<n;++i)
        a[i]=x,b[i]=x;
    ll psum[n+2],ssum[n+2];
    psum[n]=0,ssum[n]=0;
    for(int i=n-1;i>=0;--i)
       ssum[i]=ssum[i+1]+b[i],psum[i]=psum[i+1]+a[i];
    ll y=(n+1)/2;
    ll ff[n+1];
    ff[0]=psum[0];
    for(int i=1;i<n;++i)
        ff[i]=min(ff[i-1],psum[i]);
    for(int i=y-1;i>=1;--i)
    {
        ll yy=ssum[i];
        ll xx=psum[i];
        if(yy<=0)
            continue;
        if(yy+ff[i-1]-xx>0)
        {
            cout<<n-i;return 0;
        }
    }
    cout<<-1<<endl;
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