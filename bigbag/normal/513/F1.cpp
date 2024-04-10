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

const int max_n = 15;
const int max_v = 4 * max_n * max_n;
const long long inf = 1111111111111111111;

struct edge {
    int v, c, f, numr;
    edge() {
    }
    edge(int v, int c, int f, int numr) : v(v), c(c), f(f), numr(numr) {
    }
};

int n, m, k, k1, k2, x[2][max_v], y[2][max_v], t[2][max_v], used[max_v];
long long dist[max_v][max_n][max_n];
string s[max_n];
vector<edge> g[max_v];//SIZE can be 2 * max_N!!!

void add_edge(int u, int v, int c) {
    //cout << u << " -> " << v << endl;
    int rg1 = g[v].size();
    int rg2 = g[u].size();
    g[u].push_back(edge(v, c, 0, rg1));
    g[v].push_back(edge(u, 0, 0, rg2));
}

bool dfs(int v, int t, int fl) {
    if (v == t) {
        return true;
    }
    if (used[v] == 1) {
        return false;
    }
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i].c >= g[v][i].f + fl && dfs(g[v][i].v, t, fl)) {
            g[v][i].f += fl;
            g[g[v][i].v][g[v][i].numr].f -= fl;
            return true;
        }
    }
    return false;
}

bool check(long long x) {
    for (int i = 0; i < max_v; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num = 2 * (i * m + j);
            add_edge(num, num + 1, 1);
        }
    }
    //cout << endl;
    int s = 2 * n * m + 2 * k;
    int t = s + 1;
    for (int i = 0; i < k; ++i) {
        add_edge(s, 2 * n * m + i, 1);
        add_edge(2 * n * m + k + i, t, 1);
    }
    //cout << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int w = 0; w < m; ++w) {
                int num = 2 * (j * m + w);
                if (dist[i][j][w] > -1 && x >= dist[i][j][w]) {
                    add_edge(2 * n * m + i, num, 1);
                }
            }
        }
    }
    //cout << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int w = 0; w < m; ++w) {
                int num = 2 * (j * m + w) + 1;
                if (dist[i + k][j][w] > -1 && x >= dist[i + k][j][w]) {
                    add_edge(num, 2 * n * m + k + i, 1);
                }
            }
        }
    }
    //cout << endl;
    memset(used, 0, sizeof(used));
    int res = 0;
    while (dfs(s, t, 1)) {
        memset(used, 0, sizeof(used));
        ++res;
    }
    return res == k;
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(int num, int poz) {
    int stx = x[num][poz - num * k];
    int sty = y[num][poz - num * k];
    int tt = t[num][poz - num * k];
    dist[poz][stx][sty] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(stx, sty));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_in(nx, ny) && s[nx][ny] == '.' && dist[poz][nx][ny] == -1) {
                dist[poz][nx][ny] = dist[poz][x][y] + tt;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k1 >> k2;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int st1 = 0, st2 = 0;
    if (k1 + 1 == k2) {
        k = k2;
        cin >> x[0][0] >> y[0][0] >> t[0][0];
        st1 = 1;
    } else if (k2 + 1 == k1) {
        k = k1;
        cin >> x[1][0] >> y[1][0] >> t[1][0];
        st2 = 1;
    } else {
        cout << -1 << endl;
        return 0;
    }
    for (int i = st1; i < k; ++i) {
        cin >> x[0][i] >> y[0][i] >> t[0][i];
    }
    for (int i = st2; i < k; ++i) {
        cin >> x[1][i] >> y[1][i] >> t[1][i];
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < k; ++i) {
        --x[0][i];
        --x[1][i];
        --y[0][i];
        --y[1][i];
        bfs(0, i);
        bfs(1, k + i);
    }
    long long l = -1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == inf) {
        r = -1;
    }
    cout << r << endl;
    return 0;
}