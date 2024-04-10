#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

template<typename T, size_t max_lev, size_t max_n>
struct sparse_table {
    int num[max_n];
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
        for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
            for (int j = i; j <= n && j < i * 2; ++j) {
                num[j] = x;
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return inf;
        }
        int lev = num[r - l + 1];
        return min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

template<typename T>
struct segment_tree {
    T mn[4 * max_n];

    void build(int v, int l, int r, T a[]) {
        if (l == r) {
            mn[v] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, a);
        build(2 * v + 1, mid + 1, r, a);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    void update(int v, int l, int r, int pos, T value) {
        if (l == r) {
            mn[v] = value;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos, value);
        } else {
            update(2 * v + 1, mid + 1, r, pos, value);
        }
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }

    T get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return min(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }
};

template<typename T>
struct segment_tree2 {
    T mn[4 * max_n];

    void clr(int v, int l, int r) {
        mn[v] = inf;
        if (l == r) {
            return;
        }
        int mid = (l + r) / 2;
        clr(2 * v, l, mid);
        clr(2 * v + 1, mid + 1, r);
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            mn[v] = min(mn[v], value);
            return;
        }
        int mid = (tl + tr) / 2;
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
    }

    T get_value(int v, int l, int r, int pos) {
        if (l == r) {
            return mn[v];
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            return min(mn[v], get_value(2 * v, l, mid, pos));
        } else {
            return min(mn[v], get_value(2 * v + 1, mid + 1, r, pos));
        }
    }
};

int t, n, a[max_n], ra[max_n], nxt[max_n];
long long s1[max_n], s2[max_n];
int dp[max_n][2];
segment_tree<int> t1;
segment_tree2<int> t2;
map<long long, int> last[2];
sparse_table<long long, 19, max_n / 2> mn[2];

int find_pos(int i, long long from, long long to, long long s[]) {
    int l = 0, r = i;
    while (r - l > 1) {
        int pos = (l + r) / 2;
        int last_mn = pos - 1, last_mx = pos - 1;
        if (pos % 2 != i % 2) {
            ++last_mn;
        } else {
            ++last_mx;
        }
        long long MN = mn[(i % 2) ^ 1].get_min(last_mn / 2, (i - 1) / 2);
        long long MX = -mn[(i % 2)].get_min(last_mx / 2, i / 2);
        MN += s[i] - 1;
        MX += s[i] + 1;
        if (max(MX, from) <= min(MN, to)) {
            r = pos;
        } else {
            l = pos;
        }
    }
    return r;
    for (int j = i; j >= 1; --j) {
        if (j % 2 == i % 2) {
            to = min(to, s[i] + s[j - 1] - 1);
        } else {
            from = max(from, 1 + s[i] - s[j - 1]);
        }
        if (from > to) {
            return j + 1;
        }
    }
    return 1;
}

void clr() {
    last[0].clear();
    last[1].clear();
}

void update(int &x, int y) {
    x = min(x, y);
}

void init_sparse_table2(long long s[max_n]) {
    vector<long long> v[2];
    for (int i = 0; i <= n; ++i) {
        v[i % 2].push_back(s[i]);
    }
    mn[0].init(v[0].size(), v[0].data());
    mn[1].init(v[1].size(), v[1].data());
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            ra[i] = a[i];
        }
        reverse(ra + 1, ra + n + 1);
        for (int i = 1; i <= n; ++i) {
            s1[i] = a[i] - s1[i - 1];
            s2[i] = ra[i] - s2[i - 1];
        }
        init_sparse_table2(s2);
        for (int i = 1; i <= n; ++i) {
            if (a[i] % 2 == 0) {
                int x = a[i] / 2;
                nxt[i] = n + 1 - find_pos(n + 1 - i, x, x, s2);
            }
        }
        init_sparse_table2(s1);
        t1.update(1, 0, n, 0, 0);
        t2.clr(1, 0, n);
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i][1] = inf;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] % 2 == 0) {
                const int x = a[i] / 2;
                int pos = find_pos(i, x, x, s1);
                dp[i][1] = t1.get_min(1, 0, n, pos - 1, i - 1) + i;

                for (int z = -1; z <= 1; z += 2) {
                    auto it = last[(i % 2) ^ (z == -1)].find(2 * z * (s1[i] - x));
                    if (it != last[(i % 2) ^ (z == -1)].end() && it->second >= pos) {
                        int res = dp[it->second][1] + i - it->second - 1;
                        update(dp[i][1], res);
                    }
                }

                pos = nxt[i];
                if (i + 1 <= pos) {
                    t2.update(1, 0, n, i + 1, pos, dp[i][1] - i);
                }
            }
            int pos = find_pos(i, 1, a[i] - 1, s1);
            update(dp[i][0], t2.get_value(1, 0, n, i) + i);
            update(dp[i][0], t1.get_min(1, 0, n, pos - 1, i - 1) + i + 1);
            update(dp[i][0], dp[i][1]);

            t1.update(1, 0, n, i, dp[i][0] - i);
            last[i % 2][a[i] - 2 * s1[i - 1]] = i;
        }
        printf("%d\n", dp[n][0]);
        clr();
    }
    return 0;
}