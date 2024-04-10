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
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }

set<pair<ll,ll>>s[3];
ll w[100005];
ll cnt[100005];
ll c[100005];
vector<pair<ll,pair<ll,ll>>>v[100005];
ll cur;
ll dfs(ll x,ll p)
{
    ll ci=0;
    for(auto z:v[x])
    {
        if(z.ff!=p)
        {
            w[z.ff]=z.ss.ff;
            c[z.ff]=z.ss.ss;
            ll bt=dfs(z.ff,x);
            cnt[z.ff]=bt;
            ll dx=w[z.ff]-w[z.ff]/2;
            cur+=z.ss.ff*bt;
            s[z.ss.ss].insert(mp(dx*bt,z.ff));
            ci+=bt;
        }
    }
    if(ci==0)
    {
        ci=1;
    }
    return ci;
}
void solve()
{
    ll n;
    cin>>n;
    ll sum=0;
    cin>>sum;
    rep(i,3)
    {
        s[i].clear();
    }
    rep(i,n+5)
    {
        cnt[i]=0;
        w[i]=0;
        v[i].clear();
    }
    cur=0;
    rep(i,n-1)
    {
        ll x,y,w,co;
        cin>>x>>y>>w>>co;
        v[x].pb(mp(y,mp(w,co)));
        v[y].pb(mp(x,mp(w,co)));
    }
    dfs(1,1);
    ll ans=0;
    s[1].insert(mp(0,0));
    s[1].insert(mp(0,n+1));
    s[2].insert(mp(0,0));
    // for(auto z:s[1])
    // {
    //     trace(z);
    // }
    // for(auto z:s[2])
    // {
    //     trace(z);
    // }
    // trace(cur);
    ll num=0;
    ll ret=INF;
    while(cur>sum)
    {
        // num++;
        // for(auto z:s[1])
        // {
        //     trace(z);
        // }
        // for(auto z:s[2])
        // {
        //     trace(z);
        // }
        // trace(cur);
        auto e1=*s[1].rbegin();
        s[1].erase(e1);
        auto e4=e1;
        ll x1= w[e1.ss]/2;
        ll dx=x1-x1/2;
        e4.ff=dx*cnt[e4.ss];
        s[1].insert(e4);
        if(e1.ff>=cur-sum)
        {
            ans++;
            break;
        }
        auto e2=*s[1].rbegin();
        auto e3=*s[2].rbegin();
        if(e1.ff+e2.ff>e3.ff)
        {
            // trace(e1);
            // trace(w[e1.ss]);
            s[1].erase(e2);
            cur-=e1.ff;
            cur-=e2.ff;
            ret=min(e2.ff,ret);
            w[e1.ss]/=2;
            ll dx=w[e1.ss]-w[e1.ss]/2;
            e1.ff=dx*cnt[e1.ss];
            w[e2.ss]/=2;
            dx=w[e2.ss]-w[e2.ss]/2;
            e2.ff=dx*cnt[e2.ss];
            s[1].insert(e2);
            ans+=2;
        }
        else
        {
            s[1].erase(e4);
            s[1].insert(e1);
            s[2].erase(e3);
            cur-=e3.ff;
            w[e3.ss]/=2;
            ll dx=w[e3.ss]-w[e3.ss]/2;
            e3.ff=dx*cnt[e3.ss];
            s[2].insert(e3);
            ans+=2;
            if(cur+ret<=sum)
            {
                ans--;
            }
        }
        // trace(cur);
        // if(num==7)
        // {
        //     cur=sum;
        // }
    }
    cout<<ans<<endl;
        

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
    cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}