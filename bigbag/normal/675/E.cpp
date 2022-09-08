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

int n, a[max_n];
pair<int, int> t[max_n];
long long ans, dp[max_n];

void update(int i, pair<int, int> p) {
    for (; i <= n; i = (i | (i + 1))) {
        t[i] = max(t[i], p);
    }
}

pair<int, int> get(int r) {
    pair<int, int> res = make_pair(0, 0);
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res = max(res, t[r]);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    update(n, make_pair(0, n));
    for (int i = n - 1; i > 0; --i) {
        dp[i] = a[i] - i;
        pair<int, int> p = get(a[i]);
        dp[i] += dp[p.second] - (a[i] - p.second) + n - a[i];
        ans += dp[i];
        update(i, make_pair(a[i], i));
    }
    printf("%I64d\n", ans);
    return 0;
}