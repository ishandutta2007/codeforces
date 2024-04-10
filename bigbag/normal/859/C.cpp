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

const int max_n = 55, inf = 1011111111;

int n, a[max_n], dp[max_n], sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        sum[i] = a[i] + sum[i + 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = max(a[i] + sum[i + 1] - dp[i + 1], dp[i + 1]);
    }
    dp[0] = sum[0] - dp[0];
    cout << dp[0] << " " << sum[0] - dp[0] << endl;
    return 0;
}