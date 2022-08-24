#include <bits/stdc++.h>

using namespace std;

#define int long long
struct Edge{int u; int v; int c;};
bool cmp(Edge &a, Edge &b){
    return (a.c < b.c);
}
struct Snm{int r; int f; int a;};
vector<Snm> snm;
int get(int v){
    if (snm[v].f == v) return v;
    snm[v].f = get(snm[v].f);
    return snm[v].f;
}
int un(int a, int b){
    if (snm[a].r > snm[b].r) swap(a, b);
    snm[a].f = b;
    if (snm[a].r == snm[b].r) snm[b].r++;
    snm[b].a += snm[a].a;
    return b;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> all;
    all.resize(n, false);
    for (int i=0;i<k;i++){
        int x;
        cin >> x;
        all[x-1] = true;
    }
    vector<Edge> edges;
    for (int i=0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u-1, v-1, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i=0; i < n; i++) snm.push_back({1, i, all[i]});
    for (int i=0; i < m; i++){
        int u = edges[i].u, v = edges[i].v;
        int v1 = get(u), v2 = get(v);
        if (v1==v2) continue;
        int V = un(v1, v2);
        if (snm[V].a == k){
            for (int j=0; j < k; j++) cout << edges[i].c << " ";
            return 0;
        }
    }
    return 0;
}