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

const int max_n = 311111, inf = 1111111111;

int n, m, a[max_n], dp[max_n], poz[max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        poz[a[i]] = i;
    }
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long ans = 1;
    dp[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        dp[i] = dp[i + 1];
        for (int j = 0; j < g[a[i]].size(); ++j) {
            if (i < poz[g[a[i]][j]]) {
                dp[i] = min(dp[i], poz[g[a[i]][j]]);
            }
        }
        ans += dp[i] - i;
    }
    printf("%I64d\n", ans);
    return 0;
}