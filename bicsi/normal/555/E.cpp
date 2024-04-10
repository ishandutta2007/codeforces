#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> graph, queries;
vector<int> enter, low, link, finish, lca_cnt;
int timer = 0;

int Find(int x) {
    if (link[x] == -1) return x;
    return link[x] = Find(link[x]);
}
void Union(int a, int b) {
    a = Find(a); b = Find(b);
    assert(a != b);
    link[a] = b;
}


pair<int, int> DFS(int node, int par) {
    if (par != -1)
        graph[node].erase(
            find(graph[node].begin(), graph[node].end(), par));
    assert(enter[node] == -1);
    enter[node] = timer++;
    low[node] = enter[node];
    
    pair<int, int> ret = {0, 0}; 
     
    for (auto vec : graph[node]) {
        if (enter[vec] == -1) {
            pair<int, int> now = DFS(vec, node);
            if (low[vec] > enter[node] && now.first && now.second)
                throw 5;
            ret.first += now.first; ret.second += now.second;
            Union(vec, node);
        }
        low[node] = min(low[node], low[vec]);
    }

    finish[node] = timer;
    for (auto oth : queries[node]) {
        if (oth < 0) { ret.first += 1; oth = ~oth; }
        else ret.second += 1;
        if (finish[oth] != -1) 
            lca_cnt[Find(oth)] += 1;
    }
    ret.first -= lca_cnt[node];
    ret.second -= lca_cnt[node];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, q; cin >> n >> m >> q;
    graph.resize(n); queries.resize(n);
    link = low = finish = enter = vector<int>(n, -1);
    lca_cnt.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        queries[a].push_back(b);
        queries[b].push_back(~a);
    }

    try {
        for (int i = 0; i < n; ++i)
            if (enter[i] == -1) {
                auto p = DFS(i, -1);
                if (p.first || p.second)
                    throw 5;
            }
        cout << "Yes\n";
    } catch (int) { cout << "No\n"; }
    return 0;
}