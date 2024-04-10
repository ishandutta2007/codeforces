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
const int N=200005;
ll a[N],t[N],b[N];

int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    int cnt1=0,cnt2=0;
    vector<ll> v1,v2,same;
    for(int i=1;i<=n;++i)
    {
        cin>>t[i]>>a[i]>>b[i];
        if(a[i]==1)
            ++cnt1;
        if(b[i]==1)
            ++cnt2;
        if(a[i]==1 && b[i]==1)
            same.pb(t[i]);
        else if(a[i]==1)
            v1.pb(t[i]);
        else if(b[i]==1)
            v2.pb(t[i]);
    }
    sort(all(same));sort(all(v1));sort(all(v2));
    if(cnt1<k || cnt2<k)
    {
        cout<<-1;return 0;
    }
    ll ans=INF;
    for(int i=1;i<sz(v1);++i)
        v1[i]+=v1[i-1];
    for(int i=1;i<sz(v2);++i)
        v2[i]+=v2[i-1];
    ll sum=0;
    if(sz(v1)>=k && sz(v2)>=k)
        amin(ans,v1[k-1]+v2[k-1]);
    int nn=sz(same);
    for(int i=0;i<nn;++i)
    {
        sum+=same[i];
        if(i==k-1)
        {
            amin(ans,sum);
            break;
        }
        if(sz(v1)>=k-i-1 && sz(v2)>=k-i-1)
            amin(ans,sum+v1[k-i-2]+v2[k-i-2]);
    }
    cout<<ans<<'\n';
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