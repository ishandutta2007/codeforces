#include <bits/stdc++.h>

using namespace std;

const int max_n = 10111, inf = 1000111222;

int n, q, ans[max_n], dp[max_n];
pair<int, pair<int, int>> a[max_n];

void add(int r, int x) {
    for (int i = n - x; i >= 0; --i) {
        dp[i + x] = max(dp[i + x], min(dp[i], r));
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", &a[i].first, &a[i].second.first, &a[i].second.second);
    }
    sort(a, a + q);
    int cur = 0;
    dp[0] = inf;
    for (int i = 1; i <= n; ++i) {
        while (a[cur].first <= i) {
            add(a[cur].second.first, a[cur].second.second);
            ++cur;
        }
        for (int j = 1; j <= n; ++j) {
            if (dp[j] >= i) {
                ans[j] = 1;
            }
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) {
            v.push_back(i);
        }
    }
    printf("%d\n", v.size());
    for (int x : v) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}