#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], pos[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            --a[i];
            pos[a[i]] = i;
        }
        int mn = inf, mx = -inf;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, pos[i]);
            mx = max(mx, pos[i]);
            printf("%d", (bool) ((mx - mn) == i));
        }
        puts("");
    }
    return 0;
}