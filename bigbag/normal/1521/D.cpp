/**
 *  created: 07/05/2021, 18:13:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, dp[max_n][2], cnt[max_n][2], used[max_n], sz[max_n];
vector<int> g[max_n];
vector<vector<pair<int, int>>> parents[max_n];
set<pair<int, int>> del;

void clr() {
    del.clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        parents[i].clear();
        used[i] = sz[i] = 0;
    }
}

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
    vector<int> cur_dp(3, inf);
    cur_dp[0] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        vector<int> ndp(3, inf);
        vector<pair<int, int>> parent(3, make_pair(-1, -1));
        for (int i = 0; i < 3; ++i) {
            for (int f = 0; f < 2; ++f) {
                if (i + f < 3 && ndp[i + f] > cur_dp[i] + dp[to][f]) {
                    ndp[i + f] = cur_dp[i] + dp[to][f];
                    parent[i + f] = {i, f};
                }
            }
        }
        parents[v].push_back(parent);
        cur_dp.swap(ndp);
    }
    dp[v][0] = dp[v][1] = inf;
    for (int i = 0; i < 2; ++i) {
        if (dp[v][1] > cur_dp[i]) {
            cnt[v][1] = i;
            dp[v][1] = cur_dp[i];
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (dp[v][0] > cur_dp[i]) {
            cnt[v][0] = i;
            dp[v][0] = cur_dp[i];
        }
    }
    dp[v][0] += (v != 0);
}

void restore_answer(int v, int f, int p) {
    vector<int> tos;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        tos.push_back(to);
    }
    int cur_cnt = cnt[v][f];
    while (!tos.empty()) {
        const int to = tos.back();
        tos.pop_back();
        auto parent = parents[v].back();
        parents[v].pop_back();
        restore_answer(to, parent[cur_cnt].second, v);
        if (!parent[cur_cnt].second) {
            del.insert({v, to});
        }
        cur_cnt = parent[cur_cnt].first;
    }
}

vector<int> path;

void get_path(int v) {
    used[v] = 1;
    path.push_back(v);
    for (int to : g[v]) {
        if (used[to] || del.count({v, to}) || del.count({to, v})) {
            continue;
        }
        get_path(to);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
            ++sz[u];
            ++sz[v];
        }
        dfs(0, -1);
        restore_answer(0, 0, -1);
        assert(dp[0][0] == del.size());
        for (auto p : del) {
            --sz[p.first];
            --sz[p.second];
        }
        vector<vector<int>> paths;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && sz[i] <= 1) {
                path.clear();
                get_path(i);
                paths.push_back(path);
            }
        }
        assert(paths.size() == del.size() + 1);
        printf("%d\n", del.size());
        int i = 0;
        for (auto p : del) {
            //printf("%d %d\n", p.first + 1, p.second + 1);
            printf("%d %d %d %d\n", p.first + 1, p.second + 1, paths[i].back() + 1, paths[i + 1][0] + 1);
            ++i;
        }
        clr();
    }
    return 0;
}