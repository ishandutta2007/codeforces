#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1111111111;

int n, a[max_n], poz[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        poz[a[i]] = i;
    }
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 1;
        if (poz[i] > poz[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, n - dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}