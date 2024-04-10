#include <bits/stdc++.h>

using namespace std;

const int mx = 250000;
int n, m, k, ans, cl[mx], v1, v2, v, s, x;
bool used[mx];
vector<int> graph[mx];
map<int, int> mp;

void dfs(int u) {
    used[u] = 1;
    mp[cl[u]]++;
    s++;
    x = max(x, mp[cl[u]]);
    for (int i = 0; i<graph[u].size(); i++) {
        v = graph[u][i];
        if (used[v] == 0) dfs(v);
    }
}

int main()
{
    cin >> n >> m >> k;
    int i, j;
    for (i = 0; i<n; i++) {
        cin >> cl[i];
        used[i] = 0;
    }
    for (i = 0; i<m; i++) {
        cin >> v1 >> v2;
        graph[v1 - 1].push_back(v2 - 1);
        graph[v2 - 1].push_back(v1 - 1);
    }
    for (i = 0; i<n; i++) {
        mp.clear();
        s = 0;
        x = 0;
        dfs(i);
        ans += s - x;
    }
    cout << ans;
    return 0;
}