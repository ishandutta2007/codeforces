/**
 *  created: 21/03/2021, 19:38:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n];

int solve() {
    int c = -1;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] <= a[i + 1]) {
            if (c == -1) {
                c = a[i + 1] - a[i];
            }
            if (c != a[i + 1] - a[i]) {
                return -1;
            }
        }
    }
    int m = -1;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] > a[i + 1]) {
            int val = a[i] + c - a[i + 1];
            if (m == -1) {
                m = val;
            }
            if (m != val) {
                return -1;
            }
        }
    }
    if (m == -1 || c == -1) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] >= m) {
            return -1;
        }
    }
    return m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        long long m = solve();
        printf("%lld ", m);
        if (m > 0) {
            long long c = ((a[1] - a[0]) % m + m) % m;
            printf("%lld", c);
        }
        puts("");
    }
    return 0;
}