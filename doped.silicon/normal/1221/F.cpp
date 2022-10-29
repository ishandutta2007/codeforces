// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef ritick
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000000000
#define MOD 998244353
#define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb emplace_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()

#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs

#ifdef ritick
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
// #define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }


const ll N=1000100;
pair<ll,ll> st[N*8];
ll lazy[N*8];
vector<pair<ll,ll>>v[N];
vector<ll>val;
vector<pair<pair<ll,ll>,ll>>vx;

void push(ll v)
{
    if(lazy[v])
    {
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        st[2*v].ff+=lazy[v];
        st[2*v+1].ff+=lazy[v];
        lazy[v]=0;
    }
}

void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        st[v]=mp(-val[tl],tl);
    }
    else 
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v]=max(st[2*v],st[2*v+1]);
    }
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
    {
        return ;
    }
    else if(tl==l&&tr==r)
    {
        lazy[v]+=x;
        st[v].ff+=x;
    }
    else
    {
        ll tm=(tl+tr)/2;
        push(v);
        update(2*v,tl,tm,l,min(r,tm),x);
        update(2*v+1,tm+1,tr,max(tm+1,l),tr,x);
        st[v]=max(st[2*v],st[2*v+1]);
    }
}

pair<ll,ll> query(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
    {
        return {-INF,0};
    }
    if(tl==l&&tr==r)
    {
        return st[v];
    }
    ll tm=(tl+tr)/2;
    push(v);
    return max(query(2*v,tl,tm,l,min(tm,r)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
}

void solve() 
{   
    ll n;
    cin>>n;
    rep(i,n)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        vx.pb(mp(mp(x,y),z));
        val.pb(x);
        val.pb(y);
    }
    val.pb(0);
    sort(all(val));
    val.pb(val.back()+1);
    val.resize(unique(all(val))-val.begin());
    for(auto z:vx)
    {
        ll x=lower_bound(all(val),z.ff.ff)-val.begin();
        ll y=lower_bound(all(val),z.ff.ss)-val.begin();
        v[min(x,y)].pb(mp(max(x,y),z.ss));
    }
    n=val.size();
    build(1,0,n-1);
    ll ans=-1, l=1,r=1;
    for(ll i=val.size()-1;i>=0;i--)
    {
        for(auto z:v[i])
        {
            update(1,0,n-1,z.ff,n-1,z.ss);
        }
        auto cur=query(1,0,n-1,i,n-1);
        if(ans<cur.ff+val[i])
        {
            ans=cur.ff+val[i];
            l=val[i],r=val[cur.ss];
        }
    }
    cout<<ans<<endl<<l<<' '<<l<<' '<<r<<' '<<r<<endl;




}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef ritick
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}