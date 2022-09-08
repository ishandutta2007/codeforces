#include <bits/stdc++.h>

using namespace std;

const int max_n = 2000111, inf = 1000111222;

int n, k, sum[max_n], a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[a[i]] = 1;
    }
    for (int i = 1; i < max_n; ++i) {
        sum[i] += sum[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (sum[a[i] + k] == sum[a[i]]) {
            ++ans;
        }
    }
    ans = max(ans, 1);
    printf("%d\n", ans);
    return 0;
}