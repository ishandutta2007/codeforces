#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, d, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; ++i) {
            while (d >= i && a[i]) {
                d -= i;
                --a[i];
                ++a[0];
            }
        }
        printf("%d\n", a[0]);
    }
    return 0;
}