#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[100005],dp[100005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, ans = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                if (i % j == 0) {
                    if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
                    if (a[i] > a[i / j]) dp[i] = max(dp[i], dp[i / j] + 1);
                    ans = max(ans, dp[i]);
                }
        printf("%d\n", ans);
    }
    return 0;
}