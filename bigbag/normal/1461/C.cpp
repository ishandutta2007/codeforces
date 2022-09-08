/**
 *  created: 11/12/2020, 16:44:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, m, a[max_n];
pair<int, double> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
        }
        int mn = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] != i) {
                mn = i;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%lf", &p[i].first, &p[i].second);
            --p[i].first;
        }
        if (mn == -1) {
            puts("1.0");
            continue;
        }
        sort(p, p + m);
        reverse(p, p + m);
        long double ans = 0, cur = 1;
        for (int i = 0; i < m; ++i) {
            if (p[i].first < mn) {
                break;
            }
            ans += cur * p[i].second;
            cur *= 1 - p[i].second;
        }
        printf("%.15f\n", (double) ans);
    }
    return 0;
}