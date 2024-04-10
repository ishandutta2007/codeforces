// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #endif
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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

#define INF 1000000000000ll
#define MOD 998244353
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

ll n,x,y,z;
vector<ll>xx;

vector<vector<ll>>v;
vector<vector<ll>>ans;
map<vector<vector<ll>>,ll>m;

ll mex(vector<ll>v)
{
    set<ll>s;
    for(auto x:v)
    {
        s.insert(x);
    }
    ll n=s.size();
    ll i=0;
    for(auto x:s)
    {
        if(i!=x)
            return i;
        i++;
    }
    return n;
}
void find()
{
    ll a=mex({v[0][5-x],v[1][5-y],v[2][5-z]});
    ll b=mex({v[0][5-x],v[2][5-z]});
    ll c=mex({v[0][5-x],v[1][5-y]});
    rep(i,3)
    {
        v[i].erase(v[i].begin());
    }
    v[0].pb(a);
    v[1].pb(b);
    v[2].pb(c);
    ans[0].pb(a);
    ans[1].pb(b);
    ans[2].pb(c);
}
ll cnt,p;
ll find(ll x,ll y)
{
    if(x>cnt)
        x=(x-cnt)%p+cnt;
    return ans[y][x];
}
void solve()
{  
    v.clear();
    m.clear();
    ans.clear();
    xx.clear();
    vector<ll>bt;
    rep(j,5)
    {
        if(j==1)
        {
            rep(i,3)
            {
                ans.pb(bt);
            }
        }
        bt.pb(0);
    }
    rep(i,3)
    {
        v.pb(bt);
    }
    cin>>n>>x>>y>>z;
    rep(i,n)
    {
        ll a;
        cin>>a;
        xx.pb(a);
    }
    cnt=1;
    p=0;
    while(true)
    {
        m[v]=cnt++;
        find();
        if(m.count(v))
        {
            p=cnt-m[v];
            break;
        }
        if(cnt>36)
        {
            break;
        }
    }
    cnt=cnt-p;
    cnt--;
    ll an=0;
    rep(i,n)
    {
        an=an^find(xx[i],0);
    }
    ll res=0;
    rep(i,n)
    {
        an=an^find(xx[i],0);
        res+=((an^find(max(0ll,xx[i]-x),0))==0);
        res+=((an^find(max(0ll,xx[i]-y),1))==0);
        res+=((an^find(max(0ll,xx[i]-z),2))==0);
        an=an^find(xx[i],0);
    }
    cout<<res<<endl;




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
    cin>>t;
    fr(i,1,t)
    {
        solve();
    }
    end_routine();
}