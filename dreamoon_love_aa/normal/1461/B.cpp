#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE  = 1 << 10;
char s[SIZE][SIZE];
int dp[SIZE][SIZE];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    int an = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            if(s[i][j] == '*') {
                dp[i][j] = min({dp[i + 1][j], dp[i + 1][j - 1], dp[i + 1][j + 1]}) + 1;
                an += dp[i][j];
            }
        }
    }
    printf("%d\n", an);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}