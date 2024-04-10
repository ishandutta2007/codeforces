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
    ll n,x;
    cin>>n>>x;
    ll d[n];
    for(int i=0;i<n;++i)
        cin>>d[i];
    vector<ll> v;
    for(int i=0;i<n;++i)
        v.pb(d[i]);
    for(int i=0;i<n;++i)
        v.pb(d[i]);
    ll psum[2*n+2],val[2*n+2];
    psum[0]=0,val[0]=0;
    for(int i=1;i<=2*n;++i)
        psum[i]=psum[i-1]+v[i-1],val[i]=val[i-1]+v[i-1]*(v[i-1]+1)/2;
    ll fuck=0;
    for(int i=n;i<2*n;++i)
    {
        ll lo=0,hi=i+1;
        ll y=psum[i+1];
        while(lo<=hi)
        {
            ll mid=(lo+hi)>>1;
            if(y-psum[mid]>=x)
                lo=mid+1;
            else
                hi=mid-1;
        }
        //cout<<lo-1<<endl;
        //cout<<psum[i+1]-psum[lo-1]<<endl;
        ll ans=val[i+1]-val[lo-1];
        //cout<<"ans"<<ans<<endl;
        ll rem=(psum[i+1]-psum[lo-1])-x;
        ans-=(rem*(rem+1))/2;
        //cout<<"ans 2f "<<ans<<endl;
        amax(fuck,ans);
    }
    cout<<fuck<<endl;
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