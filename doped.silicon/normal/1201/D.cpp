// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#ifndef bhartiya
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

ll l[200005];
ll r[200005];
vector<ll>clo[200005];
void solve() 
{
    ll n,m,k,q;
    cin>>n>>m>>k>>q;
    rep(i,200001)
    {
        l[i]=INF;
        r[i]=-1;
    }
    rep(i,k)
    {
        ll x,y;
        cin>>x>>y;
        l[x]=min(l[x],y);
        r[x]=max(r[x],y);
    }
    ll c=0;
    vector<ll>v;
    rep(i,q)
    {
        ll x;
        cin>>x;
        v.pb(x);
    }
    sort(all(v));
    ll last=-1;
    ll j=0;
    for(ll i=1;i<=m;i++)
    {
        // trace(v[j],i);
        if(j<q&&v[j]==i)
        {
            last=i;
            j++;
        }
        // trace(last);
        if(last!=-1)
        {
            // trace(i,last);
            clo[i].pb(last);
        }
    }
    j=q-1;
    last=-1;
    for(ll i=m;i>=1;i--)
    {
        if(j>=0&&v[j]==i)
        {
            last=i;
            j--;
        }
        if(last!=-1&&i!=last)
            clo[i].pb(last);
    }
    vector<pair<ll,ll>>vx;
    ll ans=0;
    if(r[1]!=-1)
    {
        ans=r[1]-1;
        vx.pb(mp(r[1],r[1]-1));
    }
    else
        vx.pb(mp(1,0));
    ll bt=0;
    for(ll i=2;i<=n;i++)
    {
        vector<ll>lx,rx;
        vector<pair<ll,ll>>v1;
        // for(auto x:vx)
        // {
        //     trace(x);
        // }
        // cout<<endl;
        for(auto x:vx)
        {
            for(auto z:clo[x.ff])
            {
                v1.pb(mp(z,x.ss+abs(z-x.ff)));
            }
        }
        vx=v1;
        // for(auto x:vx)
        // {
        //     trace(x);
        // }
        // cout<<endl;
        bt++;
        if(r[i]!=-1)
        {
            for(auto &x:vx)
            {
                x.ss+=bt;
                lx.pb(x.ss+(r[i]-l[i])+abs(r[i]-x.ff));
                rx.pb(x.ss+(r[i]-l[i])+abs(l[i]-x.ff));
            }
            sort(all(lx));
            sort(all(rx));
            ll xx=INF;
            vx.clear();
            vx.pb(mp(l[i],lx[0]));
            vx.pb(mp(r[i],rx[0]));
            xx=min(lx[0],rx[0]);
            ans=xx;
            bt=0;
        }
    }
    cout<<ans<<endl;

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
    // cin>>t;
    fr(i,1,t)
    {
        solve();
    }
    end_routine();
}