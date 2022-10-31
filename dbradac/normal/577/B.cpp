#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1005;

int dp[MAX][MAX];
int p[MAX];

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    if (n > m) {
        printf("YES\n");
        return 0;
    }

    for (int i=0; i<n; i++)
        scanf("%d", &p[i]);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (dp[i][j]) {
                dp[i+1][j] = 1;
                dp[i+1][(j + p[i]) % m] = 1;
            }
        }
        dp[i+1][p[i] % m] = 1;
    }

    printf("%s\n", dp[n][0] ? "YES" : "NO");

    return 0;
}