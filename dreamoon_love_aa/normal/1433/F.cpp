#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 77;
int n, m, k;
// dp[x][r]  a  x  x  mod k  r  x 
void update(int &x, int v) {
    if(x < v) {
        x = v;
    }
}
int dp[SIZE][SIZE];
void calc1(int a[],int result[]) {
    memset(dp, -1, sizeof(int) * SIZE * SIZE);
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++) {
        for(int x = m - 1; x >= 0; x--) {
            for(int r = 0; r < k; r++) {
                if(dp[x][r] != -1) {
                    update(dp[x + 1][(r + a[i]) % k], dp[x][r] + a[i]);
                }
            }
        }
    }
    memset(result, -1, sizeof(int) * SIZE);
    for(int i = 0; i <= m / 2; i++) {
        for(int j = 0; j < k; j++) {
            if(dp[i][j] == -1) {
                continue;
            }
            update(result[j], dp[i][j]);
        }
    }
}
int b[SIZE][SIZE];
int a[SIZE][SIZE];
int dp2[SIZE];
void solve() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        calc1(a[i], b[i]);
    }
    memset(dp2, -1, sizeof(int) * SIZE);
    dp2[0] = 0;
    for(int i = 1; i <= n; i++) {
        int tmp[SIZE];
        memset(tmp, -1, sizeof(int) * SIZE);
        for(int r = 0; r < k; r++) {
            for(int r2 = 0; r2 < k; r2++) {
                if(dp2[r] == -1 || b[i][r2] == -1) {
                    continue;
                }
                update(tmp[(r + r2) % k], dp2[r] + b[i][r2]);
            }
        }
        memcpy(dp2, tmp, sizeof(int) * SIZE);
    }
    printf("%d\n", dp2[0]);
}
int main() {
    solve();
    return 0;
}