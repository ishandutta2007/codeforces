#include <bits/stdc++.h>

using namespace std;

const int max_n = 10011, inf = 1000111222;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int x = 0, y = 0, ans = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] == x && b[i] == y) {
            continue;
        }
        int first = max(x, y);
        if (x == y) {
            ++first;
        }
        if (first <= a[i] && first <= b[i]) {
            ans += min(a[i], b[i]) - first + 1;
        }
        x = a[i];
        y = b[i];
    }
    printf("%d\n", ans);
    return 0;
}