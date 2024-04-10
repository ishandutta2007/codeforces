#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n, u, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &u);
    long long bestx = 0, besty = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int pos = 0;
    for (int i = 0; i + 2 < n; ++i) {
        while (pos + 1 < n && a[pos + 1] - a[i] <= u) {
            ++pos;
        }
        if (pos > i + 1) {
            long long x = a[pos] - a[i + 1];
            long long y = a[pos] - a[i];
            if (x * besty > bestx * y) {
                bestx = x;
                besty = y;
            }
        }
    }
    if (bestx == 0) {
        printf("-1\n");
    } else {
        long double ans = bestx;
        ans /= besty;
        cout.precision(20);
        cout << fixed << ans << "\n";
    }
    return 0;
}