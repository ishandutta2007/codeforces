#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int n;
int a[105];
int jest[105];
int t[2];

int dp[105][105][105][2];

int main () {
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if(a[i]) jest[a[i]] = 1;
    }

    for(int i = 1; i <= n; ++i)
        if(!jest[i]) t[i % 2]++;

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= t[0]; ++j)
            for(int k = 0; k <= t[1]; ++k)
                for(int z = 0; z < 2; ++z) {
                    dp[i][j][k][z] = 1000000000;
                    if(a[i]) {
                        if(z == a[i] % 2)
                            dp[i][j][k][z] = min(dp[i - 1][j][k][z], dp[i - 1][j][k][!z] + 1);
                        continue;
                    }
                    if(z == 0 && j)
                        dp[i][j][k][0] = min(dp[i - 1][j - 1][k][0], dp[i - 1][j - 1][k][1] + 1);
                    else if(z == 1 && k)
                        dp[i][j][k][1] = min(dp[i - 1][j][k - 1][0] + 1, dp[i - 1][j][k - 1][1]);
                }
    printf("%d", min(dp[n][t[0]][t[1]][0], dp[n][t[0]][t[1]][1]));



    return 0;
}