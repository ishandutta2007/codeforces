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
#define INF 2000000000000000000
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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

struct node{
    ll a,p[7];
    node ()
    {
        mem0(p);
    }
};
const int N=100005;
node a[N];
ll dp[N][1<<8],n,p,k;
ll C;
ll getans(ll pos,ll mask)
{
    if(pos==n)
    {
        if(mask==C)
            return 0;
        else return -INF;
    }
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    ll x=__builtin_popcount(mask);
    ll ans=-INF;
    for(ll j=0;j<p;++j)
    {
        if(mask&(1<<j))continue;
        amax(ans,getans(pos+1,mask|(1<<j))+a[pos].p[j]);
    }
    ll cnt=pos-x;
    //cout<<"cnt"<<cnt<<endl;
    if(cnt<k)
        amax(ans,getans(pos+1,mask)+a[pos].a);
    else amax(ans,getans(pos+1,mask));
    return dp[pos][mask]=ans;
}
int _runtimeTerror_()
{
    ll i,j;
    mem1(dp);
    cin>>n>>p>>k;
    C=power(2,p)-1;
    for(i=0;i<n;++i)
        cin>>a[i].a;
    for(i=0;i<n;++i)
    {
        for(j=0;j<p;++j)
            cin>>a[i].p[j];
    }
    sort(a,a+n,[&](node a,node b){return a.a>b.a;});
    //for(i=0;i<n;++i)
    //    cout<<a[i].a<<" "<<a[i].p[0]<<endl;
    cout<<getans(0,0);
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