#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
const int W = 50 + 1;
const int INF = (int) 1e9;
int n, m;
vector<int> g[W][N];
set<int> snice[N];
vector<int> nice[N];
int best[N];
int mai[W][N];

struct T {
        int value;
        int x;
        int e;
};

bool operator < (T a, T b) {
        return a.value > b.value;
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
                int x, y, w;
                cin >> x >> y >> w;
                g[w][x].push_back(y);
                g[w][y].push_back(x);
                snice[x].insert(w);
                snice[y].insert(w);
        }
        for (int i = 1; i <= n; i++) {
                for (auto &j : snice[i])
                        nice[i].push_back(j);
        }
        for (int i = 1; i <= n; i++) {
                best[i] = INF;
                for (int j = 1; j < W; j++)
                        mai[j][i] = INF;
        }
        priority_queue<T> pq;
        best[1] = 0;
        pq.push({0, 1, 0});
        while (!pq.empty()) {
               /// cout << "aici\n";
                auto it = pq.top();
                pq.pop();
                if (it.e) {
                        if (it.value != mai[it.e][it.x])
                                continue;
                } else {
                        if (it.value != best[it.x])
                                continue;
                }
                if (!it.e) {
                        int x = it.x;
                        for (auto &k : nice[x]) {
                                for (auto &j : g[k][x]) {
                                        if (it.value < mai[k][j]) {
                                                mai[k][j] = it.value;
                                                pq.push({it.value, j, k});
                                        }
                                }
                        }
                } else {
                        int x = it.x, lastk = it.e;
                        for (auto &k : nice[x]) {
                                for (auto &j : g[k][x]) {
                                        int cost = it.value + (lastk + k) * (lastk + k);
                                        if (cost < best[j]) {
                                                best[j] = cost;
                                                pq.push({cost, j, 0});
                                        }
                                }
                        }
                }
        }
        for (int i = 1; i <= n; i++) {
                if (best[i] == INF)
                        best[i] = -1;
                cout << best[i] << " ";
        }
        cout << "\n";

}