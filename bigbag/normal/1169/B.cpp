#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

int mx, n, a[max_n], b[max_n], cnt[max_n];
map<pair<int, int>, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &mx, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        ++cnt[a[i]];
        ++cnt[b[i]];
        ++q[{min(a[i], b[i]), max(a[i], b[i])}];
    }
    for (int x = 1; x <= mx; ++x) {
        if (cnt[x] * 2 >= n) {
            for (int y = 1; y <= mx; ++y) {
                if (x == y) {
                    continue;
                }
                if (cnt[x] + cnt[y] - q[{min(x, y), max(x, y)}] == n) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}