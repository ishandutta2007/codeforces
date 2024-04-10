#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge{int u; int v; int st; int num;};
struct Snm{int f; int r;};
vector<Snm> snm;
int n, m, ai, bi, ci;
vector<Edge> edges;
vector<bool> used;
vector<vector<int > > graph;
bool cmp(Edge &a, Edge &b){
    return (a.st < b.st);
}
bool Cmp(int a, int b){
    return (edges[a].st < edges[b].st);
}
int get(int vertex){
    if (snm[vertex].f == vertex) return vertex;
    return get(snm[vertex].f);
}
void un(int a, int b){
    if (snm[a].r < snm[b].r){
        snm[a].f = b;
    }
    if (snm[a].r > snm[b].r){
        snm[b].f = a;
    }
    if (snm[a].r == snm[b].r){
        snm[a].f = b;
        snm[b].r++;
    }
}
bool dfs(int v, int last){
    used[v] = true;
    int G = 0;
    for (int i=0; i < graph[v].size(); i++){
        int to = graph[v][i];
        if (to == last){
            G++;
            continue;
        }
        if (used[to]) return false;
        if (!dfs(to, v)) return false;
    }
    if (G > 1) return false;
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < m; i++){
        cin >> ai >> bi >> ci;
        ai--;
        bi--;
        Edge e = {ai, bi, ci, i};
        edges.push_back(e);
    }
    int q;
    vector<vector<int> > z;
    cin >> q;
    vector<int> x;
    set<pair<int, int> > nxt;
    for (int i=0; i < q; i++){
        x.push_back(0);
        int C;
        cin >> C;
        vector<int> c(C);
        for (int j=0; j < C; j++) cin >> c[j];
        for (int j=0; j < C; j++) c[j]--;
        sort(c.begin(), c.end(), Cmp);
        nxt.insert(make_pair(edges[c[0]].st, i));
        z.push_back(c);
    }
    vector<Edge> ec = edges;
    sort(edges.begin(), edges.end(), cmp);
    int u = 0;
    for (int i=0; i < n; i++){
        Snm ss = {i, 1};
        snm.push_back(ss);
    }
    vector<bool> pr(q);
    fill(pr.begin(), pr.end(), true);
    for (int v=0; v < 500001; v++){
        //cout << v << endl;
        while (nxt.size() > 0){
            pair<int, int> pp = *nxt.begin();
            if (pp.first != v) break;
            graph.clear();
            nxt.erase(nxt.begin());
            int ind = pp.second;
            int old = x[ind];
            while (x[ind] < z[ind].size() && ec[z[ind][x[ind]]].st == v){
                x[ind]++;
            }
            if (x[ind] != z[ind].size()) nxt.insert(make_pair(ec[z[ind][x[ind]]].st, ind));
            map<int, int> mm;
            for (int i=old; i < x[ind]; i++){
                int r = z[ind][i];
                int g1 = get(ec[r].u);
                int g2 = get(ec[r].v);
                if (!mm.count(g1)){
                    int MM = mm.size();
                    mm[g1] = MM;
                    vector<int> vect;
                    graph.push_back(vect);
                }
                if (!mm.count(g2)){
                    int MM = mm.size();
                    mm[g2] = MM;
                    vector<int> vect;
                    graph.push_back(vect);
                }
                graph[mm[g1]].push_back(mm[g2]);
                graph[mm[g2]].push_back(mm[g1]);
            }
            used.clear();
            for (int i=0; i < graph.size(); i++) used.push_back(false);
            for (int i=0; i < graph.size(); i++){
                if (!used[i]){
                    bool res = dfs(i, -1);
                    if (!res) pr[pp.second] = false;
                }
            }
        }
        while (u < m && edges[u].st == v){
            int G1 = get(edges[u].u);
            int G2 = get(edges[u].v);
            if (G1 == G2){
                u++;
                continue;
            }
            un(G1, G2);
            u++;
        }
    }
    for (int i=0; i < q; i++){
        if (pr[i]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}