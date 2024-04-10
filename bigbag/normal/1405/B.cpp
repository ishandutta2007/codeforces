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
        long long ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum < 0) {
                ans -= sum;
                sum = 0;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}