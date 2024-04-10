#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 2e5;
vector<int> g[mx];
int n, m, deg[mx], t[mx];
queue<int> q0, q1;

void up(int v) {
    for (auto v1 : g[v]) {
        deg[v1]--;
        if (deg[v1] == 0 && t[v1] == 0)
            q0.push(v1);
        if (deg[v1] == 0 && t[v1] == 1)
            q1.push(v1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0 && t[i] == 0)
            q0.push(i);
        if (deg[i] == 0 && t[i] == 1)
            q1.push(i);
    }
    int ans = 0;
    while (!q0.empty() || !q1.empty()) {
        while (!q0.empty()) {
            int v = q0.front();
            up(v);
            q0.pop();
        }
        if (!q1.empty()) {
            ans++;
            while (!q1.empty()) {
                int v = q1.front();
                up(v);
                q1.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}