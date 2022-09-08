#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, ans, a[max_n], p1, p2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    p1 = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != a[p1]) {
            p2 = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[p1]) {
            ans = max(ans, abs(i - p1));
        }
        if (a[i] != a[p2]) {
            ans = max(ans, abs(i - p2));
        }
    }
    printf("%d\n", ans);
    return 0;
}