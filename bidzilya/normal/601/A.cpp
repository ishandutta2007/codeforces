#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

int Bfs(int n, const vector<vector<int>>& g)
{
    vector<int> ans(n, INF);
    queue<int> q;
    ans[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i : g[v]) {
            if (ans[i] == INF) {
                ans[i] = ans[v] + 1;
                q.push(i);
            }
        }
    }
    return ans[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    vector<vector<int>> rg(n);
    vector<bool> used;
    for (int i = 0; i < n; ++i) {
        used.assign(n, false);
        used[i] = true;
        for (int j : g[i]) {
            used[j] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                rg[i].push_back(j);
            }
        }
    }

    int ans = max(Bfs(n, g), Bfs(n, rg));
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}