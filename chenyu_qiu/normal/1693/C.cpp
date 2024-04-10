#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define en '\n'
#define sp ' '
#define tb '\t'
#define ri(n) int n; cin >> n
#define rl(n) ll n; cin >> n
#define rs(s) string s; cin >> s
#define rc(c) char c; cin >> c
#define rv(v) for (auto &x : v) cin >> x
#define pven(v) for (auto x : v) cout << x << en
#define pv(v) for (auto x : v) cout << x << sp; cout << en
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES" << en
#define no cout << "NO" << en
#define smin(a, b) a = min(a, b)
#define smax(a, b) a = max(a, b)
#define ssort(a, b) if (a < b) swap(a, b)
#define bitcnt(a) (__builtin_popcountll(a))
#define bithigh(a) (63-__builtin_clzll(a))
#define lg bithigh
#define highpow(a) (1LL << (ll)lg(a))
 
using namespace std;
 
const ll LINF = 4e18;
const int mxN = 1e6+10, INF = 2e9;
ll n, m, a[mxN], dist[mxN], indeg[mxN];
vector<int> g[mxN];
bool vis[mxN];
 
void Solve(){
 
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        ri(u); ri(v);
        u--; v--;
        g[v].pb(u);
        indeg[u]++;
    }
    for (int i = 0; i < n; i++) dist[i] = INF;
    priority_queue<array<ll, 2>,
            vector<array<ll, 2> >,
            greater<array<ll, 2> > > pq;
    dist[n-1] = 0;
    pq.push({0, n-1});
    while (pq.size()){
        int s = pq.top()[1]; pq.pop();
        if (vis[s]) continue;
        vis[s] = 1;
        for (int u : g[s]){
            if (dist[s] + indeg[u] < dist[u]){
                dist[u] = dist[s] + indeg[u];
                pq.push({dist[u], u});
            }
            indeg[u]--;
        }
    }
    cout << dist[0] << en;
}
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cerr.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;
    cerr << "Started!" << endl;
 
    int t = 1;
    //cin >> t;
    while (t--)
        Solve();
 
    return 0;
}