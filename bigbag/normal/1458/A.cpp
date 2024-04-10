/**
 *  created: 19/12/2020, 11:36:01
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m;
long long a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        long long x = abs(a[i] - a[i - 1]);
        if (ans == 0 || x == 0) {
            ans += x;
        } else {
            ans = __gcd(ans, x);
        }
    }
    for (int i = 0; i < m; ++i) {
        long long x;
        scanf("%lld", &x);
        long long res = __gcd(ans, a[0] + x);
        printf("%lld ", res);
    }
    puts("");
    return 0;
}