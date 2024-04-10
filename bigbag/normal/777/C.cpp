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

const int max_n = 101111, inf = 1011111111;

int n, m, q, dp[max_n];
vector<int> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int l = j;
            while (j + 1 < n && a[j][i] <= a[j + 1][i]) {
                ++j;
            }
            dp[l] = max(dp[l], j);
        }
    }
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        if (dp[l] >= r) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}