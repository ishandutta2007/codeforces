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
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define INF 1000000000000000000ll
// #define MOD 2000000000000000000ll
#define MOD 998244353
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






ll l[2005];
ll r[2005];
ll ar[2005];
const ll n1=2015;
ll st[n1*4];
ll lazy[n1*4];
void push(ll v)
{
    if(lazy[v])
    {
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        st[2*v]+=lazy[v];
        st[2*v+1]+=lazy[v];
        lazy[v]=0;
    }
}
void upd(ll v,ll tl,ll tr,ll l,ll r,ll val)
{
    if(l>r)
    {
        return ;
    }
    if(tl==l&&tr==r)
    {
        st[v]+=val;
        lazy[v]+=val;
    }
    else
    {
        ll tm=(tl+tr)/2;
        push(v);
        upd(2*v,tl,tm,l,min(tm,r),val);
        upd(2*v+1,tm+1,tr,max(l,tm+1),r,val);
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
        if(x<=tm)
        {
            return query(2*v,tl,tm,x);
        }
        return query(2*v+1,tm+1,tr,x);
    }
}

void solve()
{   
    ll n,m,k;
    cin>>n>>m>>k;
    rep(i,m)
    {
        cin>>l[i]>>r[i];
    }
    ll ans=0;
    for(int i=1;i<=n-k+1;i++)
    {
        rep(j,n1*4)
        {
            st[j]=0;
            lazy[j]=0;
        }
        ll l1=i;
        ll r1=i+k-1;
        ll s=0;
        rep(j,m)
        {
            ar[j]=min(r1,r[j])-max(l[j],l1)+1; 
            ar[j]=max(0ll,ar[j]);
            s+=ar[j];
            // trace(ar[j]);
            if(ar[j]!=k&&ar[j]!=r[j]-l[j]+1)
            {
                // trace(j);
                ll st=l[j]-(k-ar[j]-1);
                if(st<=0)
                {
                    upd(1,0,n+5,0,0,min(1-st,r[j]-l[j]+1-ar[j]));
                    st=1;
                }
                ll k1=min(l[j],r[j]-k+1);
                upd(1,0,n+5,st,k1,1);
                // trace(st,k1);

                ll k2=max(l[j]+1,r[j]-k+2);
                ll en=r[j]-ar[j]+1;
                en=min(n,en);
                upd(1,0,n+5,k2,en,-1);
                // trace(k2,en);
            }
        }
        ans=max(ans,s);
        ll c=query(1,0,n+5,0);
        for(int j=1;j<=n-k+1;j++)
        {
            c+=query(1,0,n+5,j);
            ans=max(s+c,ans);
        }

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