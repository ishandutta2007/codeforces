#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5000;
bool f[N][N][2];
int n;
int T;
int a[N];
int nxt[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n * 2; i++){
            scanf("%d", &a[i]);
            for (int j = 0; j <= n * 2; j ++)
                f[i][j][0] = f[i][j][1] = 0;
        }
        f[0][0][0] = f[0][0][1] = 1;
        for (int i = n * 2; i >= 1; i --) {
            int x = i;
            while (x + 1 <= n * 2 && a[x + 1] < a[i])
                x++;
            nxt[i] = x;
        }
        for (int i = 0; i < 2 * n; i ++)
            for (int j = 0; j <= n; j ++) {
                for (int k = 0; k < 2; k++)
                    if (f[i][j][k]) {
                        if (a[i + 1] > a[i])
                            f[i][j][k ^ 1] = 1;
                    }
                for (int k = 0; k < 2; k++)
                    if (f[i][j][k]) {
                        if (nxt[i] != i) {
                            f[nxt[i]][j + k * (nxt[i] - i)][k] = 1;
                        } else {
                            f[i + 1][j + k][k] = 1;
                        }
                    }
            }
        if (f[n * 2][n][0] || f[n * 2][n][1])
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}