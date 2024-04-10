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

const int max_n = 111111, inf = 1011111111;

int n, a[max_n], dp[max_n];

int func(int x) {
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return dp[l];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    a[0] = -inf;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 20 + dp[i - 1];
        dp[i] = min({dp[i], func(a[i] - 90) + 50, func(a[i] - 1440) + 120});
        printf("%d\n", dp[i] - dp[i - 1]);
    }
    return 0;
}