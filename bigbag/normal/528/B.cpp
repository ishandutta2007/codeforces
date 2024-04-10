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

const int max_n = 222222, inf = 1111111111;

int n, dp[max_n];
pair<int, int> a[max_n];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n, cmp);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (a[0].first + a[0].second <= a[i].first - a[i].second) {
            int l = 0, r = i;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (a[mid].first + a[mid].second <= a[i].first - a[i].second) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            dp[i] = max(dp[i], dp[l] + 1);
        }
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}