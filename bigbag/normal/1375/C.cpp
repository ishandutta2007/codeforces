#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

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
        if (a[0] < a[n - 1]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}