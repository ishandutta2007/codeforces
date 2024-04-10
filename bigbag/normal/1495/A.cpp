/**
 *  created: 10/03/2021, 14:06:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<long long> a, b;
        for (int i = 0; i < 2 * n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == 0) {
                a.push_back(1LL * y * y);
            } else {
                b.push_back(1LL * x * x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += sqrt(a[i] + b[i]);
        }
        printf("%.12f\n", (double) ans);
    }
    return 0;
}