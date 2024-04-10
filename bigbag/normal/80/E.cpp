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

const int max_n = 111111, inf = 111111111;

int n, root, cnt[max_n], used[max_n];
vector<int> g[max_n];

pair<long long, int> dfs(int v, int k) {
    used[v] = 1;
    vector<long long> vv;
    long long QQQ = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            pair<long long, int> q = dfs(g[v][i], cnt[g[v][i]] - 1);
            vv.push_back(q.first + 1);
            QQQ += q.second;
        }
    }
    sort(vv.begin(), vv.end());
    long long ret = 0, cnt = 0;
    for (int i = vv.size() - 1; i >= max(0, (int) vv.size() - k); --i) {
        ret += vv[i] + 1;
        ++cnt;
    }
    if (k - cnt > 0) {
        long long x = min(k - cnt, QQQ);
        cnt += x;
        ret += 2 * x;
    }
    return make_pair(ret, k - cnt);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cnt[i]);
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    scanf("%d", &root);
    cout << dfs(root, cnt[root]).first << endl;
    return 0;
}