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

int n, dp[max_n];
pair<int, int> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = -1, r = i;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (p[mid].first < p[i].first - p[i].second) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == -1) {
            dp[i] = 1;
        } else {
            dp[i] = 1 + dp[l];
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", n - ans);
    return 0;
}