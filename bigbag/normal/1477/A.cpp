/**
 *  created: 28/01/2021, 16:49:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
long long k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        long long g = llabs(a[0] - a[1]);
        for (int i = 1; i < n; ++i) {
            g = __gcd(g, llabs(a[0] - a[i]));
        }
        if ((k - a[0]) % g == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}