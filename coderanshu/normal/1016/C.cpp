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
const int N=300005;
ll a[N],b[N],c[N][2],d[N][2],e[N],f[N];
int _runtimeTerror_()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];
    c[0][0]=0,d[0][0]=0,f[0]=b[0],e[0]=a[0];
    for(int i=1;i<n;++i)
        c[i][0]+=c[i-1][0]+i*a[i],d[i][0]+=d[i-1][0]+i*b[i],f[i]=f[i-1]+b[i],e[i]=e[i-1]+a[i];
    c[n-1][1]=d[n-1][1]=0;
    for(int i=n-2;i>=0;--i)
        c[i][1]+=c[i+1][1]+(n-i-1)*a[i],d[i][1]+=d[i+1][1]+(n-i-1)*b[i];
    ll ans=-INF;
    amax(ans,c[n-1][0]+d[0][1]+f[n-1]*n);
    ll val=0;
    for(int i=0;i<n-1;++i)
    {
        if(i&1)
            val+=2*i*b[i]+(2*i+1)*a[i];
        else
            val+=2*i*a[i]+(2*i+1)*b[i];
        ll x=val,y;
        if(i&1)
        {
            y=(i+1)*(e[n-1]-e[i]) +(c[n-1][0]-c[i][0]);
            y+=(n+i+1)*(f[n-1]-f[i]) + (d[i+1][1]);
        }
        else
        {
            y=(i+1)*(f[n-1]-f[i]) +(d[n-1][0]-d[i][0]);
            y+=(n+i+1)*(e[n-1]-e[i]) + (c[i+1][1]);
        }
        x+=y;
        amax(ans,x);
    }
    cout<<ans<<endl;
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