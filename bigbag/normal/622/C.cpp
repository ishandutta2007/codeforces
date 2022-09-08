#include <bits/stdc++.h>

using namespace std;

const int max_n = 222222;

int n, m, a[max_n], b[max_n];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    b[0] = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            b[i] = i - 1;
        } else {
            b[i] = b[i - 1];
        }
    }
    while (m--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        --l;
        --r;
        if (a[r] != x) {
            printf("%d\n", r + 1);
        } else if (b[r] >= l) {
            printf("%d\n", b[r] + 1);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}