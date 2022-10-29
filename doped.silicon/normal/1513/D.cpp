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
// #define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

const ll n1=200006;//size of segment tree
ll st[n1*4];
ll ar[n1]; 
ll d[n1];
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        st[v]=ar[tl];
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        st[v]=__gcd(st[2*v],st[2*v+1]);
    }
}
ll query_l(ll v,ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
    {
        return -1;
    }
    else if(tl==l&&tr==r&&st[v]%x==0)
    {
        return r;
    }
    else if(tl==tr&&tl==l&&tr==r&&st[v]%x!=0)
    {
        return -1;
    }
    else
    {
        ll tm=(tl+tr)/2;
        ll z=query_l(2*v,tl,tm,l,min(tm,r),x);
        // trace(tl,tm,l,min(tm,r),x,z,st[2*v]%x);
        if(z==tm||l>tm)
        {
            z=query_l(2*v+1,tm+1,tr,max(l,tm+1),r,x);
            return max(tm,z);
        }
        else
        {
            return max(l-1,z);
        }
    }
}
ll query_r(ll v,ll tl,ll tr,ll l,ll r,ll x)
{
    if(l>r)
    {
        return INF;
    }
    else if(tl==l&&tr==r&&st[v]%x==0)
    {
        return l;
    }
    else if(tl==tr&&tl==l&&st[v]%x!=0)
    {
        return INF;
    }
    else
    {
        ll tm=(tl+tr)/2;
        ll z=query_r(2*v+1,tm+1,tr,max(l,tm+1),r,x);
        // trace(tm+1,tr,max(l,tm+1),r,z,x);
        if(z==tm+1||r<=tm)
        {
            z=query_r(2*v,tl,tm,l,min(tm,r),x);
            // trace(tl,tm,l,min(tm,r),z,x);
            return min(tm+1,z);
        }
        else
        {
            return min(r+1,z);
        }
    }
}
void solve()
{
    ll n,p;
    cin>>n>>p;
    vector<pair<ll,ll>>v;
    rep(i,n)
    {
        cin>>ar[i];
        v.pb(mp(ar[i],i));
        d[i]=0;
    }
    build(1,0,n-1);
    sort(all(v));
    ll ans=0;
    ll xx=n-1;
    for(auto z:v)
    {
        if(d[z.ss]!=0||z.ff>=p)
        {
            continue;
        }
        ll l=query_r(1,0,n-1,0,z.ss,z.ff);
        ll r=query_l(1,0,n-1,z.ss,n-1,z.ff);
        ll c=-1;
        xx++;
        for(int j=z.ss;j<=r;j++)
        {
            if(d[j])
            {
                c++;
                xx--;
                break;
            }
            c++;
            xx--;
            d[j]=z.ff;
            // trace(c,j);
        }
        // trace(z.ss,c,xx);
        for(int j=z.ss-1;j>=l;j--)
        {
            if(d[j])
            {
                c++;
                xx--;
                break;
            }
            c++;
            xx--;
            d[j]=z.ff;
        }
        // trace(c,xx);
        // trace(l,r,z.ff,z.ss);
        ans+=c*z.ff;

    }
    // trace(xx);
    ans+=xx*p;
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
    cin>>t;
    
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}