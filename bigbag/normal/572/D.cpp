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

const int max_n = 300333, max_k = 5005;
const long long inf = 1111111111111111111LL;

int n, k, l1, l2, a1, a2, a[max_n];
long long dp[max_k][max_k];

long long get_sum(int l, int r) {
    return a[r] - a[l];
}

void get_dp(int a1, int a2) {
    if (dp[a1][a2] != -1) {
        return;
    }
    int poz = a1 * l1 + a2 * l2 - 1;
    dp[a1][a2] = inf;
    if (a1) {
        get_dp(a1 - 1, a2);
        dp[a1][a2] = min(dp[a1][a2], dp[a1 - 1][a2] + get_sum(poz - l1 + 1, poz));
    }
    if (a2) {
        get_dp(a1, a2 - 1);
        dp[a1][a2] = min(dp[a1][a2], dp[a1][a2 - 1] + get_sum(poz - l2 + 1, poz));
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    l1 = 1 + (n - 1) / k;
    for (int i = 0; i < k; ++i) {
        int c = (n - i - 1) / k + 1;
        if (c == l1) {
            ++a1;
        } else {
            ++a2;
            l2 = c;
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    get_dp(a1, a2);
    //cout << a1 << " " << l1 << endl;
    //cout << a2 << " " << l2 << endl;
    cout << dp[a1][a2] << endl;
    return 0;
}