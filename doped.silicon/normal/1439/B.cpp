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








set<pair<ll,ll>>s;
vector<ll>v[100005];
set<ll>adj[100005];
ll cnt[100005];
ll han[100005];
void solve()
{   
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    ll k;
    cin>>k;
    s.clear();
    for(int i=1;i<=n;i++)
    {
        v[i].clear();
        cnt[i]=0;
        han[i]=0;
        adj[i].clear();
    }
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        cnt[x]++;
        cnt[y]++;
    }
    if(k > 500) {
       cout << -1 << endl;
       return;
    }
    
    
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>=k-1)
        {
            s.insert(mp(cnt[i],i));
            han[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(han[i]==0)
        {
            for(auto z:v[i])
            {
                if(han[z])
                {
                    s.erase(mp(cnt[z],z));
                    cnt[z]--;
                    s.insert(mp(cnt[z],z));
                }
            }
        }
        else
        {
            for(auto z:v[i])
            {
                if(han[z])
                {
                    adj[i].insert(z);
                }
            }
        }
    }

    while(!s.empty())
    {
        auto z=*s.begin();
        if(z.ff<k-1)
        {
            s.erase(z);
            for(auto x:adj[z.ss])
            {
                s.erase(mp(cnt[x],x));
                adj[x].erase(z.ss);
                cnt[x]--;
                s.insert(mp(cnt[x],x));
            }
        }
        else if(z.ff==k-1)
        {
            vector<ll>vx;
            for(auto x:adj[z.ss])
            {
                vx.pb(x);
            }
            ll han=1;
            rep(i,vx.size())
            {
                for(int j=i+1;j<vx.size();j++)
                {
                    if(adj[vx[i]].find(vx[j])==adj[vx[i]].end())
                    {
                        han=0;
                        break;
                    }
                }
                if(!han)
                {
                    break;
                }
            }
            if(han)
            {
                cout<<"2"<<endl;
                cout<<z.ss<<' ';
                for(auto z:vx)
                {
                    cout<<z<<' ';
                }
                cout<<endl;
                return;
            }
            else
            {
                for(auto x:adj[z.ss])
                {
                    s.erase(mp(cnt[x],x));
                    adj[x].erase(z.ss);
                    cnt[x]--;
                    s.insert(mp(cnt[x],x));
                }
            }
            s.erase(z);
        }
        else
        {
            cout<<"1 "<<s.size()<<endl;
            for(auto z:s)
            {
                cout<<z.ss<<' ';
            }
            cout<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;

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