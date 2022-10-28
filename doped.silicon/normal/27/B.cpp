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
#define PI 3.1415926535897932385
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
#define rand(l, r) uniform_int_distribution<int>(l, r)(rng32)
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }

ld modp(ld b, ll e) {
    ld ans=1; for(;e;b=b*b,e/=2) if(e&1) ans=ans*b; return ans; }

ll n,m,k;
ll dp[1005][1005];
map<ll,ll>mx,my;
vector<ll>vx,vy;
vector<pair<ll,ll>>v;
vector<pair<pair<ll,ll>,pair<ll,ll>>>vz;

bool check(ll mid)
{
    rep(i,1005)
    {
        rep(j,1005)
        {
            dp[i][j]=0;
        }
    }
    mx.clear(),my.clear();
    vz.clear();
    vx.clear(),vy.clear();
    mx[0]=my[0]=mx[n+1]=my[m+1]=mx[1]=my[1]=0;
    for(auto z:v)
    {
        vz.pb(mp(mp(max(1ll,z.ff-mid),min(n,z.ff+mid)),mp(max(1ll,z.ss-mid),min(m,z.ss+mid))));
    }
    for(auto z:vz)
    {
        // trace(z.ff);
        mx[z.ff.ff]=mx[z.ff.ss+1]=my[z.ss.ff]=my[z.ss.ss+1]=0;
    }
    ll cur=0;
    for(auto &z:mx)
    {
        // cout<<z.ff<<endl;
        z.ss=cur++;
        vx.pb(z.ff);
    }
    cur=0;
    for(auto &z:my)
    {
        z.ss=cur++;
        vy.pb(z.ff);
    }
    for(auto &z:vz)
    {
        // trace(z.ff,z.ss);
        z.ff.ff=mx[z.ff.ff];
        z.ff.ss=mx[z.ff.ss+1];
        z.ss.ss=my[z.ss.ss+1];
        z.ss.ff=my[z.ss.ff];
        // trace(z.ff,z.ss);
        dp[z.ff.ff][z.ss.ff]+=1;
        dp[z.ff.ff][z.ss.ss]-=1;
        dp[z.ff.ss][z.ss.ss]+=1;
        dp[z.ff.ss][z.ss.ff]-=1;
    }
    ll maxx=-MOD,maxy=-MOD;
    ll minx=MOD,miny=MOD;
    for(int i=1;i<vx.size()-1;i++)
    {
        for(int j=1;j<vy.size()-1;j++)
        {
            dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
            if(dp[i][j]==0)
            {
                minx=min(minx,vx[i]);
                miny=min(miny,vy[j]);
                maxx=max(maxx,vx[i+1]-1);
                maxy=max(maxy,vy[j+1]-1);
            }
        }
    }
    return (maxx-minx)<=2*mid&&(maxy-miny)<=2*mid;
}

ll w[55];
ll cnt[55];
void solve() 
{   
    ll n;
    cin>>n;
    rep(i,n*(n-1)/2-1)
    {
        ll x,y;
        cin>>x>>y;
        cnt[x]++;
        cnt[y]++;
        w[x]++;
    }
    ll a=0,b=0;
    rep(i,n)
    {
        if(cnt[i+1]!=n-1&&a==0)
        {
            a=i+1;
        }
        else if(cnt[i+1]!=n-1)
        {
            b=i+1;
        }
    }
    if(w[a]<w[b])
    {
        swap(a,b);
    }
    cout<<a<<' '<<b<<endl;



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
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}