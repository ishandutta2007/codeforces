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

const int max_n = 311111, inf = 1111111111;

int n, m, cnt, u[max_n], v[max_n], c[max_n], t[max_n], a[max_n], b[max_n], no[max_n], res[max_n], used[max_n];
vector<int> g[max_n], p[max_n], g2[max_n], rg2[max_n], ans, tp;
vector<pair<int, int> > q[max_n];

void add_edge(int a, int b) {
    g2[no[a]].push_back(b);
    g2[no[b]].push_back(a);
    rg2[b].push_back(no[a]);
    rg2[a].push_back(no[b]);
}

void dfs1(int v) {
    used[v] = 1;
    for (int i = 0; i < g2[v].size(); ++i) {
        if (used[g2[v][i]] == 0) {
            dfs1(g2[v][i]);
        }
    }
    tp.push_back(v);
}

void dfs2(int v, int cl) {
    used[v] = cl;
    for (int i = 0; i < rg2[v].size(); ++i) {
        if (used[rg2[v][i]] == 0) {
            dfs2(rg2[v][i], cl);
        }
    }
}

bool ok() {
    tp.clear();
    memset(used, 0, sizeof(used));
    for (int i = 0; i < cnt; ++i) {
        if (used[i] == 0) {
            dfs1(i);
        }
    }
    reverse(tp.begin(), tp.end());
    int cl = 0;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < tp.size(); ++i) {
        if (used[tp[i]] == 0) {
            ++cl;
            dfs2(tp[i], cl);
        }
    }
    for (int i = 0; i < cnt; ++i) {
        if (used[i] == used[no[i]]) {
            return false;
        }
        res[i] = 0;
        if (used[i] > used[no[i]]) {
            res[i] = 1;
        }
    }
    return true;
}

bool check(int tt) {
    for (int i = 0; i < max_n; ++i) {
        g2[i].clear();
        rg2[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        if (t[i] > tt) {
            add_edge(no[i], no[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != -1) {
            add_edge(a[i], b[i]);
        }
        for (int j = 0; j < g[i].size(); ++j) {
            add_edge(no[g[i][j]], p[i][j]);
            if (j + 1 < g[i].size()) {
                add_edge(no[p[i][j]], p[i][j + 1]);
                add_edge(no[p[i][j]], no[g[i][j + 1]]);
            }
        }
    }
    return ok();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int l = -1, r = 0;
    for (int i = 0; i < m; ++i) {
        no[i] = m + i;
        no[m + i] = i;
        scanf("%d%d%d%d", &u[i], &v[i], &c[i], &t[i]);
        q[u[i]].push_back(make_pair(c[i], i));
        q[v[i]].push_back(make_pair(c[i], i));
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
        r = max(r, t[i]);
    }
    cnt = 2 * m;
    for (int i = 1; i <= n; ++i) {
        sort(q[i].begin(), q[i].end());
        a[i] = b[i] = -1;
        for (int j = 0; j < q[i].size(); ++j) {
            int poz = j;
            while (poz < q[i].size() && q[i][j].first == q[i][poz].first) {
                ++poz;
            }
            --poz;
            if (poz - j + 1 > 2) {
                printf("No\n");
                return 0;
            }
            if (poz - j + 1 == 2) {
                if (a[i] == -1) {
                    a[i] = q[i][j].second;
                    b[i] = q[i][j + 1].second;
                } else {
                    printf("No\n");
                    return 0;
                }
            }
        }
        for (int j = 0; j < g[i].size(); ++j) {
            p[i].push_back(cnt);
            ++cnt;
        }
    }
    for (int i = 2 * m; i < cnt; ++i) {
        no[i] = cnt + i - 2 * m;
        no[cnt + i - 2 * m] = i;
    }
    int kr = r;
    ++r;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == kr) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    check(r);
    for (int i = m; i < 2 * m; ++i) {
        if (!res[i]) {
            ans.push_back(i + 1 - m);
        }
    }
    printf("%d %d\n", r, ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}