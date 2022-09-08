/**
 *  created: 13/03/2021, 13:05:06
**/

#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") // WINDOWS ONLY

using namespace std;

const int max_n = 1505, inf = 1000111222;
const int max_q = 11;

int q;

struct state {
    int cols[max_q];

    state() {
        memset(cols, 0, sizeof(cols));
    }
};

void combine(state &res, const state &a, const state &b, const state &c, const state &d) {
    if (a.cols[q] || b.cols[q] || c.cols[q] || d.cols[q]) {
        res.cols[q] = 1;
        return;
    }
    int cnt = 0;
    int pa = 0, pb = 0, pc = 0, pd = 0;
    while (a.cols[pa] || b.cols[pb] || c.cols[pc] || d.cols[pd]) {
        if (cnt == q) {
            res.cols[q] = 1;
            return;
        }
        int x = max({a.cols[pa], b.cols[pb], c.cols[pc], d.cols[pd]});
        res.cols[cnt++] = x;
        pa += x == a.cols[pa];
        pb += x == b.cols[pb];
        pc += x == c.cols[pc];
        pd += x == d.cols[pd];
    }
    while (cnt <= q) {
        res.cols[cnt++] = 0;
    }
}

const int max_c = 5;
const bool debug = 0;

int n, a[max_n][max_n], mx[max_n][max_n];
bool big[max_n][max_n];
state s[max_c][max_n][max_n];
int ans[max_n];

int shift = 6;

bool check(int x, int y, int len) {
    if (len <= 1) {
        return true;
    }
    if (x + len > n || y + len > n) {
        return false;
    }
    int lev = 31 - __builtin_clz(len);
    assert((1 << lev) <= len);
    state res;
    combine(res, s[lev - shift][x][y], s[lev - shift][x + len - (1 << lev)][y],
            s[lev - shift][x][y + len - (1 << lev)], s[lev - shift][x + len - (1 << lev)][y + len - (1 << lev)]);
    if (res.cols[q]) {
        return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n = 1500;
        q = 10;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = rand() % 10;
            }
        }
    } else {
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
    }
    int q1 = 0, q2 = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s[q1][i][j].cols[0] = a[i][j];
        }
    }
    for (int lev = 1; lev < 7; ++lev) {
        --lev;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                combine(s[q2][i][j], s[q1][i][j], s[q1][min(n, i + (1 << lev))][j],
                        s[q1][i][min(n, j + (1 << lev))], s[q1][min(n, i + (1 << lev))][min(n, j + (1 << lev))]);

            }
        }
        ++lev;
        swap(q1, q2);
    }
    assert(!q1);
    for (int lev = 7; lev < 11; ++lev) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const int shift = (1 << (lev - 1));
                combine(s[lev - 6][i][j], s[lev - 7][i][j], s[lev - 7][min(n, i + shift)][j],
                        s[lev - 7][i][min(n, j + shift)], s[lev - 7][min(n, i + shift)][min(n, j + shift)]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int lev = 10; lev >= 6; --lev) {
                if (check(i, j, mx[i][j] + (1 << lev))) {
                    mx[i][j] += (1 << lev);
                }
            }
            if (mx[i][j]) {
                for (int lev = 5; lev >= 0; --lev) {
                    if (check(i, j, mx[i][j] + (1 << lev))) {
                        mx[i][j] += (1 << lev);
                    }
                }
                ++ans[mx[i][j]];
            }
        }
    }



    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<int> v{a[i][j]};
            if (i + 1 < n) {
                v.push_back(a[i + 1][j]);
            }
            if (j + 1 < n) {
                v.push_back(a[i][j + 1]);
            }
            if (j + 1 < n && i + 1 < n) {
                v.push_back(a[i + 1][j + 1]);
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            reverse(v.begin(), v.end());
            s[q1][i][j] = state();
            if (v.size() > q) {
                s[q1][i][j].cols[q] = 1;
            } else {
                for (int k = 0; k < v.size(); ++k) {
                    s[q1][i][j].cols[k] = v[k];
                }
            }
        }
    }
    for (int lev = 1; lev < 5; ++lev) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                combine(s[lev][i][j], s[lev - 1][i][j], s[lev - 1][min(n, i + (1 << lev))][j],
                        s[lev - 1][i][min(n, j + (1 << lev))], s[lev - 1][min(n, i + (1 << lev))][min(n, j + (1 << lev))]);
            }
        }
    }
    shift = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!mx[i][j]) {
                for (int lev = 5; lev >= 0; --lev) {
                    if (check(i, j, mx[i][j] + (1 << lev))) {
                        mx[i][j] += (1 << lev);
                    }
                }
                ++ans[mx[i][j]];
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        ans[i - 1] += ans[i];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}