#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef bhartiya
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pii, int> piii;

typedef vector<int> vi;
typedef vector<pii> vii;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define INF 1000000000000000000ll
#define MOD 1000000000
#define mod 1000000000
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)
#define ff first
#define ss second
 
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar,val) memset(ar, val, sizeof(ar))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

 
#ifdef bhartiya
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define end_routine() 
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif
 
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) {return fabs(a - b) < 1e-9;}
int gcd(int a, int b){ return b==0 ? a : gcd(b, a%b); }
ll modpow(ll b, ll e) {
    ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans;}
struct node
{
    ll val;
    node* l;
    node* r;
    node() : val(0), l(NULL) ,r(NULL) {};
    node(node* l,node* r)
    {
        this->val = l->val+r->val;
        this->l=l;
        this->r=r;
    }
    node(int val)
    {
        this->val= val;
        this->l=NULL;
        this->r=NULL;
    }
};
typedef node* st;
st build(ll l,ll r)
{
    if(l==r)
        return new node(0);
    ll tm=(l+r)/2;
    return new node(build(l,tm),build(tm+1,r));
}
st update(st v,ll tl,ll tr,ll i,ll val)
{
    if(tl==tr)
    {
        return new node(val);
    }
    ll tm=(tl+tr)/2;
    if(i<=tm)
    {
        st nn = new node(update(v->l,tl,tm,i,val),v->r);
        return nn;
    }
    else
    {
        st nn = new node(v->l,update(v->r,tm+1,tr,i,val));
        return nn;
    }
}
ll query(st v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    if(tl==l&&tr==r)
    {
        return v->val;
    }
    ll tm=(tl+tr)/2;
    return query(v->l,tl,tm,l,min(r,tm))+query(v->r,tm+1,tr,max(l,tm+1),r);
}
ll cnt[500005];
ll nxt[500005];
ll f[500005];
ll e[500005];
st root[500005];
void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    rep(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
        f[x]=INF;
    }
    map<ll,ll>nx;
    for(ll i=n-1;i>=0;i--)
    {
        ll x=v[i];
        if(nx.find(x)==nx.end())
        {
            nxt[i]=n+1;
        }
        else
        {
            nxt[i]=nx[x];
        }
        nx[x]=i;
        // cout<<nxt[i]<<endl;
        f[x]=i;
    }
    rep(i,n)
    {
        ll x=v[i];
        cnt[x]++;
        e[i]=-1;
        if(cnt[x]>k)
        {
            e[i]=f[x];
            f[x]=nxt[f[x]];
        }
        // cout<<e[i]<<endl;
    }
    root[0]=build(0,n-1);
    for(ll i=0;i<n;i++)
    {
        root[i]=update(root[i],0,n-1,i,1);
        if(e[i]!=-1)
        {
            root[i]=update(root[i],0,n-1,e[i],0);
        }
        root[i+1]=root[i];
    }
    ll la=0;
    ll q;
    cin>>q;
    rep(i,q)
    {
        ll x,y;
        cin>>x>>y;
        x=(x+la)%n;
        y=(y+la)%n;
        if(y<x)
            swap(x,y);
        la=query(root[y],0,n-1,x,y);
        cout<<la<<endl;
    }
    
}

signed main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
    #ifdef rg
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int begtime = clock();
    ll t=1;
    for(ll i=1;i<=t;i++)
    {
        solve();
    }
}