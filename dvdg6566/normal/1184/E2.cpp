#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

struct Edge { int a, b, e, i; };

class UnionFind {
    private: vector<int> p,r;
    public:
             UnionFind(int n) { r.assign(n, 0); p.assign(n, 0); iota(ALL(p), 0); }
             int findset(int i) { return (p[i] == i) ? i : (p[i] = findset(p[i])); }
             bool unionset(int i, int j) {
                 int x = findset(i), y= findset(j);
                 if (x != y) {
                     if (r[x] > r[y]) p[y] = x;
                     else { p[x] = y; if (r[x] == r[y]) ++r[y]; }
                     return true;
                 } else return false;
             }
};
            
const int N = 1e5+10;
const int lgN = 18;
const int M = 1e6+10;

int n, m; 
vector<Edge> el;
vector<ii> al[N];
bool used[M];
int d[N];
ii pa[N][lgN];

void dfs(int u) {
    FOR(k,1,lgN-1) pa[u][k] = ii(pa[pa[u][k-1].fi][k-1].fi, max(pa[u][k-1].sc, pa[pa[u][k-1].fi][k-1].sc));
    //FOR(k,0,lgN-1) cout << u << " " << k << " :: " << pa[u][k].fi << " " << pa[u][k].sc << endl;
    for(auto v : al[u]) if (v.fi != pa[u][0].fi) d[v.fi] = d[u]+1, pa[v.fi][0] = ii(u,v.sc), dfs(v.fi);
}

int ans(int a, int b) {
    //cout << "ANS " << a << " " << b << " :: " << d[a] << " " << d[b] << endl;
    if (d[a] < d[b]) swap(a,b);
    int maxi = 0;
    RFOR(k,lgN-1,0) if (pa[a][k].fi != 0 and d[pa[a][k].fi] >= d[b]) maxi = max(maxi, pa[a][k].sc), a = pa[a][k].fi;
    if (a == b) return maxi;
    RFOR(k,lgN-1,0) if (pa[a][k].fi != 0 and pa[b][k].fi != 0 and pa[a][k].fi != pa[b][k].fi)
        maxi = max(maxi, max(pa[a][k].sc, pa[b][k].sc)), a = pa[a][k].fi, b = pa[b][k].fi;
    maxi = max(maxi, max(pa[a][0].sc, pa[b][0].sc));
    return maxi;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i,0,m-1){
        int a, b, e; cin >> a >> b >> e;
        el.push_back({a,b,e,i});
    }

    sort(ALL(el), [](Edge a, Edge b){ if (a.e == b.e) return a.i < b.i; else return a.e < b.e; });
    UnionFind UF(n+1);
    for (auto& e : el) {
        if (UF.unionset(e.a, e.b)) used[e.i] = 1, al[e.a].emplace_back(e.b, e.e), al[e.b].emplace_back(e.a, e.e);
    }

    d[1] = 0;
    dfs(1);
    sort(ALL(el), [](Edge a, Edge b) { return a.i < b.i; });
    FOR(i,0,m-1) if (!used[i]) cout << ans(el[i].a, el[i].b) << '\n';
}