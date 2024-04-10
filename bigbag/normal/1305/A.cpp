#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        puts("");
        for (int i = 0; i < n; ++i) {
            printf("%d ", b[i]);
        }
        puts("");
    }
    return 0;
}