#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;
vector<vector<int> > g;
int ans = 0;

void Dfs(int v, int pr, int cm)
{
    if (a[v]) {
        ++cm;
        if (cm > m) {
            return;
        }
    } else {
        cm = 0;
    }
    bool is_leaf = true;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (u != pr) {
            is_leaf = false;
            Dfs(u, v, cm);
        }
    }
    if (is_leaf) {
        ++ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    Dfs(0, -1, 0);

    cout << ans << endl;

    return 0;
}