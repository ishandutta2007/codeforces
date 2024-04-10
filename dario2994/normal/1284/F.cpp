/* Complexity Nlog(N).
    Description: Keeps a disjoint union set on the vertices of the second tree.
                 The root of each tree in the forest coincides with the highest
                 vertex in that component (with respect to the second tree).
                 When two vertices u-v must be joined, the first free edge in
                 the path from u to v is found and the union is done. The first
                 free edge is found in log(N) time using an lca structure on
                 the tree.
                 All the magic happens in the function 'choose'.
                 It is not possible to add the the union-by-rank optimization
                 (as the root of each component must be the highest vertex in
                 the tree).
                 
*/

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
    ifstream in("input.txt");
    #define cin in
#endif

const int MAXN = 250100;
const int MAXL = 18;
vector<int> aa[MAXN], aa2[MAXN]; //trees
vector<int> ids[MAXN], ids2[MAXN]; //ids of the edges

int res[MAXN];

int depth[MAXN]; // depth in tree2
int ff[MAXN][MAXL]; // lca-structure on tree2
int dsu[MAXN]; // dsu on tree2
int edge_id[MAXN];  // edge_id[v] = id of the (father(v), v) in tree2

void precompute(int v, int f) {
    ff[v][0] = f;
    depth[v] = depth[f] + 1;
    for (int i = 0; i < (int)aa2[v].size(); i++) {
        int a = aa2[v][i];
        if (a == f) continue;
        edge_id[a] = ids2[v][i];
        precompute(a, v);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int it = MAXL-1; it >= 0; it--) if (depth[u]-(1<<it) >= depth[v]) u = ff[u][it];
    if (u == v) return u;
    for (int it = MAXL-1; it >= 0; it--) if (ff[u][it] != ff[v][it]) {
        u = ff[u][it];
        v = ff[v][it];
    }
    return ff[u][0];
}

int ancestor(int v) {
    if (v != dsu[v]) dsu[v] = ancestor(dsu[v]);
    return dsu[v];
}

int join(int u) { // Joins u with his father.
    // assert(gg[u] == u and u != 1);
    dsu[u] = ff[u][0];
    return edge_id[u];
}

int choose(int u, int v) { // Finds the first "free" in the path from u to v.
    // assert(ancestor(u) != ancestor(v));
    int a = lca(u, v);
    int x = ancestor(u);
    if (depth[x] > depth[a]) return join(x);
    for (int it = MAXL-1; it >= 0; it--) {
        if (depth[v]-(1<<it) > depth[a] && ancestor(ff[v][it]) != x) {
            v = ff[v][it];
        }
    }
    return join(v);
}

void solve(int v, int f) {
    for (int i = 0; i < (int)aa[v].size(); i++) {
        int a = aa[v][i];
        if (a == f) continue;
        solve(a, v);
        res[ids[v][i]] = choose(a, v);
    }
}


pair<int,int> edge1[MAXN];
pair<int,int> edge2[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        aa2[a].push_back(b);
        aa2[b].push_back(a);
        ids2[a].push_back(i);
        ids2[b].push_back(i);
        edge1[i] = {a, b};
    }
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
        aa[b].push_back(a);
        ids[a].push_back(i);
        ids[b].push_back(i);
        edge2[i] = {a, b};
    }
    precompute(1, 0);
    for (int l = 1; l < MAXL; l++) {
        for (int v = 1; v <= N; v++) ff[v][l] = ff[ff[v][l-1]][l-1];
    }
    for (int i = 1; i <= N; i++) dsu[i] = i;
    solve(1, 0);
    cout << N-1 << "\n";
    for (int i = 1; i <= N-1; i++) {
        cout << edge1[res[i]].first << " " << edge1[res[i]].second << " "
             << edge2[i].first << " " << edge2[i].second << "\n";
        // cout << res[i] << " ";
    }
    cout << "\n";
}