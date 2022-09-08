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

long long n, c[max_n], dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int mx = 0, mn = inf;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++c[x];
        mx = max(mx, x);
        mn = min(mn, x);
    }
    dp[mn] = mn * c[mn];
    for (int i = mn + 1; i <= mx; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * c[i]);
    }
    cout << dp[mx] << endl;
    return 0;
}