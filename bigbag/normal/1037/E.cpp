#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, k, ans[max_n], used[max_n], sz[max_n];
int a[max_n], b[max_n];
vector<int> g[max_n];
queue<int> q;
set<pair<int, int>> deleted;

void upd(int a, int b) {
    while (!q.empty()) {
        --n;
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (a == v && b == to || a == to && b == v) {
                continue;
            }
            if (!used[to] && !deleted.count({min(v, to), max(v, to)})) {
                --sz[to];
                if (sz[to] < k) {
                    deleted.insert({min(v, to), max(v, to)});
                    //cout << v << ": " << to << endl;
                    q.push(to);
                    used[to] = 1;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        ++sz[a[i]];
        ++sz[b[i]];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (sz[i] < k) {
            q.push(i);
            used[i] = 1;
        }
    }
    upd(-1, -1);
    for (int i = m - 1; i >= 0; --i) {
        ans[i] = n;
        if (!used[a[i]] && !used[b[i]]) {
            --sz[a[i]];
            --sz[b[i]];
            deleted.insert({min(a[i], b[i]), max(a[i], b[i])});
            if (sz[a[i]] < k) {
                used[a[i]] = 1;
                q.push(a[i]);
            }
            if (sz[b[i]] < k) {
                used[b[i]] = 1;
                q.push(b[i]);
            }
            upd(a[i], b[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}