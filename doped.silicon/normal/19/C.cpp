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
#define endl '\n'
#define trace(...)
#define end_routine()
#endif

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) { return fabs(a - b) < 1e-9; }
ll modpow(ll b, ll e, ll mod=MOD) {
    ll ans=1; for(;e;b=b*b%mod,e/=2) if(e&1) ans=ans*b%mod; return ans; }



int n;
vector<ll>s;
int SortIndex[20][500005];   
int suf[500005]; 
int c[500005]; 
 
struct suffix
{
    int nr[2], p;
};
 
bool operator < (suffix a, suffix b) 
{
    return a.nr[0] < b.nr[0] || (a.nr[0] == b.nr[0] && a.nr[1] < b.nr[1]);
}
 
suffix tmp[500005], ttmp[500005];
 
void counting_sort(int r) 
{
    int maxi = n > 300 ? n : 300;
    memset(c, 0, sizeof c);
 
    rep(i, n) c[tmp[i].nr[r]+1]++;
    for(int i = 0, sum = 0; i <= maxi; i++) {
        int t = c[i]; 
        c[i] = sum; 
        sum += t;
    }
    rep(i, n) ttmp[c[tmp[i].nr[r]+1]++] = tmp[i];
    rep(i, n) tmp[i] = ttmp[i];
}
 
int stp, doneTill; 
 
void suffix_array() {
    n = s.size();
    int mn = *min_element(s.begin(), s.end());
    rep(i, n) SortIndex[0][i] = s[i] - mn;
  
    for(stp = 1, doneTill = 1; doneTill < n; doneTill <<= 1, stp++) {
        rep(i, n) {
            tmp[i].p = i;
            tmp[i].nr[0] = SortIndex[stp-1][i];
            tmp[i].nr[1] = i + doneTill < n ? SortIndex[stp-1][i+doneTill] : -1;
        }
        sort(tmp, tmp + n);
    
        rep(i, n)
            SortIndex[stp][tmp[i].p] = (i > 0 && tmp[i-1].nr[0] == tmp[i].nr[0] &&\
                tmp[i-1].nr[1] == tmp[i].nr[1]) ? SortIndex[stp][tmp[i-1].p] : i;
    }
 
    rep(i, n) suf[SortIndex[stp-1][i]] = i ;
}

int lcp(int x, int y)
{
    if(x == y)
        return n-x;
    int ans = 0;
  
    for(int k = stp-1; x < n && y < n && k >= 0; k--)
    {
        if(SortIndex[k][x] == SortIndex[k][y]) 
        {
            ans += 1 << k; 
            x += 1 << k;   
            y += 1 << k;   
        }
    }
    return ans;
}
 
map<ll,vector<ll>>m;
vector<pair<ll,ll>>del;
void solve()
{
    ll n;
    cin>>n;
    // vector<ll>v;
    rep(i,n)
    {
        ll x;
        cin>>x;
        m[x].pb(i);
        s.pb(x);
    }
    // v.pb(-1);
    suffix_array();
    // findmin(0,1);
    for(auto z:m)
    {
        vector<ll>vx=z.ss;
        rep(i,vx.size())
        {
            for(int j=i+1;j<vx.size();j++)
            {
                if(lcp(vx[i],vx[j])>=vx[j]-vx[i])
                {
                    del.pb(mp(vx[j]-vx[i],vx[i]));
                }
            }
        }
    }
    sort(all(del));
    ll ans=0;
    for(auto z:del)
    {
        // trace(z);
        if(ans<=z.ss)
        {
            ans=z.ss+z.ff;
        }
    }
    cout<<n-ans<<endl;
    for(int i=ans;i<n;i++)
    {
        cout<<s[i]<<' ';
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
    fr(i,1,t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    end_routine();
}