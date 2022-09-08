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

int n, a[max_n];
long long dp[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = i; j >= 1; --j) {
            cnt += a[j];
            if (cnt == 1) {
                dp[i] += dp[j - 1];
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}