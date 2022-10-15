#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
int m;
vector<int> g[N];
vector<int> gCorrect[N];
vector<int> backEdges[N];
bool vis[N];
int d[N];

void buildBackEdges(int a) {
        vis[a] = 1;
        for (auto &b : g[a]) {
                if (vis[b] == 0) {
                        d[b] = 1 + d[a];
                        gCorrect[a].push_back(b);
                        buildBackEdges(b);
                } else {
                        if (d[b] < d[a] - 1) {
                                backEdges[b].push_back(a);
                        }
                }
        }
}

struct T {
        int a;
        int b;
        int c;
};

vector<T> sol;

int dfs(int a) {
        vector<int> nodes;
        for (auto &b : gCorrect[a]) {
                int c = dfs(b);
                if (c) {
                        sol.push_back({a, b, c});
                } else {
                        nodes.push_back(b);
                }
        }
        for (auto &it : backEdges[a]) {
                nodes.push_back(it);
        }
        while ((int) nodes.size() >= 2) {
                int x = nodes.back();
                nodes.pop_back();
                int y = nodes.back();
                nodes.pop_back();
                sol.push_back({x, a, y});
        }
        if (nodes.empty()) {
                return 0;
        } else {
                return nodes[0];
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        if (m % 2 == 1) {
                cout << "No solution\n";
                return 0;
        }
        buildBackEdges(1);
        for (int i = 1; i <= n; i++) {
                g[i] = gCorrect[i];
        }
        dfs(1);
        for (auto &it : sol) {
                cout << it.a << " " << it.b << " " << it.c << "\n";
        }
}