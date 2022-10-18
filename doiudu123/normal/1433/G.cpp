#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1001, logN = 17, K = 500;

vector <pair <int, long long>> adj[N];

long long dis[N][N];

void build_dis(int s) {
    priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair <long long, int>>> q;
    q.push({0, s});
    dis[s][s] = 0;
    long long d;
    int v;
    while (q.size()) {
        tie(d, v) = q.top(); q.pop();
        if (d > dis[s][v]) continue;
        for (auto i : adj[v]) {
            if (dis[s][i.first] > d + i.second) {
                dis[s][i.first] = d + i.second;
                q.push({dis[s][i.first], i.first});
            }
        }
    }
}

struct Edge {
    int u, v;
    Edge (int _u, int _v) : u(_u), v(_v) {}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    fop (i,0,n) fop (j,0,n) dis[i][j] = 1ll << 60;
    vector <Edge> E, Q;
    fop (i,0,m) {
        cin >> u >> v >> w, u--, v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
        E.eb(Edge(u, v));
    }
    fop (i,0,k) {
        cin >> u >> v, u--, v--;
        if (u != v) Q.eb(Edge(u, v));
    }
    k = Q.size();
    fop (i,0,n) build_dis(i);
    lli ans = 1ll << 60;
    for (Edge &e : E) {
        lli tmp = 0;
        for (Edge &q : Q) {
            tmp += min({dis[q.u][e.u] + dis[q.v][e.v], dis[q.u][e.v] + dis[q.v][e.u], dis[q.u][q.v]});
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}