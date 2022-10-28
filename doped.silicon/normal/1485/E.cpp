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
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
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
// #define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


vector<ll>v[200005];
vector<pair<ll,ll>>lev[200005];
ll ar[200005];
ll par[200005];
int dep=0;
ll dp[200005];
ll mx[200005];
void dfs(ll x,ll p,ll d)
{
    par[x]=p;
    lev[d].pb(mp(ar[x],x));
    dep=max(dep,d);
    for(auto z:v[x])
    {
        if(z!=p)
        {
            dfs(z,x,d+1);
        }
    }
}
void solve()
{
    ll n;
    cin>>n;
    rep(i,n+5)
    {
        dep=0;
        ar[i]=0;
        par[i]=0;
        dp[i]=0;
        mx[i]=0;
        lev[i].clear();
        v[i].clear();
    }

    rep(i,n-1)
    {
        ll x;
        cin>>x;
        v[i+2].pb(x);
        v[x].pb(i+2);
    }
    rep(i,n-1)
    {
        cin>>ar[i+2];
    }
    dfs(1,1,0);
    ll an=0;
    // trace(dep);
    for(int i=dep;i>=1;i--)
    {
        sort(all(lev[i]));
        // trace(lev[i].size());
        multiset<ll>s,s1;
        for(auto z:lev[i])
        {
            ll m=0;
            for(auto x:v[z.ss])
            {
                if(x!=par[z.ss])
                {
                    m=max(dp[x],m);
                }
            }
            mx[z.ss]=m;
            s.insert(m+ar[z.ss]);
        }
        for(auto z:lev[i])
        {
            ll ans=0;
            ans=mx[z.ss]+max(z.ff-lev[i][0].ff,lev[i][lev[i].size()-1].ff-z.ff);
            if(!s.empty())
            {
                ans=max(ans,*s.rbegin()-z.ff);
            }
            if(!s1.empty())
            {
                ans=max(ans,z.ff-*s1.begin());
            }
            s.erase(s.find(z.ff+mx[z.ss]));
            s1.insert(z.ff-mx[z.ss]);
            // trace(z.ss,z.ff,mx[z.ss],z.ff-mx[z.ss]);
            dp[z.ss]=ans;
            an=max(an,ans);
            // trace(z,ans,an);
        }
    }
    cout<<an<<endl;



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
    cin>>t;
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
        // vector<int>x={0,1,1};
        // vector<int>y={0,0,1};
        // SecondDiameters *a=new SecondDiameters();
        // ll ans=a->getSecondDiameters(x,y);
        // trace(ans);
        // trace(v);
    }
    end_routine();
}