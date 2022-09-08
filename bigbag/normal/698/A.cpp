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

const int max_n = 111, inf = 1111111111;

int n, a[max_n], dp[max_n][3];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < max_n; ++i) {
        dp[i][0] = inf;
        dp[i][1] = inf;
        dp[i][2] = inf;
    }
    dp[0][0] = 1;
    for (int i = 0; i < 2; ++i) {
        if (get_bit(a[0], i)) {
            dp[0][1 << i] = 0;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
            for (int k = 0; k < 2; ++k) {
                if (get_bit(a[i + 1], k) && !get_bit(j, k)) {
                    dp[i + 1][1 << k] = min(dp[i + 1][1 << k], dp[i][j]);
                }
            }
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
    return 0;
}