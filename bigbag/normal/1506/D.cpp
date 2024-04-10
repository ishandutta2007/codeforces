/**
 *  created: 25/03/2021, 16:46:33
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        map<int, int> q;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++q[a[i]];
        }
        int mx = 0;
        for (auto p : q) {
            mx = max(mx, p.second);
        }
        int ans = n % 2;
        if (mx > n - mx) {
            ans = mx - n + mx;
        }
        printf("%d\n", ans);
    }
    return 0;
}