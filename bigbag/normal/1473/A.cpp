/**
 *  created: 14/01/2021, 16:35:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, d, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        if (a[0] + a[1] <= d || a[n - 1] <= d) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}