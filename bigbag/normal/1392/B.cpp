#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];
long long k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%I64d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int mx = *max_element(a, a + n);
        --k;
        for (int i = 0; i < n; ++i) {
            a[i] = mx - a[i];
        }
        mx = *max_element(a, a + n);
        for (int i = 0; i < n; ++i) {
            if (k % 2) {
                a[i] = mx - a[i];
            }
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}