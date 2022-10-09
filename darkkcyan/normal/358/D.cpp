#include <bits/stdc++.h>

using namespace std;

#define maxn 3030

int n;
int a[3][maxn];
int dp[2][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < 3; ++i)
        for (int f = -1; ++f < n; )
            cin >> a[i][f];

    dp[0][n - 1] = a[0][n - 1];
    dp[1][n - 1] = a[1][n - 1];
    for (int i = n - 1; i--; ) {
        dp[0][i] = max(a[0][i] + dp[1][i + 1], dp[0][i + 1] + a[1][i]);
        dp[1][i] = max(a[1][i] + dp[1][i + 1], dp[0][i + 1] + a[2][i]);
        //clog << 0 << ' ' << i << ' ' << dp[0][i] << endl;
        //clog << 1 << ' ' << i << ' ' << dp[1][i] << endl;
    }
    cout << dp[0][0] ;
}