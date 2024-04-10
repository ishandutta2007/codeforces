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
ll phi(ll n)
{
    ll ans=1;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ll count=1;
            while(n%i==0)
            {
                n/=i;count*=i;
            }
            ans*=(count-count/i);
        }
    }
    if(n>1)ans*=n-1;
    return ans;
}
const int N=100005;
set<pll> v[N];
int MOD;
ll ans=0;
ll n,phi_mod;
ll inv_10[N],pow_10[N];

ll ctree[N],sub[N];
ll cntoftr;
void dfs1(ll s,ll p)
{
    ++cntoftr;
    sub[s]=1;
    for(auto j:v[s])
        if(j.F!=p)
        {
            dfs1(j.F,s);
            sub[s]+=sub[j.F];
        }
}
ll dfs2(ll s,ll p)
{
    for(auto j:v[s])
        if(j.F!=p && sub[j.F]>cntoftr/2)
            return dfs2(j.F,s);
    return s;
}
vector<ll> up;
map<ll,ll> query;
void dfs3(ll s,ll p,ll upval,ll downval,ll dep,bool r)
{
    if(!r)
        ans+=((upval%MOD)==0)+((downval%MOD)==0);
    ll val=-downval*inv_10[dep+1]%MOD;
    val+=MOD;val%=MOD;
    if(query.count(val))
        ans+=query[val];
    up.pb(upval);
    for(auto j:v[s])
    {
        if(j.F!=p)
        {
            dfs3(j.F,s,(j.S*pow_10[dep+1]%MOD+upval)%MOD,(downval*10%MOD+j.S)%MOD,dep+1,r);
        }
    }
}
void decompose(ll s,ll p)
{
    cntoftr=0;
    dfs1(s,s);
    ll centroid=dfs2(s,s);
    if(p==-1)p=centroid;
    ctree[centroid]=p;
    for(auto j:v[centroid])
    {
        v[j.F].erase({centroid,j.S});
        dfs3(j.F,centroid,j.S,j.S,0,false);
        for(auto j:up)
            query[j]++;
        up.clear();
        //cout<<ans<<endl;
    }
    query.clear();
    for(auto j=v[centroid].rbegin();j!=v[centroid].rend();++j)
    {
        dfs3(j->F,centroid,j->S,j->S,0,true);
        for(auto j:up)
            query[j]++;
        up.clear();
    }
    //cout<<"centroid ans "<<centroid<<" "<<ans<<endl;
    query.clear();
    for(auto j:v[centroid])
    {
        decompose(j.F,centroid);
    }
    v[centroid].clear();
}

int _runtimeTerror_()
{
    cin>>n>>MOD;
    for(int i=0;i<n-1;++i)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        w%=MOD;
        v[x].insert({y,w});v[y].insert({x,w});
    }
    phi_mod=phi(MOD);
    inv_10[0]=1;
    pow_10[0]=1;
    ll x=10;
    x=power(x,phi_mod-1,MOD);
    for(int i=1;i<N;++i)
    {
        inv_10[i]=inv_10[i-1]*x%MOD;
        pow_10[i]=pow_10[i-1]*10%MOD;
    }
    decompose(1,-1);
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