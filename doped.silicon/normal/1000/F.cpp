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
    pair<ll,ll> val;
    node* l;
    node* r;
    node() : val(mp(INF,0)), l(NULL) ,r(NULL) {};
    node(node* l,node* r)
    {
        this->val = min(l->val,r->val);
        this->l=l;
        this->r=r;
    }
    node(int pos, int val)
    {
        this->val= mp(val,pos);
        this->l=NULL;
        this->r=NULL;
    }
};
typedef node* st;
st build(ll l,ll r)
{
    if(l==r)
    {
        return new node(l,INF);
    }
    ll tm=(l+r)/2;
    return new node(build(l,tm),build(tm+1,r));
}
st update(st v,ll tl,ll tr,ll val,ll pos)
{
    // cout<<tl<<' '<<tr<<endl;
    if(tl==tr)
    {
        return new node(pos,val);
    }
    ll tm=(tl+tr)/2;
    if(pos<=tm)
    {
        return new node(update(v->l,tl,tm,val,pos),v->r);
    }
    else
    {
        return new node(v->l,update(v->r,tm+1,tr,val,pos));
    }
}
pair<ll,ll> query(st v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
    {
        return mp(INF,0);
    }
    if(l==tl&&tr==r)
    {
        return v->val;
    }
    ll tm=(tl+tr)/2;
    auto q1=query(v->l,tl,tm,l,min(r,tm));
    auto q2=query(v->r,tm+1,tr,max(l,tm+1),r);
    return min(q1,q2);
}
st root[500005];
ll l[500005];
void solve()
{
    ll n;
    cin>>n;
    vector<ll>v;
    map<ll,ll>last;
    rep(i,n)
    {
        ll x;
        cin>>x;
        v.pb(x);
        if(last.find(x)==last.end())
        {
            l[i]=-1;
        }
        else
        {
            l[i]=last[x];
        }
        last[x]=i;
    }
    root[0]=build(0,n-1);
    rep(i,n)
    {
        ll z=v[i];
        st xx=root[i];
        if(l[i]!=-1)
        {
            xx=update(xx,0,n-1,INF,l[i]);
        }
        xx=update(xx,0,n-1,l[i],i);
        root[i]=xx;
        root[i+1]=xx;
        // cout<<xx->val.ff<<endl;
        // cout<<xx->val.ss<<endl;
        // cout<<endl;
    }
    ll q;
    cin>>q;
    rep(i,q)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        auto xx=query(root[y],0,n-1,x,y);
        if(xx.ff<x)
        {
            cout<<v[xx.ss]<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
}

signed main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
        // freopen("area.in", "r", stdin);
        // freopen("area.out", "w", stdout);
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