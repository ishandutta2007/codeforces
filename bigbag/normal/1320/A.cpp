#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n];
long long dp[max_n];
map<int, long long> mx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        dp[i] = a[i];
        int val = i - a[i];
        if (mx.count(val)) {
            dp[i] = max(dp[i], mx[val] + a[i]);
        }
        mx[val] = dp[i];
    }
    cout << *max_element(dp, dp + n) << "\n";
    return 0;
}