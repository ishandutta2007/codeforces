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


ll dp[200005][30];
pair<ll,ll> d[200005][2];
vector<ll>v[200005][2];
void solve()
{
    rep(i,200005)
    {
        rep(j,30)
        {
            dp[i][j]=INF;
        }
        d[i][0]={INF,INF};
        d[i][1]={INF,INF};
    }
    ll n,m;
    cin>>n>>m;
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x][0].pb(y);
        v[y][1].pb(x);
    }
    priority_queue<pair<ll,pair<ll,ll>>>q;
    q.push(mp(0,mp(1,0)));
    dp[1][0]=0;
    ll ans=INF;
    while(!q.empty())
    {
        auto z=q.top();
        q.pop();
        z.ff*=-1;
        // trace(z.ff,z.ss);
        if(dp[z.ss.ff][z.ss.ss]<z.ff)
        {
            continue;
        }
        for(auto a:v[z.ss.ff][z.ss.ss%2])
        {
            ll c=(1+z.ff);
            ll b=z.ss.ss;
            if(dp[a][b]>c)
            {
                dp[a][b]=c;
                q.push(mp(-c,mp(a,b)));
            }
        }
        for(auto a:v[z.ss.ff][(z.ss.ss+1)%2])
        {
            ll c=(1+z.ff);
            ll b=z.ss.ss+1;
            if(dp[a][b]>c&&b<=29)
            {
                dp[a][b]=c;
                q.push(mp(-c,mp(a,b)));
            }
        }
    }
    rep(i,30)
    {
        ans=min(ans,dp[n][i]+(1<<i)-1);
    }
    if(ans!=INF)
    {
        cout<<ans<<endl;
        // trace("Sd");
        return;
    }
    set<pair<pair<ll,ll>,ll>>s;
    s.insert(mp(mp(0,0),1));
    while(!s.empty())
    {
        auto z=*s.begin();
        s.erase(z);
        ll a=z.ff.ff;
        ll b=z.ff.ss;
        if(d[z.ss][a%2]<z.ff)
        {
            continue;
        }
        for(auto x:v[z.ss][a%2])
        {
            if(d[x][a%2]>mp(a,b+1))
            {
                d[x][a%2]=mp(a,b+1);
                s.insert(mp(mp(a,b+1),x));
            }
        }
        ll x=z.ss;
        if(d[x][(a%2)^1]>mp(a+1,b))
        {
            d[x][(a%2)^1]=mp(a+1,b);
            s.insert(mp(mp(a+1,b),x));
        }
    }
    ans=INF;
    if(d[n][0]<d[n][1])
    {
        ans=(d[n][0].ss-1+modpow(2,d[n][0].ff,MOD)+MOD)%MOD;
    }
    else
        ans=(d[n][1].ss-1+modpow(2,d[n][1].ff,MOD)+MOD)%MOD;

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
        // vector<int>x={0,1,1};
        // vector<int>y={0,0,1};
        // SecondDiameters *a=new SecondDiameters();
        // ll ans=a->getSecondDiameters(x,y);
        // trace(ans);
        // trace(v);
    }
    end_routine();
}