#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
char t[1024][1024];
bool us[16];
set<int> vis;

vector< vector<int> > g;

inline void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

inline int co(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return -1;
    }
    return x * m + y;
}

inline void oc(int k, int &x, int &y) {
    x = k / m;
    y = k % m;
}

void go(int s, char fi) {
    if (vis.find(s) != vis.end()) {
        return;
    }
    vis.insert(s);
    int x, y;
    oc(s, x, y);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && t[nx][ny] >= '0' && t[nx][ny] <= '9') {
            us[t[nx][ny] - '0'] = 1;
        }
    }
    t[x][y] = fi;
    for (int i = 0; i < (int) g[s].size(); ++i) {
        go(g[s][i], fi);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", t[i]);
    }
    g.resize(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int s = co(i, j);
            if (t[i][j] == '#' || g[s].size()) {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                int l = co(nx, ny);
                if (l == -1) continue;
                if (t[nx][ny] == '#' || g[l].size()) {
                    continue;
                }
                add_edge(l, s);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int s = co(i, j);
            if (t[i][j] == '#' || g[s].size()) {
                continue;
            }
            bool ok = false;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                int l = co(nx, ny);
                if (l == -1) continue;
                if (t[nx][ny] == '#') {
                    continue;
                }
                add_edge(l, s);
                ok = true;
                break;
            }
            if (!ok) {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (t[i][j] != '.') {
                continue;
            }
            int s = co(i, j);
            memset(us, 0, sizeof(us));
            vis.clear();
            go(s, 'x');
            for (int k = 0; k < 10; ++k) {
                if (!us[k]) {
                    vis.clear();
                    go(s, '0' + k);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n", t[i]);
    }
}