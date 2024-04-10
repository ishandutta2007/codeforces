#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
int dp[505][505],a[505][505];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp[i][j] = j - i + 1;
    for (int i = 1; i <= n; i++) cin >> a[i][i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j + i - 1 <= n; j++)
            for (int k = j; k < j + i - 1; k++) {
                dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1]);
                if (dp[j][k] == 1 && dp[k + 1][j + i - 1] == 1 && a[j][k] == a[k + 1][j + i - 1])
                    dp[j][j + i - 1] = 1, a[j][j + i - 1] = a[j][k] + 1;
            }
    printf("%d\n", dp[1][n]);
    return 0;
}