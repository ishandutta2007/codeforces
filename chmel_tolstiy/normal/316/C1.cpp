#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int n, m;
int a[80][80];

struct edge {
    int to, cs, cp, id_r;
    edge(int to, int cs, int cp, int id_r): to(to), cs(cs), cp(cp), id_r(id_r) {}
};

vector<edge> g[10000];

int ID(int i, int j) {
    return i * m + j;
}

void add(int x, int y, int cs) {
    g[x].push_back(edge(y, +cs, 1, g[y].size()));
    g[y].push_back(edge(x, -cs, 0, g[x].size() - 1));
}

int q[1<<20];
int qn, ql;

int len(int S, int T) {
    vector<int> d(T + 1, 1<<30);
    vector<int> f(T + 1);
    vector<int> e(T + 1);
    vector<int> u(T + 1);
    d[S] = 0;
    qn = ql = 1<<19;
    q[ql++] = S;
    while (qn < ql) {
        int x = q[qn++];
        if (u[x]) continue;
        u[x] = 1;
        for (int i = 0; i < g[x].size(); ++i) if (g[x][i].cp) {
            int y = g[x][i].to;
            if (d[y] > d[x] + g[x][i].cs) {

                u[y] = 0;
                d[y] = d[x] + g[x][i].cs;
                f[y] = x;
                e[y] = i;

                if (g[x][i].cp <= 0) q[--qn] = y;
                else q[ql++] = y;
            }
        }
    }

    int x = T;
    while (x != S) {
        int y = f[x];
        g[y][e[x]].cp--;
        g[x][g[y][e[x]].id_r].cp++;
        x = y;
    }

    return d[T];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    if (m & 1) {
        for (int i = 0; i < 80; ++i) for (int j = i + 1; j < 80; ++j) swap(a[i][j], a[j][i]);
        swap(n, m);
    }
    
    for (int i = 0; i < n; ++i) for (int j = (i & 1); j < m; j += 2) {
        for (int k = 0; k < 4; ++k) {
            size_t ii = i + di[k];
            size_t jj = j + dj[k];
            if (ii < n && jj < m) {
                add(ID(i, j), ID(ii, jj), a[i][j] != a[ii][jj]);
            }
        }
    }
    int S = n * m;
    int T = n * m + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i+j) & 1) {
                add(ID(i, j), T, 0);
            } else {
                add(S, ID(i, j), 0);
            }
        }
    }

    int res = 0;
    for (int it = 0; it < n * m / 2; ++it) {
        res += len(S, T);
    }
    cout << res << endl;
    return 0;
}