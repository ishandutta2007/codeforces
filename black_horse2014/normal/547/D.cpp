#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#define pb push_back

#define X first
#define Y second

#define N 200005

PII P[N];
int id[N], col[N];

VI adj[N];
VI Vx[N], Vy[N];

bool cmp(int u, int v) {
    return P[u] < P[v];
}

void DFS(int u, int c) {
    col[u] = c;
    for (int i = adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];
        if (col[v] != -1) continue;
        DFS(v, c ^ 1);
    }
}

int main() {

    int i, j, u, v, n;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &u, &v);
        P[i] = PII(u, v);
        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp);
    for (i = 1; i <= n; i++) {
        j = id[i];
        Vx[P[j].X].push_back(j);
        Vy[P[j].Y].push_back(j);
    }

    for (i = 1; i <= 200000; i++) {
        if (Vx[i].size() > 1) {
            for (j = 0; j < Vx[i].size() - 1; j += 2) {
                u = Vx[i][j], v = Vx[i][j + 1];
                adj[u].pb(v), adj[v].pb(u);
            }
        }
        if (Vy[i].size() > 1) {
            for (j = 0; j < Vy[i].size() - 1; j += 2) {
                u = Vy[i][j], v = Vy[i][j + 1];
                adj[u].pb(v), adj[v].pb(u);
            }
        }
    }

    memset(col, -1, sizeof col);
    for (i = 1; i <= n; i++) if (col[i] == -1) {
        DFS(i, 0);
    }

    for (i = 1; i <= n; i++) {
        if (col[i] == 0) putchar('r');
        else putchar('b');
    }

    return 0;
}