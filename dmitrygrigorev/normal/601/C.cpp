#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

#define INF 1000000007

using namespace std;
double dp[101][200002];
const int K = 100000;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0;i<=n;i++) for (int j=0; j <= 2*n*m+1;j++) dp[i][j] = 0;
    dp[0][n*m+1] = 1;
    for (int i=0; i < n; i++){
        for (int j=0; j <= 2*n*m; j++) dp[i][j+1] += dp[i][j];
        for (int j=0; j <= 2*n*m+1; j++){
            double prob = 0;
            int L = j-(a[i]-1), R = j-1;
            if (L-1 < 0) continue;
            prob += (dp[i][R] - dp[i][L-1]) / (double) (m-1);
            L = j+1, R = j + (m-a[i]);
            if (R > 2*n*m+1) continue;
            prob += (dp[i][R] - dp[i][L-1]) / (double) (m-1);
            dp[i+1][j] = prob;
            //if (i==0 && j>=n*m) cout << i << " " << j << " " << prob << endl;
        }
    }
    double P = 0;
    for (int i=n*m+2; i <= 2*n*m+1;i++) P += dp[n][i];
    double ans = 1;
    for (int i=0; i < m-1; i++) ans += P;
    cout.precision(20);
    cout << ans;
}