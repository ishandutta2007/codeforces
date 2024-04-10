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




vector<pair<ll,ll>>v[1000005];
ll cost[2005];
ll yx[1000005];
ll xx[1000005];
vector<pair<ll,ll>>r;
vector<pair<ll,ll>>ly;
vector<pair<ll,ll>>lx;
vector<ll>upd[1000005];
vector<ll>ux[1000005];
void solve()
{
    ll n,m;
    cin>>n>>m;
    rep(i,n)
    {
        ll x,y;
        cin>>x>>y;
        r.pb(mp(x,y));
    }
    multiset<ll>s;
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        s.insert(x);
        lx.pb(mp(x,y));
        ly.pb(mp(y,x));
    }
    sort(all(lx));
    sort(all(ly));
    ll cur=0;
    ll mx=*s.rbegin();
    s.insert(0);
    rep(i,1000005)
    {
        while(cur<m&&ly[cur].ff<i)
        {
            s.erase(s.find(ly[cur].ss));
            cur++;
            mx=*s.rbegin();
        }
        xx[i]=mx;
    }
    // trace(n);
    cur=0;
    rep(i,m)
    {
        s.insert(lx[i].ss);
    }
    mx=*s.rbegin();
    s.insert(0);
    rep(i,1000005)
    {
        while(cur<m&&lx[cur].ff<i)
        {
            s.erase(s.find(lx[cur].ss));
            cur++;
            mx=*s.rbegin();
        }
        // trace(mx);
        yx[i]=mx;
    }
    ll ans=0;
    // trace(ans);
    multiset<ll>c;
    rep(i,n)
    {
        upd[yx[r[i].ff]+1].pb(i);
        ll xz=max(xx[r[i].ss]-r[i].ff+1,0ll);
        cost[i]=xz;
        // trace(xz);
        c.insert(xz);
    }
    ans=*c.rbegin();
    // cout<<ans<<endl;
    cur=0;
    rep(i,n)
    {
        for(auto x:ly)
        {
            if(x.ff>=r[i].ss)
            {
                // trace(i,x.ff-r[i].ss+1);
                ux[x.ff-r[i].ss+1].pb(i);
            }
        }
    }
    rep(i,1000005)
    {
        // trace(i);
        for(auto z:upd[i])
        {
            // trace(i,z);
            c.erase(c.find(cost[z]));
            cost[z]=0;
            c.insert(0);
        }
        ll bt=0;
        while(cur<m&&lx[cur].ff<i)
        {
            cur++;
            bt=1;
        }
        {
            for(auto j:ux[i])
            {
                // trace
                ll bx=cost[j];
                ll btx=max(xx[r[j].ss+i]-r[j].ff+1,0ll);
                cost[j]=min(cost[j],btx);
                if(bx!=cost[j])
                {
                    c.erase(c.find(bx));
                    c.insert(cost[j]);
                }
            }
        }
        // trace(i,*c.rbegin());
        ans=min(ans,*c.rbegin()+i);

    }
    cout<<ans<<endl;

     
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