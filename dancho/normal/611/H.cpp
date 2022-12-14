#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000000;

struct MaxFlow {
    struct Edge {
        int to, c, f, ne;
        Edge(int to, int c, int f, int ne) : to(to), c(c), f(f), ne(ne) {}
    };

    int n;
    vector<Edge> ed;
    vector<int> fi;

    MaxFlow(int n) : n(n), ed(), fi(n, -1) {}

    void add_edge(int a, int b, int c) {
        ed.push_back(Edge(b, c, 0, fi[a]));
        fi[a] = (int) ed.size() - 1;
        ed.push_back(Edge(a, c, 0, fi[b]));
        fi[b] = (int) ed.size() - 1;
    }

    vector<char> us;

    int dfs(int v, int tar, int cur, int minv = 1) {
        if (v == tar) return cur;
        if (us[v]) return 0;
        us[v] = 1;
        for (int i = fi[v]; i != -1; i = ed[i].ne) {
            if (ed[i].c < minv) {
                continue;
            }
            int tmp = dfs(ed[i].to, tar, min(cur, ed[i].c), minv);
            if (tmp > 0) {
                ed[i].c -= tmp;
                ed[i].f += tmp;
                ed[i ^ 1].c += tmp;
                ed[i ^ 1].f -= tmp;
                return tmp;
            }
        }
        return 0;
    }

    int flow(int s, int t) {
        int ans = 0, cur, mv = 1024;
        for (; mv; mv /= 2) {
            do {
                us = vector<char>(n);
                cur = dfs(s, t, INF, mv);
                ans += cur;
            } while (cur);
        }
        return ans;
    }
};

int nd(int x) {
    int di = -1;
    while (x) {
        ++di;
        x /= 10;
    }
    return di;
}

int n;
int ed[16][16];

int par[1 << 20];
int lid[6];

bool gen_parent(int v) {
    if (v > n) {
        // Check if it is connected
        //
        for (int i = 1; i <= n; i *= 10) {
            int st = 0;
            int v = i;
            while (st < 7) {
                ++st;
                v = par[v];
            }
            if (v != 0) {
                return false;
            }
        }
        // printf("Found tree!\n");
        MaxFlow f(6 + 6 * 6 + 2);
        int s = 6 + 6 * 6;
        int t = s + 1;
        int tot = 0;
        for (int i = 1; i <= n; i *= 10) {
            int cnt = 0;
            if (i * 10 <= n) {
                cnt = 9 * i - 1;
            } else {
                cnt = n - i;
            }
            tot += cnt;
            int digs = nd(i);
            f.add_edge(s, digs, cnt);
            for (int k = 0; k < 6; ++k) {
                f.add_edge(digs, 6 + k * 6 + digs, ed[k][digs]);
                f.add_edge(digs, 6 + digs * 6 + k, ed[digs][k]);
            }
        }
        // printf("TOT %d\n", tot);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                f.add_edge(6 + i * 6 + j, t, ed[i][j]);
            }
        }
        if (f.flow(s, t) == tot) {
            for (int j = 1; j <= n; j *= 10) {
                int k = nd(j);
                int lid = j + 1;
                for (int i = f.fi[k]; i != -1; i = f.ed[i].ne) {
                    if (f.ed[i].f > 0) {
                        int ot = f.ed[i].to - 6;
                        for (int l = 1; l <= n; l *= 10) {
                            int d1 = k;
                            int d2 = nd(l);
                            // printf("Found edge! %d -> %d\n", j, l);
                            if (d1 > d2) {
                                swap(d1, d2);
                            }
                            if (d1 * 6 + d2 == ot) {
                                while (f.ed[i].f) {
                                    par[lid++] = l;
                                    --f.ed[i].f;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }
    for (int i = 1; i <= n; i *= 10) {
        par[v] = i;
        int d1 = nd(i);
        int d2 = nd(v);
        if (d1 > d2) {
            swap(d1, d2);
        }
        if (ed[d1][d2]) {
            --ed[d1][d2];
            if (gen_parent(v * 10)) {
                return true;
            }
            ++ed[d1][d2];
        }
    }
    return false;
}

int main() {
    char b1[16], b2[16];
    scanf("%d", &n);
    memset(ed, 0, sizeof(ed));
    for (int i = 0; i < n - 1; ++i) {
        scanf("%s %s", b1, b2);
        int l = strlen(b1) - 1;
        int k = strlen(b2) - 1;
        if (l > k) {
            swap(l, k);
        }
        ++ed[l][k];
    }

    memset(par, -1, sizeof(par));
    par[0] = 0;
    int digs = nd(n);
    // Generate all trees between 1, 10, 100, ..., 100000.
    // 1 is root. 5 others have one parent (among 6 values)
    //

    par[1] = 0;
    if (!gen_parent(10)) {
        printf("-1\n");
    } else {
        for (int i = 2; i <= n; ++i) {
            printf("%d %d\n", i, par[i]);
        }
    }
    return 0;
}