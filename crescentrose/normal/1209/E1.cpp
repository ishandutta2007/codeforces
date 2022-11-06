#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
struct node{
    int v[12];
    int mx;
}f[20000];
int T, n, m;
int g[1 << 12], h[1 << 12], c[1 << 12];
int help[1 << 12];
int main() {
    scanf("%d", &T);
    for (int i = 0; i < 12 ; i ++)
        help[1<<i] = i;
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n ; i ++) {
            for (int j = 1; j <= m ; j++){
                int x;
                scanf("%d", &x);
                f[j].v[i - 1] = x;
                f[j].mx = max(f[j].mx, x);
            }
        }
        sort(f + 1, f + m + 1, [](node &a, node & b) {
            return a.mx > b.mx;
        });
        int l = 1;
        while (l < m && f[l + 1].mx == f[l].mx) ++l;
        if (l >= n) {
            printf("%d\n", f[l].mx * n);
        } else {
            l = min(n, m);
            memset(g, 0, sizeof(g));
            for (int i = 1; i <= l; i ++) {
                memset(h, 0, sizeof(h));
                for (int j = 0; j < n; j ++)
                    for (int k = 1; k < (1 << n); k ++) {
                        int x = k;
                        int y = 0;
                        while (x){
                            y += f[i].v[(help[x & -x] + j) % n];
                            x -= x & -x;
                        }
                        h[k] = max(h[k], y);
                    }
                for (int j = 1; j < (1 << n); j ++) {
                    c[j ] =g[j];
                    for (int k = j; k; k = (k - 1) & j)
                        c[j] = max(c[j], g[j - k] + h[k]);
                }
                for (int j = 1; j < (1 << n); j ++)
                    g[j] = c[j];
            }
            printf("%d\n", g[(1 << n) - 1]);
        }
        for (int i = 1; i <= m; i ++)
            f[i].mx = 0;
    }
    return 0;
}