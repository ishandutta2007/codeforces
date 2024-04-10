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


typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef gp_hash_table<long long, long long> umap;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
// not that imp
typedef pair<pll, ll> plll;
typedef vector<ll> vl;
typedef vector<pll> vll;

#define inf 200000000000000ll
#define mod 1000000007ll
#define eps 1e-7
#define PI 3.1415926535897932385
// #define PI acos(-1)

#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()

#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fill(ar,val) memset(ar, val, sizeof(ar))

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
ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

const ll maxn = 1000005;
vector<pair<ll, pll>> adj;

ll parent[maxn];
ll siz[maxn];

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

//run this for the entire array
void make_set(ll v) {
    parent[v] = v;
    // sizeRank[v] = 0;
    siz[v] = 1;//
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(siz[a] < siz[b])//
        // if (sizeRank[a] < sizeRank[b])
            swap(a, b);
        parent[b] = a;
        // if (sizeRank[a] == sizeRank[b])
            // sizeRank[a]++;
        siz[a] += siz[b];//
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    pair<ll, pll> extraEdge,temp;
    rep(i,n){
        make_set(i);
    }
    rep(i,m){
        ll u,v,w; cin>>u>>v>>w;
        u--; v--;
        if(i==0){
            extraEdge.ff = w;
            extraEdge.ss.ff =  u;
            extraEdge.ss.ss =  v;     
        }
        else{
            temp.ff = w;
            temp.ss.ff =  u;
            temp.ss.ss =  v;    
            adj.pb(temp); 
        }
    }
    sort(all(adj));
    ll ans_wo = 0;
    rep(i,m-1){
        ll v,to,w;
        w = adj[i].ff;
        v = adj[i].ss.ff, to = adj[i].ss.ss;
        if(find_set(v) != find_set(to)){
            ans_wo += w;
            union_sets(v,to);
        }
    }
    ll p = find_set(0);
    ll cost = 0;
    rep(i,n){
        if(p != find_set(i)){
            cost = 1000000000;
            cout<<cost<<endl;
            return;
        }
    }
    rep(i,n)
        make_set(i);
    // adj.pb(extraEdge);
    // sort(all(adj));
    ll ans_w = 0;
    union_sets(extraEdge.ss.ff, extraEdge.ss.ss);
    ans_w += extraEdge.ff;
    rep(i,m-1){
        ll v,to,w;
        w = adj[i].ff;
        v = adj[i].ss.ff, to = adj[i].ss.ss;
        if(find_set(v) != find_set(to)){
            ans_w += w;
            union_sets(v,to);
        }
    }
    // trace(ans_w, ans_wo);
    // if(ans_w > ans_wo){
        cost = min(1000000000ll, max(0ll, extraEdge.ff - (ans_w - ans_wo)));
    // }
    cout<<cost<<endl;
}

int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(10); //cout<<fixed;
    cin.exceptions(cin.failbit);
    #ifdef bhartiya
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    end_routine();
}