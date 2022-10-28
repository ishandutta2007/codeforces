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
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
#define MOD 1000000007
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




ll pos[200005];
ll v[200005];
ll ini[200005];
ll t[200005];
ll la[200005];
ll ra[200005];
ll rb[200005];
ll lb[200005];
vector<ll>bt[200005];
vector<ll>btx[200005];
const ll N=200000;
void sum(ll x,ll y)
{
    for(;x>0;x-=(x&(-x)))
    {
        // trace(x,y);
        bt[x].pb(y);
    }
}
void upd(ll x,ll y)
{
    for(;x<=N;x+=(x&(-x)))
    {
        // trace(x,y);
        bt[x].pb(y);
    }
}

void update(ll x,ll y,ll z)
{
    for(;x<=N;x+=(x&(-x)))
    {
        // trace(x,y);
        // trace(x,lower_bound(bt[x].begin(),bt[x].end(),y)-bt[x].begin()+1);
        // trace(bt[x].size());
        // trace(btx[x].size());
        for(int j=lower_bound(bt[x].begin(),bt[x].end(),y)-bt[x].begin()+1;j<=bt[x].size();j+=(j&-j))
        {
            // trace(j);
            btx[x][j-1]+=z;
        }
    }
    // trace("ok");
}

ll find(ll x,ll y)
{
    ll sum=0;
    for(;x>0;x-=(x&(-x)))
    {
        // trace(x,y);
        for(int j=lower_bound(bt[x].begin(),bt[x].end(),y)-bt[x].begin()+1;j>0;j-=(j&-j))
        {
            // trace(j,bt[x][j-1]);
            sum+=btx[x][j-1];
        }
    }
    // trace(sum);
    return sum;
}

void solve()
{
    ll n;
    cin>>n;
    ll q;
    cin>>q;

    rep(i,n)
    {
        ll x;
        cin>>x;
        pos[x]=i+1;
    }
    rep(i,n)
    {
        ll x;
        cin>>x;
        v[i+1]=pos[x];   
        ini[i+1]=v[i+1];
        upd(i+1,pos[x]);
        // trace(i+1,pos[x]);
    }
    rep(i,q)
    {
        cin>>t[i];
        if(t[i]==1)
        {
            cin>>la[i]>>ra[i]>>lb[i]>>rb[i];
            sum(rb[i],ra[i]);
            sum(rb[i],la[i]-1);
            sum(lb[i]-1,ra[i]);
            sum(lb[i]-1,la[i]-1);
        }
        else
        {
            cin>>la[i]>>ra[i];
            upd(la[i],v[la[i]]);
            upd(ra[i],v[ra[i]]);
            swap(v[la[i]],v[ra[i]]);
            upd(la[i],v[la[i]]);
            upd(ra[i],v[ra[i]]);
        }
    }
    rep(i,n+4)
    {
        sort(all(bt[i+1]));
        bt[i+1].resize(unique(all(bt[i+1]))-bt[i+1].begin());
        
        // trace(bt[i+1]);
    }
    rep(i,N)
    {
        rep(j,bt[i+1].size())
        {
            btx[i+1].pb(0);
        }
    }
    rep(i,n)
    {
        v[i+1]=ini[i+1];
        update(i+1,v[i+1],1);
    }
    rep(i,q)
    {
        if(t[i]==1)
        {
            ll ans=0;
            ans+=find(rb[i],ra[i]);
            ans-=find(rb[i],la[i]-1);
            ans-=find(lb[i]-1,ra[i]);
            ans+=find(lb[i]-1,la[i]-1);
            cout<<ans<<endl;
        }
        else
        {
            update(la[i],v[la[i]],-1);
            update(ra[i],v[ra[i]],-1);
            swap(v[la[i]],v[ra[i]]);
            update(la[i],v[la[i]],1);
            update(ra[i],v[ra[i]],1);
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
    int tx=1;
    // cin>>t;
    fr(i,1,tx)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}