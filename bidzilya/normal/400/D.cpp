#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
typedef long long ll;

const int inf = 1e9;
const int max_k = 555;
const int max_n = 1e5 + 100;

int n, m, k;
int c[max_k];
int tp[max_n];
int d[max_k][max_k];

vector<vector<int> > g;
int cmp[max_n];
int cmps;

void dfs(int v) {
    cmp[v] = cmps;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i];
        if (!cmp[u])
            dfs(u);
    }
}

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        for (int i = 0; i < k; ++i)
            scanf("%d", c + i);
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                d[i][j] = inf;
        int all_sum = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = all_sum; j < all_sum + c[i]; ++j)  
                tp[j] = i;
            all_sum += c[i];
        }
        for (int i = 0; i < k; ++i)
            if (c[i] == 1) 
                d[i][i] = 0;
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; ++i) {
            int v1, v2, x;
            scanf("%d%d%d", &v1, &v2, &x);
            --v1; --v2;
            if (x == 0) {
                g[v1].push_back(v2);
                g[v2].push_back(v1);
            }
            v1 = tp[v1];
            v2 = tp[v2];
            d[v1][v2] = d[v2][v1] = min(d[v1][v2], x);
        }
        cmps = 0;
        for (int i = 0; i < n; ++i)
            cmp[i] = 0;
        for (int i = 0; i < n; ++i)
            if (!cmp[i]) {
                ++cmps;
                dfs(i);
            }
        bool good = true;
        all_sum = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = all_sum + 1; j < all_sum + c[i]; ++j)
                if (cmp[j] != cmp[all_sum]) {
                    good = false;
                    break;
                }
            all_sum += c[i];
        } 
        if (!good) {
            printf("No\n");
            continue;
        }
        for (int t = 0; t < k; ++t)
            for (int i = 0; i < k; ++i)
                for (int j = 0; j < k; ++j)
                    d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
        printf("Yes\n");
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (d[i][j] == inf) d[i][j] = -1;
                printf("%d ", d[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}