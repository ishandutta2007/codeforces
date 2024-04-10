#include <bits/stdc++.h>

using namespace std;

const int max_n = 30033, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = n - 1; i > 0; --i) {
            a[i] -= a[i - 1];
        }
        long long need = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] < 0) {
                need -= a[i];
            }
        }
        if (need <= a[0]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}