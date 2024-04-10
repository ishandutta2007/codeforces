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
    ll n,m;
    vector<ll> v;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;++j)
            s[j]='1'+'0'-s[j];
        reverse(all(s));
        ll num=0;
        for(int j=0;j<m;++j)
            num+=(s[j]-'0')*power(2,j);
        v.pb(num);
        //cout<<num<<endl;
    }
    ll lo=0,hi=power(2,m);
    ll x=power(2,m)-n;
    v.pb(-1),v.pb(hi);
    sort(all(v));
    ll y=(x-1)/2;
    ll ans;
    for(int i=0;i<n+1;++i)
    {
        ll ff=(hi-(n+2-i-1)-y);
        if(ff>v[i] && ff<v[i+1])
            ans=ff;
    }
    vector<int> vv;
    while(ans>0)
    {
        vv.pb(ans%2);
        ans/=2;
    }
    while(sz(vv)<m)vv.pb(0);
    reverse(all(vv));
    for(int i=0;i<m;++i)cout<<-vv[i]+1;
        cout<<endl;
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
    cerr<<"\n"<<_time_;
    return 0;
}