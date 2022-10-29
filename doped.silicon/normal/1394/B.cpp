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

bool han[15][15][15][15];
vector<pair<ll,ll>>v[200005];
set<pair<ll,ll>>xx[200005];
ll val[10];
void solve()
{
    rep(i,15)
    {
        rep(j,15)
        {
            rep(k,15)
            {
                rep(z,15)
                {
                    han[i][j][k][z]=1;
                }
            }
        }
    }
    ll n,m,k;
    cin>>n>>m>>k;
    rep(i,10)
    {
        val[i]=1;
    }
    rep(i,m)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        v[x].pb(mp(z,y));
    }
    for(ll i=1;i<=n;i++)
    {
        sort(all(v[i]));
        ll x=v[i].size();
        rep(j,x)
        {
            if(xx[v[i][j].ss].find(mp(x,j+1))!=xx[v[i][j].ss].end())
            {
                han[x][j+1][x][j+1]=0;
            }
            else
            {
                for(auto z:xx[v[i][j].ss])
                {
                    han[x][j+1][z.ff][z.ss]=0;
                    han[z.ff][z.ss][x][j+1]=0;
                }
                xx[v[i][j].ss].insert(mp(x,j+1));
            }
        }
    }
    ll ans=0;
    while(val[1]==1)
    {
        // rep(i,k)
        // {
        //     trace(i+1,val[i+1]);
        // }
        // cout<<endl;
        ll h=1;
        for(ll i=1;i<=k;i++)
        {
            for(ll j=i;j<=k;j++)
            {
                if(han[i][val[i]][j][val[j]]==0)
                {
                    // trace(i,j);
                    h=0;
                    break;
                }
            }
        }
        // if(h)
        // {
        //     rep(i,k)
        //     {
        //         trace(i+1,val[i+1]);
        //     }
        //     cout<<endl;
        // }
        ans+=h;
        for(ll i=k;i>=1;i--)
        {
            val[i]++;
            if(val[1]==2)
            {
                break;
            }
            if(val[i]>i)
            {
                val[i]=1;
            }
            else
            {
                break;
            }
        }
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
    // cin>>t;
    fr(i,1,t)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}