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

#define INF 100000000000005ll
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

vector<ll>v[10];
ll fin[100000][10];
ll dp[2005][2005];
ll hg[2005][2005];
void f(ll x,ll y)
{
    rep(j,7)
    {
        if((1<<j)&y)
        {
            ll han=1;
            for(auto z:v[x])
            {
                if(z==j+1)
                {
                    han=0;
                }
            }
            if(han)
            {
                fin[y][x]=2003;
                return;
            }
        }
    }
    fin[y][x]=v[x].size()-bitc(y);
}
void solve() 
{
    ll n,k;
    cin>>n>>k;
    rep(i,(1<<7))
    {
        rep(j,10)
        {
            f(j,i);
        }
    }
    ll cnt=0;
    ll han=1;
    rep(i,2005)
    {
        rep(j,2005)
        {
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=1;
    vector<ll>vx;
    rep(i,n)
    {
        string s;
        cin>>s;
        ll x=0;
        rep(j,7)
        {
            if(s[j]=='1')
            {
                x+=(1<<j);
                cnt++;
                if(j==3)
                {
                    han=0;
                }
            }
        }
        vx.pb(x);
        
    }
    reverse(all(vx));
    rep(i,n)
    {
        ll x=vx[i];
        rep(j,10)
        {
            if(fin[x][j]<=2000)
            {
                for(ll xx=0;xx<=k-fin[x][j];xx++)
                {
                    dp[i+1][xx+fin[x][j]]=max(dp[i+1][xx+fin[x][j]],dp[i][xx]);
                }
            }
        }
    }
    if(dp[n][k]<0)
    {
            cout<<"-1";
            return;
    }
    // reverse(all(v));
    for(ll i=n-1;i>=0;i--)
    {
        ll x=vx[i];
        for(ll j=9;j>=0;j--)
        {
            if(k>=fin[x][j]&&dp[i][k-fin[x][j]]>=0)
            {
                cout<<j;
                k-=fin[x][j];
                break;
            }
        }
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
    int t=1;
    // cin>>t;
    rep(i,7)
    {
        v[8].pb(i+1);
        if(i!=3)
        {
            v[0].pb(i+1);
        }
        if(i!=2)
        {
            v[6].pb(i+1);
        }
        if(i!=4)
        {
            v[9].pb(i+1);
        }
        if(i!=1&&i!=5)
        {
            v[2].pb(i+1);
        }
        if(i!=1&&i!=4)
        {
            v[3].pb(i+1);
        }
        if(i!=0&&i!=4&&i!=6)
        {
            v[4].pb(i+1);
        }
        if(i!=2&&i!=4)
        {
            v[5].pb(i+1);
        }

    }
    v[1].pb(3);
    v[1].pb(6);
    v[7].pb(1);
    v[7].pb(3);
    v[7].pb(6);
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}