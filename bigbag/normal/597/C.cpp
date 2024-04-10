#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 511111, max_k = 12;

int n, k, a[max_n];
long long t[max_n], dp[max_k][max_n];

void update(int i, long long x) {
    for (; i < n; i = (i | (i + 1))) {
        t[i] += x;
    }
}

long long get_sum(int r) {
    long long res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[r];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    ++k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= k; ++i) {
        memset(t, 0, sizeof(t));
        for (int j = 0; j < n; ++j) {
            dp[i][j] = get_sum(a[j] - 1);
            update(a[j], dp[i - 1][j]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[k][i];
    }
    cout << ans << endl;
    return 0;
}