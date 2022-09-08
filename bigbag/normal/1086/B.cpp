#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, s, sz[max_n], cnt[max_n];
vector<int> g[max_n];
vector<long long> all;

void dfs(int v, int p) {
    bool leaf = true;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            leaf = false;
            cnt[v] += cnt[to];
        }
    }
    cnt[v] += g[v].size() == 1;
}

void dfs2(int v, int p) {
    for (int to : g[v]) {
        if (to != p) {
            dfs2(to, v);
            all.push_back(1LL * cnt[to] * (cnt[1] - cnt[to]));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    dfs2(1, -1);
    sort(all.begin(), all.end());
    long double ans = s;
    ans *= all.front();
    ans /= (1LL * cnt[1] * (cnt[1] - 1) / 2);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}