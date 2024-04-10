#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, m, k, l, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &m, &k, &l);
    int n = m * k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int st = 0;
    for (int i = 0; i + k <= n; ++i) {
        if (a[i] - a[0] <= l) {
            st = i;
        }
    }
    if (st + 1 < m) {
        printf("0\n");
        return 0;
    }
    long long ans = 0;
    int cur = 0;
    while (m) {
        ans += a[cur];
        cur += k;
        --m;
        cur = min(cur, st - m + 1);
    }
    cout << ans << "\n";
    return 0;
}