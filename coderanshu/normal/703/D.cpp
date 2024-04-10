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

const int N=1000005;
ll a[N],pxor[N];
map<ll,ll> last;

template<typename T>
class fenwick {
public:
    T bit[N]{};
    void update(ll st,ll en,ll in,T val)
    {
        for(ll j=in;j<=en;j+=j&-j)
            bit[j]^=val;
    }
    T get(ll r)
    {
        T x{};
        while(r>0)
        {
            x^=bit[r];
            r-=r&-r;
        }
        return x;
    }
    T query(ll l,ll r)
    {
        return get(r)^get(l-1);
    }
};
fenwick<ll> fenw;
vector<pll> query[N];
ll ans[N];

int _runtimeTerror_()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    pxor[0]=0;
    for(int i=1;i<=n;++i)
        pxor[i]=pxor[i-1]^a[i];
    ll m;
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        int l,r;
        cin>>l>>r;
        query[r].pb({l,i});
    }
    for(int i=1;i<=n;++i)
    {
        if(last[a[i]])
            fenw.update(1,n,last[a[i]],a[i]);
        last[a[i]]=i;
        fenw.update(1,n,last[a[i]],a[i]);
        for(auto j:query[i])
        {
            ans[j.S]=fenw.query(j.F,i)^pxor[i]^pxor[j.F-1];
        }
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<endl;
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