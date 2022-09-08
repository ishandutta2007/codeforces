#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 101111, inf = 1111111111;

int n, m, cnt, used[max_n], sz[max_n], f[max_n], a[max_n], b[max_n], dp[max_n];
pair<int, int> p[max_n];
vector<int> g[max_n];

void dfs(int v) {
    used[v] = 1;
    ++sz[cnt];
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }
}

bool ok(int x) {
    while (x > 0) {
        if (x % 10 != 4 && x % 10 != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs(i);
            ++cnt;
        }
    }
    sort(sz, sz + cnt);
    int cnt2 = 0;
    for (int i = 0; i < cnt; ++i) {
        a[cnt2] = sz[i];
        b[cnt2] = 1;
        while (i + 1 < cnt && sz[i] == sz[i + 1]) {
            ++i;
            ++b[cnt2];
        }
        ++cnt2;
    }
    cnt = cnt2;
    cnt2 = 0;
    for (int i = 0; i < cnt; ++i) {
        int s = 1, sum = 0;
        while (sum + s <= b[i]) {
            p[cnt2] = make_pair(s * a[i], s);
            ++cnt2;
            sum += s;
            s *= 2;
        }
        if (sum < b[i]) {
            p[cnt2] = make_pair((b[i] - sum) * a[i], b[i] - sum);
            ++cnt2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = inf;
        if (ok(i)) {
            f[i] = 1;
        }
    }
    cnt = cnt2;
    dp[0] = 0;
    for (int i = 0; i < cnt; ++i) {
        //cout << i << "  -  " << p[i].first << "  " << p[i].second << endl;
        for (int x = n - p[i].first; x >= 0; --x) {
            dp[x + p[i].first] = min(dp[x + p[i].first], dp[x] + p[i].second);
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; ++i) {
        //cout << i << " - " << dp[i] << endl;
        if (f[i] == 1) {
            ans = min(ans, dp[i]);
        }
    }
    if (ans == inf) {
        printf("-1\n");
    } else {
        printf("%d\n", ans - 1);
    }
    return 0;
}