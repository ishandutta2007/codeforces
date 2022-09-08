#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222, max_len = 1111111;

int n, m, q, dx[max_n], dy[max_n], f[max_n * max_n], used[max_n * max_n], mask[max_n * max_n], poz[max_len];
int msk[max_len];
char a[max_n][max_n], s[max_len];
vector<int> g[max_n * max_n], rg[max_n * max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void add_edge(int x, int y, int a, int b) {
    x = x * m + y;
    a = a * m + b;
    g[x].push_back(a);
    rg[a].push_back(x);
}

void proc() {
    int cnt = 0;
    vector<int> all;
    for (int i = 0; i < n * m; ++i) {
        if (used[i] == 0) {
            ++cnt;
            int v = i;
            while (used[v] == 0) {
                used[v] = cnt;
                if (g[v].size() == 0) {
                    break;
                }
                v = g[v][0];
            }
            if (g[v].size() && used[v] == cnt) {
                v = i;
                mask[i] = 0;
                while (true) {
                    mask[i] |= (1 << (a[v / m][v % m] - '0'));
                    f[v] = 1;
                    if (i != v) {
                        for (int j = 0; j < rg[v].size(); ++j) {
                            rg[i].push_back(rg[v][j]);
                        }
                    }
                    v = g[v][0];
                    if (v == i) {
                        break;
                    }
                }
                f[i] = 2;
                all.clear();
                for (int j = 0; j < rg[i].size(); ++j) {
                    if (f[rg[i][j]] == 0) {
                        all.push_back(rg[i][j]);
                    }
                }
                rg[i] = all;
                sort(rg[i].begin(), rg[i].end());
                rg[i].erase(unique(rg[i].begin(), rg[i].end()), rg[i].end());
                g[i].clear();
            }
        }
    }
}

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

bool dfs(int v, int poz) {
    if (a[v / m][v % m] == s[poz]) {
        --poz;
    }
    if (poz == -1) {
        return true;
    }
    for (int i = 0; i < rg[v].size(); ++i) {
        if (dfs(rg[v][i], poz)) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 10; ++i) {
        scanf("%d%d", &dx[i], &dy[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mask[i * m + j] = (1 << (a[i][j] - '0'));
            int k = a[i][j] - '0';
            int x = i + dx[k];
            int y = j + dy[k];
            if (is_in(x, y)) {
                add_edge(i, j, x, y);
            }
        }
    }
    proc();
    while (q--) {
        scanf("%s", s);
        int len = strlen(s);
        msk[len] = 0;
        for (int i = len - 1; i >= 0; --i) {
            msk[i] = ((1 << (s[i] - '0')) | msk[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n * m; ++i) {
            if (f[i] == 1) {
                continue;
            }
            if (g[i].size() == 0) {
                int l = -1, r = len;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    int qqq = (mask[i] & msk[mid]);
                    if (qqq == msk[mid]) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                if (r == 0) {
                    ans = 1;
                    break;
                }
                if (dfs(i, l)) {
                    ans = 1;
                    break;
                }
            }
        }
        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}