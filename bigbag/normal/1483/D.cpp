/**
 *  created: 21/03/2021, 16:29:00
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 606;
const long long inf = 1000111222000111222LL;
const int max_m = max_n * max_n / 2;

int n, m, from[max_m], to[max_m], len[max_m];
long long dist[max_n][max_n], val[max_n][max_n];

long long get_max(int A, int B) {
    long long res = -inf;
    for (int v = 0; v < n; ++v) {
        if (val[A][v] != -inf && dist[B][v] != inf) {
            res = max(res, val[A][v] - dist[B][v]);
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
            val[i][j] = -inf;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &from[i], &to[i], &len[i]);
        --from[i];
        --to[i];
        dist[from[i]][to[i]] = dist[to[i]][from[i]] = len[i];
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        --u;
        --v;
        for (int A = 0; A < n; ++A) {
            if (dist[A][u] != inf) {
                val[A][v] = max(val[A][v], l - dist[A][u]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        long long mx = max(get_max(from[i], to[i]), get_max(to[i], from[i]));
        if (len[i] <= mx) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}