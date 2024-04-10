#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

const int max_n = 15055, inf = 1000111222;

int n, dp[max_n], sz[max_n], used[max_n], parent[max_n];
vector<int> g[max_n], all;
int h[max_n], in_cycle[max_n], res[max_n];
int best[2][max_n], sum_dp[max_n];

void dfs(int v, int p) {
    used[v] = 1;
    parent[v] = p;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if  (used[to]) {
            if (h[to] > h[v]) {
                continue;
            }
            int cur = v;
            while (true) {
                all.push_back(cur);
                in_cycle[cur] = 1;
                if (cur == to) {
                    break;
                }
                cur = parent[cur];
            }
        } else {
            h[to] = h[v] + 1;
            dfs(to, v);
        }
    }
}

int forb;
vector<int> allv;

void dfs2(int v, int p) {
    sz[v] = 1;
    dp[v] = 0;
    for (int to : g[v]) {
        if (to == p || to == forb) {
            continue;
        }
        dfs2(to, v);
        sz[v] += sz[to];
        dp[v] += dp[to];
    }
    dp[v] += sz[v];
    //cout << v << ": " << sz[v] << " " << dp[v] << endl;
}

void dfs3(int v, int p) {
    allv.push_back(v);
    for (int to : g[v]) {
        if (to == p || to == forb) {
            continue;
        }
        h[to] = h[v] + 1;
        dfs3(to, v);
    }
}

int sum_sz[2 * max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    if (n <= 2) {
        exit(222);
    }
    for (int i = 0; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    int tot = 0;
    for (int v : all) {
        forb = v;
        for (int to : g[v]) {
            if (in_cycle[to]) {
                continue;
            }
            dfs2(to, v);
            sum_dp[v] += dp[to];
        }
        tot += sum_dp[v];
    }
    int q1 = 0, q2 = 1;
    for (int i = 0; i < all.size(); ++i) {
        sum_sz[i] = 1;
        for (int to : g[all[i]]) {
            if (!in_cycle[to]) {
                sum_sz[i] += sz[to];
                //cout << "$" << all[i] << " " << sz[to] << ", to = " << to << endl;
            }
        }
        //cout << "(" << all[i] << ": " << res[all[i]] << " " << sum_dp[all[i]] << " " << sum_sz[i] << ") ";
    }
    //cout << endl;
    //cout << "$" << endl;
    for (int v : all) {
        forb = v;
        // calc res[v]
        int add = -inf;
        for (int to : g[v]) {
            if (in_cycle[to]) {
                continue;
            }
            int SZ = (n - sz[to]);
            allv.clear();
            h[to] = 2;
            dfs3(to, v);
            int subs = -dp[to];
            for (int root : allv) {
                dfs2(root, v);
                add = max(add, dp[root] + h[root] * SZ + subs);
            }
        }
        //if (v == 2) cout << "$$" << sum_dp[v] << " " << add << endl;
        if (add == -inf) {
            res[v] = n;
        } else {
            res[v] = sum_dp[v] + add;
        }
    }
    for (int i = 0; i < all.size(); ++i) {
        //cout << all[i] << ": " << res[all[i]] << endl;
        best[q1][i] = tot - sum_dp[all[i]] + res[all[i]];
    }
    for (int j = all.size(); j < 2 * all.size(); ++j) {
        sum_sz[j] = sum_sz[j - all.size()];
    }
    for (int j = 0; j < 2 * all.size(); ++j) {
        if (j) {
            sum_sz[j] += sum_sz[j - 1];
        }
    }
    for (int i = 0; i + 1 < all.size(); ++i) {
        memset(best[q2], 0, sizeof(best[q2]));
        //cout << i << ": ";
        for (int j = 0; j < all.size(); ++j) {
            //cout << best[q1][j] << " ";
            int tot = sum_sz[j + i];
            if (j) {
                tot -= sum_sz[j - 1];
            }
            best[q2][j] = max(best[q2][j], best[q1][j] + n - tot);
            int pr = j - 1;
            if (j == 0) {
                pr += all.size();
            }
            best[q2][pr] = max(best[q2][pr], best[q1][j] + n - tot);
        }
        swap(q1, q2);
        //cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < all.size(); ++i) {
        //cout << best[q1][i] << " ";
        ans = max(ans, best[q1][i]);
    }
    //cout << endl;
    printf("%d\n", ans);
    return 0;
}