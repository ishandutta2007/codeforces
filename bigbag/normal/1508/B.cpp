/**
 *  created: 16/04/2021, 18:07:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n;
long long k;

bool check() {
    long long N = 1, cnt = 1;
    while (cnt < k) {
        cnt *= 2;
        ++N;
    }
    return N <= n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &k);
        if (!check()) {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n - 62; ++i) {
            printf("%d ", i);
        }
        for (int i = max(1, n - 61); i <= n; ) {
            for (int x = i; ; ++x) {
                if (x == n || (1LL << (n - x - 1)) >= k) {
                    for (int j = x; j >= i; --j) {
                        printf("%d ", j);
                    }
                    i = x + 1;
                    break;
                }
                k -= (1LL << (n - x - 1));
            }
        }
        puts("");
    }
    return 0;
}