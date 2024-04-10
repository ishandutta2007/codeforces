#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, x, y, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = max(0, i - x); j < min(n, i + y + 1); ++j) {
            if (i != j && a[i] >= a[j]) {
                ok = false;
            }
        }
        if (ok) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}