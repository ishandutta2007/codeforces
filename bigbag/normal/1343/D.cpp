#include <bits/stdc++.h>

using namespace std;

const int max_n = 400022, inf = 1000111222;

int t, n, k, a[max_n], sum[max_n];

void add(int l, int r) {
    if (l <= r) {
        sum[l] -= 1;
        sum[r + 1] += 1;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= 2 * k; ++i) {
            sum[i] = 0;
        }
        for (int i = 0; i < n / 2; ++i){
            int x = a[i], y = a[n - 1 - i];
            if (x > y) {
                swap(x, y);
            }
            add(x + 1, x + k);
            add(max(x + k + 1, y + 1), y + k);
            add(x + y, x + y);
        }
        int ans = inf, x = n;
        for (int i = 2; i <= 2 * k; ++i) {
            x += sum[i];
            ans = min(ans, x);
        }
        printf("%d\n", ans);
    }
    return 0;
}