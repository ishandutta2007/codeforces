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

// #define int long long
typedef int ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
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
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }


pair<ll,ll> st[3005][4*2600];

ll ar[3005];
ll an[3005];
void build(ll v,ll tl,ll tr,ll x)
{
    if(tl==tr)
    {
        st[x][v]={ar[tl],tl};
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,x);
        build(2*v+1,tm+1,tr,x);
        st[x][v]=max(st[x][2*v],st[x][2*v+1]);
    }
}

pair<ll,ll> query(ll v,ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
    {
        return {-10000,0};
    }
    if(tl==l&&tr==r)
    {
        return st[x][v];
    }
    ll tm=(tl+tr)/2;
    return max(query(2*v,tl,tm,l,min(r,tm),x),query(2*v+1,tm+1,tr,max(l,tm+1),r,x));
}


void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>vx;
    rep(i,n)
    {
        ll x;
        cin>>x;
        vx.pb(x,i);
    }
    sort(all(vx));
    vector<ll>v;
    rep(i,n)
    {
        v.pb(vx[i].ff);
    }
    for(ll i=0;i<n;i++)
    {
        ar[i+1]=v[0];
        for(ll j=1;j<i+1;j++)
        {
            ar[j]=v[i-j+1]-v[i-j];
        }
        for(ll j=i+2;j<=n;j++)
        {
            ar[j]=-10000;
        }
        build(1,1,n,i);
    }
    pair<pair<ll,ll>,ll>ans;
    ans={{0,0},0};
    ll a=0,b=0,c=0;
    for(ll jx=n-1;jx>=0;jx--)
    {
        ll x=n-jx;
        for(ll i=jx-1;i>0;i--)
        {
            ll y=jx-i;
            if(2*x<y||2*y<x)
            {
                continue;
            }
            // cout<<x<<' '<<y<<endl;
            ll r=min(2*x,2*y);
            ll l=max((x+1)/2,(y+1)/2);
            if(l<=r)
            {
                auto z1=query(1,1,n,l,r,i-1);
                ll z=z1.ss;
                // trace(i,z1);
                if(z1.ff>=0)
                {
                    pair<pair<ll,ll>,ll> xx={{v[jx]-v[jx-1],v[i]-v[i-1]},z1.ff};
                    // if(xx.ff.ff==0||xx.ff.ss==0)
                    // {
                    //     continue;
                    // }
                    // if(xx.ss==0&&x+y+z!=n)
                    // {
                    //     continue;
                    // }
                    // trace(xx.ff);
                    if(xx>ans)
                    {
                        ans=xx;
                        a=x;
                        b=y;
                        c=z;
                    }
                    // trace(a,b,c);
                }
            }
        }
    }
    ll cur=n-1;
    for(ll i=cur;cur-i<a;i--)
    {
        an[vx[i].ss]=1;
    }
    cur-=a;
    for(ll i=cur;cur-i<b;i--)
    {
        an[vx[i].ss]=2;
    }
    cur-=b;
    for(ll i=cur;cur-i<c;i--)
    {
        an[vx[i].ss]=3;
    }
    cur-=c;
    for(ll i=cur;i>=0;i--)
    {
        an[vx[i].ss]=-1;
    }
    rep(i,n)
    {
        cout<<an[i]<<' ';
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
    // cin>>tx;
    fr(i,1,tx)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}