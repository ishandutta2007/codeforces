// clang-format off
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef ONLINE_JUDGE
#define bhartiya
#endif

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
 
#define INF 4557430888798830399ll
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
// clang-format on
ll ar[2005][26];
ll tt[2005][26];
ll dp[2005][2005];
ll n;

string s,t;
ll find(ll x,ll y)
{
    // trace(x,y);
    if(x==-1)
    {
        return 0;
    }
    if(x<=-1||y<=-1)
    {
        return INF;
    }
    ll &ans=dp[x][y];
    if(ans!=-1)
    {
        return ans;
    }
    ans=INF;
    if(s[x]==t[y])
    {
        ans=min(ans,find(x-1,y-1));
    }
    if(ar[x+1][t[y]-'a']>tt[y+1][t[y]-'a'])
    {
        ans=min(ans,find(x,y-1));
    }
    ans=min(ans,1+find(x-1,y));

    return ans;
}

void solve() 
{
    cin>>n;
    cin>>s>>t;
    rep(i,26)
    {
        rep(j,n+5)
        {
            ar[j][i]=0;
            tt[j][i]=0;
        }
    }
    rep(i,n+5)
    {
        rep(j,n+5)
        {
            dp[i][j]=-1;
        }
    }
    for(ll i=n-1;i>=0;i--)
    {
        rep(j,26)
        {
            ar[i][j]=ar[i+1][j];
        }
        ar[i][s[i]-'a']++;
    }
    for(ll i=n-1;i>=0;i--)
    {
        rep(j,26)
        {
            tt[i][j]=tt[i+1][j];
        }
        tt[i][t[i]-'a']++;
    }
    rep(i,26)
    {
        if(ar[0][i]!=tt[0][i])
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<find(n-1,n-1)<<endl;

}   
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    // cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t; 
    fr(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}