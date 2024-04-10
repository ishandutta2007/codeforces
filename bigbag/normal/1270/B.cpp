#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

void solve() {
    for (int i = 0; i + 1 < n; ++i) {
        if (max(a[i], a[i + 1]) - min(a[i], a[i + 1]) >= 2) {
            puts("YES");
            printf("%d %d\n", i + 1, i + 2);
            return;
        }
    }
    puts("NO");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}