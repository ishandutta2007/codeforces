/**
 *  created: 25/06/2021, 18:37:50
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 101111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        long long ans = a[n - 1], sum = 0;
        for (int i = 1; i < n; ++i) {
            ans -= 1LL * i * a[i] - sum;
            sum += a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}