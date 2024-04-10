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

long long n, c[1111][11], dp[1111];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    c[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 11; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    long long ans = 0;
        for (int j = 5; j <= 7; ++j) {
            if (n - j >= 0) {
                ans += c[n][j];
            }
        }
    cout << ans << endl;
    return 0;
}