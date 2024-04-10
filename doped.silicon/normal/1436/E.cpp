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
typedef int ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
// #define MOD 2000000000000000000ll
#define MOD 1000000007
#define EPS 1e-7
// #define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (int)x.length()
#define sz(x) (int)x.size();

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








ll last[100005];
ll l[100005];
ll r[100005];
ll ar[100005];
ll bs=500;
ll cnt[100005];
ll mex[100005];
vector<pair<ll,ll>>v;
ll bt[500005];
void update(ll x,ll d)
{
    for(;x<=100005;x+=(x&-x))
    {
        bt[x]+=d;
    }
}
ll find()
{
    ll ans=0;
    for(int i=17;i>=0;i--)
    {
        if(bt[ans+(1<<i)]==(1<<i))
            ans+=(1<<i);
    }
    return ans+1;
}
void add(ll i)
{
    i=ar[i];
    cnt[i]++;
    if(cnt[i]==1)
    {
        update(i,1);
    }
}
void rem(ll i)
{
    i=ar[i];
    cnt[i]--;
    if(cnt[i]==0)
    {
        update(i,-1);
    }
}
bool cmp(pii le, pii ri) {
    if (le.ff / bs != ri.ff / bs)
        return le.ff < ri.ff;
    if ((le.ff / bs) & 1)
        return le.ss < ri.ss;
    return le.ss > ri.ss;
}

void solve()
{   
    ll n;
    cin>>n;
    rep(i,n+2)
    {
        last[i]=-1;
    }
    ll mx=0;
    rep(i,n)
    {
        ll x;
        cin>>ar[i];
        x=ar[i];
        mx=max(mx,x);
        if(x!=1)
        {
            mex[1]=1;
        }
        last[x]=i;
        l[i]=last[x+1]+1;
    }
    rep(i,n+2)
    {
        last[i]=n;
    }
    set<pair<ll,ll>>sx;
    for(int i=n-1;i>=0;i--)
    {
        ll x=ar[i];
        last[x]=i;
        r[i]=last[x+1]-1;
        sx.insert(mp(l[i],r[i]));
    }
    for(auto z:sx)
    {
        v.pb(z);
    }
    sort(all(v),cmp);
    ll l=0,r=-1;
    
    for(auto z:v)
    {
        ll l1=z.ff;
        ll r1=z.ss;
        while(r<r1)
        {
            r++;
            add(r);
        }
        while(l<l1)
        {
            rem(l);
            l++;
        }
        while(l>l1)
        {
            l--;
            add(l);
        }
        while(r>r1)
        {
            rem(r);
            r--;
        }
        mex[find()]=1;
    }
    for(ll i=1;i<=n+2;i++)
    {
        if(mex[i]==0)
        {
            cout<<i;
            return;
        }
    }


}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
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