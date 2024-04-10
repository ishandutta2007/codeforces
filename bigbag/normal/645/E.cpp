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

const int max_n = 1011111, max_k = 33, mod = 1000000007;

int n, m, k, dp[max_k], a[max_k];
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &k, s);
    m = strlen(s);
    for (int i = 0; i < k; ++i) {
        a[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int all = 1, poz;
        int x = s[i] - 'a';
        for (int j = 0; j < k; ++j) {
            if (a[j] == x) {
                poz = j;
            }
            all += dp[j];
            all %= mod;
        }
        for (int j = poz; j + 1 < k; ++j) {
            a[j] = a[j + 1];
        }
        a[k - 1] = x;
        dp[x] = all;
    }
    for (int i = 0; i < n; ++i) {
        int all = 1, poz;
        int x = a[0];
        for (int j = 0; j < k; ++j) {
            if (a[j] == x) {
                poz = j;
            }
            all += dp[j];
            all %= mod;
        }
        for (int j = poz; j + 1 < k; ++j) {
            a[j] = a[j + 1];
        }
        a[k - 1] = x;
        dp[x] = all;
    }
    int ans = 1;
    for (int i = 0; i < k; ++i) {
        ans += dp[i];
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}