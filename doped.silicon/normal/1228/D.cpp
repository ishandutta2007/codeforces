#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#ifndef bhartiya
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    // #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef gp_hash_table<int, int> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pii, int> piii;

typedef vector<int> vi;
typedef vector<pii> vii;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define INF 1000000000
#define MOD 1000000007
#define mod 1000000007
#define EPS 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)
#define ff first
#define ss second
 
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define all(ar) ar.begin(), ar.end()
#define sz(x) (int)(x).size()
 
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar,val) memset(ar, val, sizeof(ar))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

 
#ifdef bhartiya
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
#else
#define endl '\n'
#define trace(...)
#define end_routine()
#endif
 
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
inline bool equals(double a, double b) {return fabs(a - b) < 1e-9;}
int gcd(int a, int b){ return b==0 ? a : gcd(b, a%b); }
ll modpow(ll b, ll e) {
    ll ans=1; for(;e;b=b*b%MOD,e/=2) if(e&1) ans=ans*b%MOD; return ans;}
vector<ll>v[100005];
map<pair<ll,ll>,bool>m1;
void solve()
{
    ll n,m;
    cin>>n>>m;
    rep(i,m)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        m1[mp(x,y)]=1;
        m1[mp(y,x)]=1;
    }
    set<ll>s;
    rep(i,n)
    {
        s.insert(i+1);
    }
    vector<ll>v1,v2,v3;
    for(auto x:v[1])
    {
        s.erase(x);
    }
    for(auto x:s)
    {
        v1.pb(x);
        // cout<<x<<endl;
    }
    if(v[1].size()==0)
    {
        cout<<"-1";
        return ;
    }
    ll xx=v[1][0];
    rep(i,n)
    {
        s.insert(i+1);
    }
    for(auto x:v[xx])
    {
        s.erase(x);
    }
    // cout<<xx<<endl;
    for(auto x:s)
    {
        v2.pb(x);
        // cout<<x<<endl;
    }
    rep(i,n)
    {
        s.insert(i+1);
    }
    for(auto x:v1)
    {
        if(s.find(x)!=s.end())
        s.erase(s.find(x));
    }
    for(auto x:v2)
    {
        if(s.find(x)!=s.end())
        s.erase(s.find(x));
    }
    if(s.empty())
    {
        cout<<"-1"<<endl;
        return;
    }
    xx=*s.begin();
    // cout<<xx<<endl;
    rep(i,n)
    {
        s.insert(i+1);
    }
    for(auto x:v[xx])
    {
        s.erase(x);
    }
    for(auto x:s)
    {
        // cout<<x<<endl;
        v3.pb(x);
    }
    ll ss=v1.size()*(v2.size()+v3.size())+v2.size()*v3.size();
    if(ss!=m)
    {
        cout<<"-1"<<endl;
        return;
    }
    for(auto x:v1)
    {
        for(auto y:v2)
        {
            if(m1.find(mp(x,y))==m1.end())
            {
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    for(auto x:v1)
    {
        for(auto y:v3)
        {
            if(m1.find(mp(x,y))==m1.end())
            {
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    for(auto x:v2)
    {
        for(auto y:v3)
        {
            if(m1.find(mp(x,y))==m1.end())
            {
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    ll ans[100005]={0};
    for(auto x:v1)
    {
        ans[x]=1;
    }
    for(auto x:v2)
    {
        ans[x]=2;
    }
    for(auto x:v3)
    {
        ans[x]=3;
    }

    rep(i,n)
    {
        cout<<ans[i+1]<<' ';
    }


}

signed main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
    #ifdef rg
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    end_routine();
}