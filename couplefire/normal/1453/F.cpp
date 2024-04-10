#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn = 3005;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
 
int a[maxn];
int f[maxn][maxn];
int suf[maxn][maxn];
int sum[maxn];
int dif[maxn * 2];
 
int main() {
 
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        a[n] = 0;
 
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) {
                f[i][j] = inf;
                suf[i][j] = inf;
            }
        }
 
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                dif[j] = 0;
                sum[j] = 0;
            }
            for (int j = i + 1; j <= i + a[i]; j++) {
                if (a[j] == 0) continue;
                dif[j]++; dif[j + a[j] + 1]--;
            }
            for (int j = i + 1; j <= i + a[i]; j++) {
                sum[j] = sum[j - 1] + dif[j];
            }
 
            if (a[i] == 0) continue;
            if (i + a[i] >= n) {
                f[i][n + 1] = sum[n];
                suf[i][n + 1] = f[i][n + 1];
                for (int j = n; j > i; j--) {
                    suf[i][j] = min(f[i][j], suf[i][j + 1]);
                }
            } else {
                int y = i + a[i] + 1;
                for (int x = i + 1; x <= i + a[i]; x++) {
                    if (suf[x][y] != inf) {
                        f[i][x] = sum[x] - 1 + suf[x][y];
                    }
                }
                for (int j = i + a[i]; j > i; j--) {
                    suf[i][j] = min(suf[i][j + 1], f[i][j]);
                }
            }
        }
        printf("%d\n", suf[1][2]);
    }
 
    return 0;
}