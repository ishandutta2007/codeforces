/**
 *  created: 09/08/2021, 17:36:02
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

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
        double ans = accumulate(a, a + n - 1, 0LL) / ((long double) (n - 1)) + a[n - 1];
        printf("%.10f\n", ans);
    }
    return 0;
}