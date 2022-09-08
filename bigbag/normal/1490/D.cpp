/**
 *  created: 16/02/2021, 16:46:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, a[max_n], ans[max_n];

void solve(int l, int r, int d = 0) {
    int pos = max_element(a + l, a + r + 1) - a;
    ans[pos] = d;
    if (l < pos) {
        solve(l, pos - 1, d + 1);
    }
    if (pos < r) {
        solve(pos + 1, r, d + 1);
    }
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
        solve(0, n - 1);
        for (int i = 0; i < n; ++i) {
            printf("%d ", ans[i]);
        }
        puts("");
    }
    return 0;
}