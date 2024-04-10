#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            ++cnt[a[i]];
        }
        int ans = -2;
        for (int i = 0; i < n; ++i) {
            if (cnt[a[i]] == 1 && (ans == -2 || a[ans] > a[i])) {
                ans = i;
            }
        }
        printf("%d\n", ans + 1);
        for (int i = 0; i < n; ++i) {
            --cnt[a[i]];
        }
    }
    return 0;
}