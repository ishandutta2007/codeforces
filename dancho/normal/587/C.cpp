#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, q;

vector<int> g[1 << 17];
int pe[1 << 17][12];

int par[1 << 17][18];
int dep[1 << 17];
int pq[1 << 17][18][12];

// void merge(vector<int> &re, const vector<int> &to, const vector<int> &fr) {
void merge(int re[12], int to[12], int fr[12]) {
    re[0] = 0;
    int i, j;
    i = j = 1;
    // while (i < (int) to.size() && j < (int) fr.size() && re.size() < 10) {
    while (i <= to[0] && j <= fr[0] && re[0] < 10) {
        if (to[i] < fr[j]) {
            re[++re[0]] = to[i++];
        } else {
            re[++re[0]] = fr[j++];
        }
    }
    while (i <= to[0] && re[0] < 10) {
        re[++re[0]] = to[i++];
    }
    while (j <= fr[0] && re[0] < 10) {
        re[++re[0]] = fr[j++];
    }
}

void dfs(int v) {
    memcpy(pq[v][0], pe[v], sizeof(pe[v]));
    for (int j = 1; j < 18; ++j) {
        par[v][j] = par[ par[v][j - 1] ][j - 1];
        merge(pq[v][j], pq[v][j - 1], pq[ par[v][j - 1] ][j - 1]);
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (par[u][0] == -1) {
            par[u][0] = v;
            dep[u] = dep[v] + 1;
            dfs(u);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(pe, 0, sizeof(pe));
    for (int i = 0; i < m; ++i) {
        int p;
        scanf("%d", &p);
        pe[p][++pe[p][0]] = i + 1;
        if (pe[p][0] > 10) {
            sort(pe[p] + 1, pe[p] + pe[p][0] + 1);
            --pe[p][0];
        }
    }
    for (int i = 0; i <= n; ++i) {
        sort(pe[i] + 1, pe[i] + pe[i][0] + 1);
    }
    memset(par, -1, sizeof(par));
    for (int j = 0; j < 18; ++j) {
        par[0][j] = 0;
    }
    par[1][0] = 0;
    dep[0] = -1;
    dep[1] = 0;
    dfs(1);

    for (int i = 0; i < q; ++i) {
        int v, u, a;
        scanf("%d %d %d", &v, &u, &a);
        int re[12];
        re[0] = 0;
        if (dep[v] < dep[u]) {
            swap(v, u);
        }
        int k = 17;
        int tmp[12];
        int st = 0;
        while (dep[v] > dep[u]) {
            while (dep[ par[v][k] ] < dep[u]) {
                --k;
            }
            ++st;
            merge(tmp, re, pq[v][k]);
            memcpy(re, tmp, sizeof(re));
            v = par[v][k];
        }
        if (st > 17) {
            exit(-1);
        }
        k = 17;
        st = 0;
        while (v != u) {
            while (k > 0 && par[v][k] == par[u][k]) {
                --k;
            }
            ++st;
            merge(tmp, re, pq[v][k]);
            merge(re, tmp, pq[u][k]);
            v = par[v][k];
            u = par[u][k];
        }
        if (st > 17) {
            exit(-1);
        }
        merge(tmp, re, pq[v][0]);
        printf("%d", min(tmp[0], a));
        for (int i = 1; i <= min(tmp[0], a); ++i) {
            printf(" %d", tmp[i]);
        }
        printf("\n");
    }
    return 0;
}