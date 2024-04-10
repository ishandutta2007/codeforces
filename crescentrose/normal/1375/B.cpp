#include <algorithm>
#include <cstdio>
#include <deque>
using namespace std;
int n, m;
int t;
int a[311][311], c[311][311];
int v[311][311];
int b[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int main() {
    scanf("%d", &t);
    while (t -- ) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                scanf("%d", &a[i][j]), c[i][j] = a[i][j];
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++) {
                v[i][j] = 0;
                for (int k = 0;k < 4; k ++)
                    if (a[b[k][0] + i][b[k][1] + j])
                        v[i][j] ++;
                v[i][j] -= a[i][j];
                if (a[i][j] && v[i][j] > 0)
                    a[i][j] += v[i][j], v[i][j] = 0;
            }
        for (int i = 1; i <= n; i ++)
            for (int j =1; j <= m; j ++)
                if (!a[i][j]) {
                    bool sig = 0;
                    for (int k = 0;k < 4; k ++)
                        if (a[b[k][0] + i][b[k][1] + j] && v[b[k][0] + i][b[k][1] + j] < 0) {
                            v[b[k][0] + i][b[k][1] + j] ++;
                            sig = 1;
                        }
                    a[i][j] = sig;
                    v[i][j] = 0;
                }
        bool sig = 1;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++) {
                v[i][j] = 0;
                for (int k = 0;k < 4; k ++)
                    if (a[b[k][0] + i][b[k][1] + j])
                        v[i][j] ++;
                v[i][j] -= a[i][j];
                if (a[i][j] && v[i][j] > 0)
                    a[i][j] += v[i][j], v[i][j] = 0;
                if (a[i][j] && v[i][j] < 0) {
                    sig = 0;
                }
            }
        if (!sig) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= m; j ++)
                    printf("%d%c", a[i][j], " \n"[j == m]);
        }
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                a[i][j] = 0;
    }
    return 0;
}