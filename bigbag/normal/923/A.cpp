#include <bits/stdc++.h>

using namespace std;

const int max_n = 1001111, inf = 1000111222;

int dp[max_n];
int mx[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i < max_n; ++i) {
        if (mx[i] == 0) {
            for (int j = 2 * i; j < max_n; j += i) {
                mx[j] = i;
            }
        }
    }
    int x;
    cin >> x;
    int ans = inf;
    for (int i = x - mx[x] + 1; i <= x; ++i) {
        if (mx[i]) {
            ans = min(ans, i - mx[i] + 1);
        }
    }
    cout << ans << endl;
    return 0;
}