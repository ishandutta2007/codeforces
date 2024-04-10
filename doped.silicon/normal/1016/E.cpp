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
#define inf 1000000000
#define MOD  998244353
// #define EPS 1e-7
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

ld y;
ll a,b;
pair<ld,ld> find(ld xx,ld yy)
{
    return {a-y*(a-xx)*1.0/(y-yy),b-y*(b-xx)*1.0/(y-yy)};
}

vector<pair<ll,ll>>v;
// ld find(ld x)
// {
//     pair<pair<ld,ld>,ld> bt=mp(mp(x,x),0);
//     auto z1=upper_bound(v.begin(),v.end(),bt);
//     if(z1==v.begin())
//     {
//         return 0;
//     }
//     z1--;
//     auto z=*z1;
//     if(z.ff.ss<=x)
//     {
//         return z.ss+z.ff.ss-z.ff.ff;
//     }
//     return z.ss+x-z.ff.ff;
// }
ld ans[400005];
ll yx[200005];
vector<pair<ld,ll>>vx;
void solve()
{
    cin>>y;
    cin>>a>>b;
    ll n;
    cin>>n;
    rep(i,n)
    {
        ll x,yz;
        cin>>x>>yz;
        v.pb(mp(x,yz));
    }   
    sort(all(v));
    ll q;
    cin>>q;
    rep(i,q)
    {
        ll xx,yy;
        cin>>xx>>yy;
        yx[i]=yy;
        auto z=find(xx,yy);
        vx.pb(mp(z.ff,2*i));
        vx.pb(mp(z.ss,2*i+1));
        // ld x1=z.ff;
        // ld x2=z.ss;
        // ld bt=find(x2)-find(x1);
        // bt=bt*(yy-y)/yy;
        // cout<<bt<<endl;
    }
    sort(all(vx));
    ll i=0;
    ll s=0;
    for(auto z:vx)
    {
        while(i<n&&v[i].ff<z.ff)
        {
            s+=v[i].ss-v[i].ff;
            i++;
        }
        if(i!=0)
        {
            ans[z.ss]=s;
            if(v[i-1].ss>z.ff)
            {
                ans[z.ss]-=(v[i-1].ss-z.ff);
            }
        }
    }
    rep(i,q)
    {
        cout<<(ans[i*2+1]-ans[i*2])*(yx[i]-y)/yx[i]<<endl;
    }


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
        // cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    end_routine();
}