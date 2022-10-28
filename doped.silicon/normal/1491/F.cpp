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


ll ar[2005];
ll ans[2005];

void solve()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ar[i]=i;
        ans[i]=0;
    }
    shuffle(ar+1,ar+n+1,rng32);
    ll l=1,r=1;
    ll x=0;
    for(int i=2;i<=n;i++)
    {
        cout<<"? "<<i-1<<' '<<1<<endl;
        rep(j,i-1)
        {
            cout<<ar[j+1]<<' ';
        }
        cout<<endl;
        cout<<ar[i]<<endl;
        ll z;
        cin>>z;
        if(z!=0)
        {
            x=i;
            break;
        }
        r=i;
    }
    while(l<r)
    {
        ll m=(l+r)/2;
        cout<<"? "<<m-l+1<<' '<<1<<endl;
        for(int j=l;j<=m;j++)
        {
            cout<<ar[j]<<' ';
        }
        cout<<endl;
        cout<<ar[x]<<endl;
        ll z;
        cin>>z;
        if(z!=0)
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    ll cnt=2;
    ans[ar[l]]=1;
    ans[ar[x]]=1;
    for(int i=x+1;i<=n;i++)
    {
        cout<<"? 1 1"<<endl;
        cout<<ar[i]<<endl;
        cout<<ar[x]<<endl;
        ll z;
        cin>>z;
        if(z!=0)
        {
            ans[ar[i]]=1;
            cnt++;
        }
    }
    cout<<"! "<<n-cnt<<' ';
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            cout<<i<<' ';
        }
    }
    cout<<endl;





}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
#ifdef bhartiya
    // cin.exceptions(cin.failbit);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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