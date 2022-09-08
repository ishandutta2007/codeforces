#include <bits/stdc++.h>

using namespace std;

const int max_n = 200022, inf = 1000111222;

int n, m, ta, tb, k, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    if (k >= n || k >= m) {
        puts("-1");
        return 0;
    }
    int pos = 0;
    int ans = -1;
    for (int i = 0; i <= k; ++i) {
        while (pos < m && a[i] + ta > b[pos]) {
            ++pos;
        }
        if (pos + k - i >= m) {
            ans = -1;
            break;
        }
        ans = max(ans, b[pos + k - i] + tb);
    }
    printf("%d\n", ans);
    return 0;
}