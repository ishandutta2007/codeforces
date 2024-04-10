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

const int max_n = 10000111, inf = 1011111111;

int n, k, a[max_n], dp[max_n];

bool check(int x) {
    long long res = 0;
    for (int i = 0; i < max_n; ++i) {
        dp[i] = 0;
        if (i >= x) {
            dp[i] = max(1, dp[i / 2] + dp[i / 2 + i % 2]);
        }
        res += 1LL * a[i] * dp[i];
        if (res >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    int l = 0, r = max_n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == 0) {
        l = -1;
    }
    printf("%d\n", l);
    return 0;
}