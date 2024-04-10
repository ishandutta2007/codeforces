#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define oo ((int)1e9)

const int maxn = 202, maxk = 11;
int n, K, ans;
int a[maxn], s[maxn], f[maxn][maxn][maxk], g[maxn][maxn][maxk];

int main(){
    scanf("%d %d", &n, &K);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), s[i] = s[i - 1] + a[i];

    memset(f, 128, sizeof(f));
    memset(g, 127, sizeof(g));
    f[n + 1][n][0] = 0;
    for(int i = 1; i <= n; i++){
        f[i][i][0] = g[i][i][0] = f[i][i - 1][0] = 0;
        f[i][i][1] = g[i][i][1] = a[i];
        for(int j = i + 1; j <= n; j++){
            f[i][j][0] = g[i][j][0] = 0;
            for(int k = 1; k <= K; k++){
                f[i][j][k] = max(f[i][j - 1][k], f[i][j - 1][k - 1] + a[j]);
                g[i][j][k] = min(g[i][j - 1][k], g[i][j - 1][k - 1] + a[j]);
            }
        }
    }
    
    ans = -oo;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            for(int k = 0; k <= K; k++)
                for(int t = 0; t <= k; t++)
                    if (f[1][i - 1][t] > -oo && f[j + 1][n][k - t] > -oo && g[i][j][k] < oo)
                        ans = max(ans, s[j] - s[i - 1] + f[1][i - 1][t] + f[j + 1][n][k - t] - g[i][j][k]);
    printf("%d", ans);
    return 0;
}