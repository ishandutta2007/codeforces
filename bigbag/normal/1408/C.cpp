#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, l, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int pos1 = 0, pos2 = n - 1;
        long double ans = 0, x = 0, y = l;
        while (pos1 <= pos2) {
            int v1 = pos1 + 1, v2 = n - pos2;
            long double s1 = a[pos1] - x, s2 = y - a[pos2];
            long double t = min(s1 / v1, s2 / v2);
            ans += t;
            if (s1 / v1 <= s2 / v2) {
                x = a[pos1];
                ++pos1;
                y -= t * v2;
            } else {
                y = a[pos2];
                --pos2;
                x += t * v1;
            }
        }
        //cout << "#" << x << " " << y << endl;
        int v1 = pos1 + 1, v2 = n - pos2;
        long double s = y - x;
        ans += s / (v1 + v2);
        printf("%.20f\n", (double) ans);
    }
    return 0;
}