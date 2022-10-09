#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool operator < (const Edge& lhs, const Edge& rhs) {
    return lhs.w != rhs.w ? lhs.w < rhs.w
        : lhs.u != rhs.u ? lhs.u < rhs.u
        : lhs.v < rhs.v;
}

const int maxn = 303030;
const int maxm = 303030;
int n, m;
vector<Edge> a;
int dp_node[maxn], dp_edge[maxm];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    a.resize(m);
    for (auto& it: a) {
        cin >> it.u >> it.v >> it.w;
    }
    
    sort(a.begin(), a.end());
    
    for (int start = 0, end = 0; start < m; start = end) {
        while (end < m and a[start].w == a[end].w) ++ end;
        for (int i = start; i < end; ++i) {
            int u = a[i].u;
            dp_edge[i] = dp_node[u] + 1;
        }
        for (int i = start; i < end; ++i) {
            int v = a[i].v;
            dp_node[v] = max(dp_node[v], dp_edge[i]);
        }
    }
    cout << *max_element(dp_node, dp_node + n + 1);
    
    return 0;
}