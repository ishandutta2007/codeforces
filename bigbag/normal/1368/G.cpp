#include <bits/stdc++.h>

using namespace std;

const int max_n = 200111, inf = 1000111222;

template<typename T>
struct segment_tree {
    T f[4 * max_n];
    pair<T, int> mn[4 * max_n];

    pair<T, int> merge(const pair<T, int> &a, const pair<T, int> &b) {
        pair<T, int> res(min(a.first, b.first), 0);
        if (a.first == res.first) {
            res.second += a.second;
        }
        if (b.first == res.first) {
            res.second += b.second;
        }
        return res;
    }

    void build_zeros(int v, int l, int r) {
        f[v] = 0;
        if (l == r) {
            mn[v] = {0, 1};
            return;
        }
        int mid = (l + r) / 2;
        build_zeros(2 * v, l, mid);
        build_zeros(2 * v + 1, mid + 1, r);
        mn[v] = merge(mn[2 * v], mn[2 * v + 1]);
    }

    void push(int v, int l, int r, int mid) {
        if (f[v]) {
            mn[2 * v].first += f[v];
            mn[2 * v + 1].first += f[v];
            f[2 * v] += f[v];
            f[2 * v + 1] += f[v];
            f[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T value) {
        if (tl == l && tr == r) {
            f[v] += value;
            mn[v].first += value;
            return;
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            update(2 * v, tl, mid, l, r, value);
        } else if (l > mid) {
            update(2 * v + 1, mid + 1, tr, l, r, value);
        } else {
            update(2 * v, tl, mid, l, mid, value);
            update(2 * v + 1, mid + 1, tr, mid + 1, r, value);
        }
        mn[v] = merge(mn[2 * v], mn[2 * v + 1]);
    }

    pair<T, int> get_min(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return mn[v];
        }
        int mid = (tl + tr) / 2;
        push(v, tl, tr, mid);
        if (r <= mid) {
            return get_min(2 * v, tl, mid, l, r);
        } else if (l > mid) {
            return get_min(2 * v + 1, mid + 1, tr, l, r);
        }
        return merge(get_min(2 * v, tl, mid, l, mid), get_min(2 * v + 1, mid + 1, tr, mid + 1, r));
    }

    int get_cnt(int v, int tl, int tr, int l, int r, T x) {
        pair<T, int> p = get_min(v, tl, tr, l, r);
        if (p.first == x) {
            return p.second;
        }
        return 0;
    }
};

int n, m, is_root[2][max_n], sz[max_n];
vector<int> num[max_n], g[2][max_n];
string s[max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int l[max_n], r[max_n], curt = -1;

void dfs(int v) {
    l[v] = ++curt;
    for (int to : g[1][v]) {
        dfs(to);
    }
    r[v] = curt;
}

segment_tree<int> t;
long long ans;
int cnt;

void solve(int v) {
    int add = t.get_cnt(1, 0, cnt - 1, l[v], r[v], 0);
    sz[v] = 1;
    t.update(1, 0, cnt - 1, l[v], r[v], 1);
    for (int to : g[0][v]) {
        solve(to);
        sz[v] += sz[to];
    }
    t.update(1, 0, cnt - 1, l[v], r[v], -1);
    ans += 1LL * add * sz[v];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        num[i].resize(m, -1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'L') {
                num[i][j] = num[i][j + 1] = cnt++;
            }
            if (s[i][j] == 'U') {
                num[i][j] = num[i + 1][j] = cnt++;
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        is_root[0][i] = 1;
        is_root[1][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tp = (i ^ j) % 2;
            int x = i, y = j;
            if (s[x][y] == 'L') {
                y += 2;
            } else if (s[x][y] == 'R') {
                y -= 2;
            } else if (s[x][y] == 'U') {
                x += 2;
            } else {
                x -= 2;
            }
            if (is_in(x, y)) {
                g[tp][num[x][y]].push_back(num[i][j]);
                is_root[tp][num[i][j]] = 0;
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        if (is_root[1][i]) {
            dfs(i);
        }
    }
    t.build_zeros(1, 0, cnt - 1);
    for (int i = 0; i < cnt; ++i) {
        if (is_root[0][i]) {
            solve(i);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}