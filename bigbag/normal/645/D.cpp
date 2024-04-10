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

const int max_n = 111111, inf = 1111111111;

int n, m, u[max_n], v[max_n], used[max_n];
set<pair<int, int> > all;
vector<int> g[max_n], q;

void dfs2(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs2(g[v][i]);
        }
    }
    q.push_back(v);
}

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
        used[i] = 0;
    }
    all.clear();
    for (int i = 0; i < x; ++i) {
        g[u[i]].push_back(v[i]);
        all.insert(make_pair(u[i], v[i]));
    }
    q.clear();
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs2(i);
        }
    }
    reverse(q.begin(), q.end());
    for (int i = 0; i + 1 < q.size(); ++i) {
        if (!all.count(make_pair(q[i], q[i + 1]))) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
    }
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == m + 1) {
        r = -1;
    }
    printf("%d\n", r);
    return 0;
}