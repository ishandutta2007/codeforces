/**
 *  created: 06/01/2021, 14:46:44
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &x);
        long long mn = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            mn += a[i];
            mx += (a[i] + x - 1) / x;
        }
        mn = (mn + x - 1) / x;
        printf("%lld %lld\n", mn, mx);
    }
    return 0;
}