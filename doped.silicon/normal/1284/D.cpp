// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
#define bt  __int128
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 4557430888798830399ll
#define MOD 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef bhartiya
template<typename T>
void __p(T a) { cout << a << " "; }
template<typename T>
void __p(std::vector<T> a) { cout << "{ "; for (auto p : a) __p(p); cout << "}"; }
template<typename T, typename F>
void __p(pair<T, F> a) { cout << "{ "; __p(a.first); __p(a.second); cout << "}"; }
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) { __p(a1); __p(a...); }
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";__p(arg1);cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(; ;i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<"| ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }
// clang-format on

const int maxn = 1000005;

vector<pair<pair<ll,ll>,pair<ll,ll>>>v;
vector<pair<ll,ll>>v1;
vector<pair<pair<ll,ll>,ll>>v2;
ll val[100005];
vector<pair<ll,ll>>xx[2];
ll st[400005];
ll ma[100005];
ll lazy[400005];
void push(ll v)
{
    if(lazy[v])
    {
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        st[2*v+1]+=lazy[v];
        st[2*v]+=lazy[v];
        lazy[v]=0;
    }
}
void update(ll v, ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
    {
        return;
    }
    else if(l==tl&&r==tr)
    {
        lazy[v]+=x;
        st[v]+=x;
    }
    else
    {
        push(v);
        ll tm=(tl+tr)/2;
        update( 2*v, tl,tm,l,min(r,tm),x);
        update( 2*v+1, tm+1,tr,max(l,tm+1),min(r,r),x);
        st[v]=st[2*v]+st[v*2+1];
    }
}
ll get(ll v,ll tl,ll tr,ll l, ll r)
{
    if(l>r)
    {
        return 0;
    }
    else if(l==tl&&r==tr)
    {
        return st[v];
    }
    push(v);
    ll tm=(tl+tr)/2;
    return get(2*v,tl,tm,l,min(r,tm))+get(2*v+1,tm+1,tr,max(l,tm+1),r);
}
ll st1[400005];
ll lzy[400005];
void psh(ll v)
{
    if(lzy[v])
    {
        lzy[2*v]+=lzy[v];
        lzy[2*v+1]+=lzy[v];
        st1[2*v+1]+=lzy[v];
        st1[2*v]+=lzy[v];
        lzy[v]=0;
    }
}
void upd(ll v, ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
    {
        return;
    }
    else if(l==tl&&r==tr)
    {
        lzy[v]+=x;
        st1[v]+=x;
    }
    else
    {
        psh(v);
        ll tm=(tl+tr)/2;
        upd( 2*v, tl,tm,l,min(r,tm),x);
        upd( 2*v+1, tm+1,tr,max(l,tm+1),min(r,r),x);
        st1[v]=st1[2*v]+st1[v*2+1];
    }
}
ll get1(ll v,ll tl,ll tr,ll l, ll r)
{
    if(l>r)
    {
        return 0;
    }
    else if(l==tl&&r==tr)
    {
        return st1[v];
    }
    psh(v);
    ll tm=(tl+tr)/2;
    return get1(2*v,tl,tm,l,min(r,tm))+get1(2*v+1,tm+1,tr,max(l,tm+1),r);
}
ll bin(ll x,ll k)
{
    ll l=0,r=xx[k].size();
    ll ans=0;
    while(l<r)
    {
        ll m=(l+r)/2;
        if(xx[k][m].ff<=x)
        {
            l=m+1;
            ans=xx[k][m].ss;
        }
        else
        {
            r=m;
        }
    }
    return ans;
}
ll find(ll l,ll r,ll k)
{
        // trace(val[i])
    return bin(r,k)-bin(l-1,k);
}
ll findind(ll x,ll k)
{
    ll l=0,r=xx[k].size();
    ll ans=0;
    while(l<r)
    {
        ll m=(l+r)/2;
        if(xx[k][m].ff<=x)
        {
            l=m+1;
            ans=xx[k][m].ss;
        }
        else
        {
            r=m;
        }
    }
    return l-1;
}
void solve() 
{
    ll n;
    cin>>n;
    rep(i,n)
    {
        ll x,y,z,w;
        cin>>x>>y>>z>>w;
        v.pb(mp(mp(x,y),mp(z,w)));
    }
    sort(all(v));
    rep(i,n)
    {
        val[i]=rng32()%MOD;
        // trace(val[i]);
    }
    ll xz=0;
    for(auto x:v)
    {
        v1.pb(mp(x.ff.ff,x.ff.ss));
        v2.pb(mp(mp(x.ss.ff,x.ss.ss),xz));
        xz++;
    }
    sort(all(v2));
    ll a=0,b=0;
    rep(i,n)
    {
        a+=val[i];
        b+=val[v2[i].ss];
        xx[0].pb(mp(v1[i].ff,a));
        xx[1].pb(mp(v2[i].ff.ff,b));
    }
    bool han=1;
    xz=0;
    for(auto x:v2)
    {
        ll k=findind(x.ff.ss,1);
        ll k1=findind(x.ff.ff,1);
        // trace(k,k1);
        update(1,0,n-1,k1+1,k,val[x.ss]);
        ma[x.ss]=xz;
        xz++;
    }
    xz=0;
    for(auto x:v1)
    {
        ll k=findind(x.ss,0ll);
        ll k1=findind(x.ff,0);
        upd(1,0,n-1,k1+1,k,val[xz]);
        xz++;
    }
    rep(i,n)
    {
        auto x=v1[i];
        auto y=v2[ma[i]];
        ll a=find(x.ff,x.ss,0ll)%MOD;
        ll b=find(y.ff.ff,y.ff.ss,1ll)%MOD;
        // trace(a,b);
        ll k=findind(y.ff.ss,1ll);
        b=b+get(1,0,n-1,ma[i],ma[i]);
        a=(a+get1(1,0,n-1,i,i));
        a%=MOD;
        b%=MOD;
        // trace(a,b);
        if(a!=b)
        {
            han=0;
        }
    }
    if(han)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   //cout<<fixed;
#ifdef bhartiya
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t=1;
    // cin>>t; 
    fr(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}