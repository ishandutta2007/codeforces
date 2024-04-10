#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n, a[max_n], b[max_n], posa[max_n], posb[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        posa[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        --b[i];
        posb[b[i]] = i;
    }
    int mx = -1, ans = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, posb[a[i]]);
        if (posb[a[i]] < mx) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}