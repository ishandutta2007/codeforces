#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 22, M = 24;
const int inf = (1LL << 31) - 1;

int n, m, a[N], b[N];
int ans[N][N], now[N][N], tmp[N][N];

void mergy(int a[N][N], int b[N][N], int c[N][N]) {
    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            tmp[i][j] = inf;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            if (a[i][j] != inf)
                for(int k = 0; k <= n; k++)
                    for(int l = 0; l <= n; l++)
                        if (b[k][l] != inf) {
                            int left = i + max(0, k - j);
                            int right = l + max(0, j - k);
                            if (left > n || right > n)
                                continue;
                            tmp[left][right] = min(tmp[left][right], a[i][j] + b[k][l]);
                        }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            c[i][j] = tmp[i][j];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            now[i][j] = inf;
    
    for(int i = 0; i < (1 << n); i++) {
        int left = 0, right = 0, cost = 0;
        for(int j = 0, cnt = 0; j < n; j++) {
            if (i & (1 << j)) {
                cost += b[j];
                if (left > 0)
                    left--;
                else
                    right++;
            }
            else {
                cost += a[j];
                left++;
            }
            
        }
        now[left][right] = min(now[left][right], cost);
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            ans[i][j] = now[i][j];
    //printf("%d\n", ans[0][0]);
    m--;
    while(m) {
        if (m & 1) {
            mergy(ans, now, ans);
        }
        m >>= 1;
        mergy(now, now, now);
    }
    printf("%d\n", ans[0][0]);
    return 0;       
}