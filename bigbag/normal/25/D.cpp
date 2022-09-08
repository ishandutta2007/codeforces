#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;

struct edge {
    int u, v;
};

edge make_edge(int u, int v) {
    edge ret;
    ret.u = u;
    ret.v = v;
    return ret;
}

int n, u[max_n], v[max_n], parent[max_n], f[max_n];
vector <edge> x;
vector < pair<edge, edge> > ans;

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int x, int y) {
    int v1 = find_set(x), v2 = find_set(y);
    if (v1 != v2) {
        parent[v1] = v2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        cin >> u[i] >> v[i];
        if (find_set(u[i]) == find_set(v[i])) {
            f[i] = 1;
            x.push_back(make_edge(u[i], v[i]));
        } else {
            union_set(u[i], v[i]);
        }
    }
    int cnt = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (find_set(i) != find_set(j)) {
                ++cnt;
                ans.push_back(make_pair(x[cnt], make_edge(i, j)));
                union_set(i, j);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first.u << ' ' << ans[i].first.v << ' ' << ans[i].second.u << ' ' << ans[i].second.v << endl;
    }
    return 0;
}