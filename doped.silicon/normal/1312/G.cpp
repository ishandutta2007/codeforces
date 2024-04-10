// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 100000000000ll
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

struct node
{
    node* ch[26];
    ll ans;
    ll k;
};
node* getnode()
{
    node* n=new node();
    rep(i,26)
    {
        n->ch[i]=NULL;
    }
    n->ans=INF;
    n->k=0;
    return n;
}
ll st[1000015*4];
ll lazy[1000015*4];
node* r[1000015];
void push(ll v)
{
    if(lazy[v])
    {
        st[2*v]+=lazy[v];
        st[2*v+1]+=lazy[v];
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        lazy[v]=0;
    }
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
        return;
    if(l==tl&&r==tr)
    {
        st[v]+=x;
        lazy[v]+=x;
    }
    else
    {
        ll tm=(tl+tr)/2;
        push(v);
        update(2*v,tl,tm,l,min(r,tm),x);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,x);
        st[v]=min(st[2*v],st[2*v+1]);
    }
}
ll query(ll v,ll tl,ll tr,ll x)
{
    if(tl==tr)
    {
        return st[v];
    }
    else
    {
        ll tm=(tl+tr)/2;
        push(v);
        st[v]=min(st[2*v],st[2*v+1]);
        if(x<=tm)
        {
            return query(2*v,tl,tm,x);
        }
        return query(2*v+1,tm+1,tr,x);
    }
}
ll n;
ll hg[1000005];
void dfs(node* x,ll d)
{
    ll an=x->ans;
    ll bt=query(1,0,n,d);
    ll z=-bt+an;
    if (hg[x->k])
    {
        update(1,0,n,0,n,1);
        an=st[1];
        an=min(an,x->ans);
        z++;
    }
    x->ans=an;
    update(1,0,n,d,d,z);
    rep(i,26)
    {
        if(x->ch[i]!=NULL)
        {
            (x->ch[i])->ans=x->ans+1;
            dfs(x->ch[i],d+1);
        }
    }
    update(1,0,n,d,d,-z+INF);
}
void solve() 
{
    cin>>n;
    r[0]=getnode();
    rep(i,1000015*4)
    {
        st[i]=INF;
    }
    r[0]->ans=0;
    // update(1,0,n,0,0,0);
    rep(i,n)
    {
        ll x;
        char ch;
        cin>>x>>ch;
        ll z=ch-'a';
        r[i+1]=getnode();
        r[x]->ch[z]=r[i+1];
        r[i+1]->k=i+1;
    }
    ll q;
    cin>>q;
    vector<ll>v;
    while(q--)
    {
        ll x;
        cin>>x;
        hg[x]=1;
        v.pb(x);
    }
    dfs(r[0],0);
    for(auto x:v)
    {
        cout<<r[x]->ans<<' ';
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
    int t=1;
    // cin>>t;
    fr(i,1,t)
    {
        solve();
    }
    end_routine();
}