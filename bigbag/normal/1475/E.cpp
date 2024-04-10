/**
 *  created: 25/01/2021, 17:15:41
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, mod = 1000000007;

int t, n, k, a[max_n], c[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        reverse(a, a + n);
        int tot = 0, need = 0;
        for (int i = 0; i < n; ++i) {
            tot += a[i] == a[k - 1];
        }
        for (int i = 0; i < k; ++i) {
            need += a[i] == a[k - 1];
        }
        printf("%d\n", c[tot][need]);
    }
    return 0;
}