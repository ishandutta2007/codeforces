#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if ((a[i] < 0 && i % 2 == 0) || (a[i] > 0 && i % 2 == 1)) {
                a[i] *= -1;
            }
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}