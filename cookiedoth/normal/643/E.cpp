#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,abm,mmx,popcnt,tune=native")
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int lg = 32;

// void dfs(int u, const vector<vector<int>>& g, vector<vector<double>>& p) {
//     for (int v : g[u]) {
//         dfs(v, g, p);
//     }
//     p[u][0] = 1;
//     for (int v : g[u]) {
//         p[u][0] /= 2.0;
//     }
//     for (int k = 1; k < lg; ++k) {
//         p[u][k] = 1;
//         for (int v : g[u]) {
//             p[u][k] *= (1 + p[v][k - 1]) / 2.0;
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout.precision(20);
    int q;
    cin >> q;
    vector<vector<int>> g(1);
    vector<vector<double>> p(1, vector<double>(lg, 1));
    vector<vector<double>> p2(1, vector<double>(lg, 1));
    vector<int> pred(1, -1);
    while (q--) {
        int tp, v;
        cin >> tp >> v;
        v--;
        if (tp == 1) {
            g.emplace_back();
            g[v].push_back(g.size() - 1);
            p.emplace_back(lg, 1);
            p2.emplace_back(lg, 1);
            pred.push_back(v);
            int cur = v, pr = g.size() - 1;
            int it = 0;
            while (cur != -1 && it < lg) {
                if (cur == v) {
                    p2[cur][0] = p[cur][0] / 2.0;
                }
                for (int k = 1; k < lg; k++) {
                    p2[cur][k] = p[cur][k];
                    p2[cur][k] /= ((1 + p[pr][k - 1]) / 2.0);
                    p2[cur][k] *= ((1 + p2[pr][k - 1]) / 2.0);
                }
                cur = pred[cur];
                pr = pred[pr];
                it++;
            }
            cur = v;
            it = 0;
            while (cur != -1 && it < lg) {
                p[cur] = p2[cur];
                cur = pred[cur];
                it++;
            }
        } else {
            //dfs(v, g, p);
            double ans = 0;
            for (int k = 1; k < lg; k++) {
                ans += (1 - p[v][k - 1]);
            }
            cout << ans << '\n';
        }
    }
}