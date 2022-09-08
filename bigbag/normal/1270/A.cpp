#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, k1, k2, mx1, mx2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &k1, &k2);
        mx1 = mx2 = 0;
        while (k1--) {
            int x;
            scanf("%d", &x);
            mx1 = max(mx1, x);
        }
        while (k2--) {
            int x;
            scanf("%d", &x);
            mx2 = max(mx2, x);
        }
        if (mx1 > mx2) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}