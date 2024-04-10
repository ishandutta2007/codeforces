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

ll mat[1000006][3];
ll dp[16][2];
void solve()
{
    ll n,m;
    cin>>n>>m;
    if(n>=4&&m>=4)
    {
        cout<<"-1"<<endl;
        return;
    }
    // trace(n,m);
    if(m>n)
    {
        rep(i,n)
        {
            rep(j,m)
            {
                char ch;
                cin>>ch;
                mat[j][i]=ch-'0';
            }
        }
        swap(n,m);
    }
    else
    {
        rep(i,n)
        {
            rep(j,m)
            {
                // trace(i,j);
                char ch;
                cin>>ch;
                mat[i][j]=ch-'0';
            }
        }
    }
    if(m==1)
    {
        cout<<"0";
        return;
    }
    rep(i,16)
    {
        rep(j,2)
        {
            dp[i][j]=0;
        }
    }
    vector<ll>a1,a2;
    rep(j,(1<<m))
    {
        rep(k,(1<<m))
        {
            ll j1=j;
            vector<ll>v1,v2;
            rep(xx,m)
            {
                v1.pb(j1%2);
                j1/=2;
            }
            j1=k;
            rep(xx,m)
            {
                v2.pb(j1%2);
                j1/=2;
            }
            ll han=0;
            // trace(k,j);
            // trace(v1,v2);
            rep(xx,m-1)
            {
                if((v1[xx]+v1[xx+1])%2==(v2[xx]+v2[xx+1])%2)
                {
                    // trace(xx);
                    // trace(v1[xx]+v1[xx+1]);
                    // trace(v1[xx]+v2[xx+1]);
                    han=1;
                    break;
                }
            }
            if(!han)
            {
                // trace(j,k);
                a1.pb(j);
                a2.pb(k);
                // a1.pb(k);
                // a2.pb(j);
            }
        }
    }
    rep(i,n)
    {
        rep(j,16)
        {
            dp[j][1]=INF;
        }
        rep(j,a1.size())
        {
            ll c=0;
            ll x=a1[j];
            ll y=a2[j];
            rep(k,m)
            {
                if(y%2!=mat[i][k])
                {
                    c++;
                }
                y/=2;
            }
            y=a2[j];
            dp[y][1]=min(dp[y][1],dp[x][0]+c);
        }
        rep(j,16)
        {
            dp[j][0]=dp[j][1];
            // trace(dp[j][0],j);
        }
    }
    ll ans=INF;
    rep(i,16)
    {
        ans=min(ans,dp[i][0]);
    }
    cout<<ans;


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