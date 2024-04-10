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
#define mp make_pair

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


ll mat[2005][2005];
ll rx[2005][10];
ll rn[2005][10];
ll cx[2005][10];
ll cn[2005][10];
ll xr[10],nr[10],xc[10],nc[10];
ll ans[10];
void solve()
{   
    ll n;
    cin>>n;
    rep(i,n)
    {
        rep(j,10)
        {
            rx[i][j]=-10000;
            cx[i][j]=-10000;
            rn[i][j]=100000;
            cn[i][j]=10000;
            xr[j]=-100000;
            xc[j]=-100000;
            nr[j]=100000;
            nc[j]=100000;
            ans[j]=0;
        }

    }
    rep(i,n)
    {
        string s;
        cin>>s;
        rep(j,n)
        {
            mat[i][j]=s[j]-'0';
            ll x=s[j]-'0';
            rx[i][x]=max(rx[i][x],j);
            rn[i][x]=min(rn[i][x],j);
            cn[j][x]=min(cn[j][x],i);
            cx[j][x]=max(cx[j][x],i);
            xr[x]=max(xr[x],i);
            nr[x]=min(nr[x],i);
            xc[x]=max(xc[x],j);
            nc[x]=min(nc[x],j);
        }
    }
    for(int i=0;i<n;i++)
    {
        rep(j,10)
        {
            ll z=rx[i][j]-rn[i][j];
            ans[j]=max(ans[j],z*max(i,n-1-i));
            ll x=max(xr[j]-i,i-nr[j]);
            x=max(x,0ll);
            if(rn[i][j]<n)
            {
                ans[j]=max(ans[j],x*rn[i][j]);
                ans[j]=max(ans[j],x*(n-1-rn[i][j]));

            }
            if(rx[i][j]>=0)
            {
                ans[j]=max(ans[j],x*(n-1-rx[i][j]));
                ans[j]=max(ans[j],x*(rx[i][j]));
            }
        }
        // trace(ans[0]);
        rep(j,10)
        {
            ll z=cx[i][j]-cn[i][j];
            ans[j]=max(ans[j],z*max(i,n-1-i));
            ll x=max(xc[j]-i,i-nc[j]);
            // if(j==3)
            // {
            //     trace(z,ans[3],x,nc[3],xc[3],cn[i][j],cx[i][j]);
            // }
            x=max(x,0ll);
            if(cn[i][j]<n)
            {
                ans[j]=max(ans[j],x*cn[i][j]);
                ans[j]=max(ans[j],x*(n-1-cn[i][j]));

            }
            if(cx[i][j]>=0)
            {
                ans[j]=max(ans[j],x*(n-1-cx[i][j]));
                ans[j]=max(ans[j],x*(cx[i][j]));

            }
        }
    }
    rep(i,10)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    

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