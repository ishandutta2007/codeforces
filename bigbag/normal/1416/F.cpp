#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dirs[] = {'U', 'D', 'L', 'R'};

int t, n, m, pl[max_n], pr[max_n];
bool used[max_n], bad_ver[max_n];
vector<int> a[max_n], num[max_n], g[max_n], v, ans[max_n];
vector<char> is_bad[max_n], dir[max_n];
vector<pair<int, int>> all[max_n];

void init() {
    for (int i = 0; i < v.size(); ++i) {
        all[i].clear();
    }
    v.clear();
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        dir[i].resize(m);
        ans[i].assign(m, 0);
        is_bad[i].assign(m, 0);
        num[i].assign(m, 0);
    }
}

int compress(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

bool dfs1(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (pr[to] == -1) {
            pr[to] = v;
            pl[v] = to;
            return true;
        }
    }
    for (int to : g[v]) {
        if (dfs1(pr[to])) {
            pr[to] = v;
            pl[v] = to;
            return true;
        }
    }
    return false;
}

bool dfs2(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (pl[to] == -1) {
            pl[to] = v;
            pr[v] = to;
            return true;
        }
    }
    for (int to : g[v]) {
        if (!bad_ver[pl[to]]) {
            pr[pl[to]] = -1;
            pl[to] = v;
            pr[v] = to;
            return true;
        }
    }
    for (int to : g[v]) {
        if (dfs2(pl[to])) {
            pl[to] = v;
            pr[v] = to;
            return true;
        }
    }
    return false;
}

char get_dir(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        if (x == dx[i] && y == dy[i]) {
            return dirs[i];
        }
    }
}

void make_cycle(int x1, int y1, int x2, int y2) {
    dir[x1][y1] = get_dir(x2 - x1, y2 - y1);
    dir[x2][y2] = get_dir(x1 - x2, y1 - y2);
    ans[x1][y1] = 1;
    ans[x2][y2] = a[x1][y1] - 1;
}

bool solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            all[compress(a[i][j])].push_back({i, j});
            is_bad[i][j] = true;
            for (int k = 0; k < 4; ++k) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (is_in(nx, ny) && a[i][j] > a[nx][ny]) {
                    is_bad[i][j] = false;
                }
            }
        }
    }
    for (int X : v) {
        const int x = compress(X);
        int verts = 0;
        for (auto p : all[x]) {
            num[p.first][p.second] = verts++;
        }
        for (int i = 0; i < verts; ++i) {
            g[i].clear();
            pl[i] = pr[i] = -1;
            bad_ver[i] = is_bad[all[x][i].first][all[x][i].second];
        }
        for (auto p : all[x]) {
            for (int k = 0; k < 4; ++k) {
                const int nx = p.first + dx[k], ny = p.second + dy[k];
                if (is_in(nx, ny) && a[p.first][p.second] == a[nx][ny]) {
                    g[num[p.first][p.second]].push_back(num[nx][ny]);
                }
            }
        }
        int left = 0, right = 1;
        for (int run = 1; run; ) {
            run = 0;
            memset(used, 0, verts);
            for (auto p : all[x]) {
                const int v = num[p.first][p.second];
                if ((p.first ^ p.second) % 2 == left && is_bad[p.first][p.second] && pl[v] == -1) {
                    if (dfs1(v)) {
                        run = 1;
                    }
                }
            }
        }
        for (int run = 1; run; ) {
            run = 0;
            memset(used, 0, verts);
            for (auto p : all[x]) {
                const int v = num[p.first][p.second];
                if ((p.first ^ p.second) % 2 == right && is_bad[p.first][p.second] && pr[v] == -1) {
                    if (dfs2(v)) {
                        run = 1;
                    }
                }
            }
        }
        for (auto p : all[x]) {
            const int v = num[p.first][p.second];
            if (is_bad[p.first][p.second] && pl[v] == -1 && pr[v] == -1) {
                return false;
            }
        }
        for (auto p : all[x]) {
            const int v = num[p.first][p.second];
            if ((p.first ^ p.second) % 2 == left && pl[v] != -1) {
                make_cycle(p.first, p.second, all[x][pl[v]].first, all[x][pl[v]].second);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] == 0) {
                for (int k = 0; k < 4; ++k) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (is_in(nx, ny) && a[i][j] > a[nx][ny]) {
                        dir[i][j] = dirs[k];
                        ans[i][j] = a[i][j] - a[nx][ny];
                        break;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < n; ++i) {
            for (int &x : a[i]) {
                scanf("%d", &x);
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (solve()) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    printf("%d ", ans[i][j]);
                }
                puts("");
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    printf("%c ", dir[i][j]);
                }
                puts("");
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}