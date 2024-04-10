#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, m, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    int pos_a = 0, pos_b = 0, ans = 0;
    long long x = 0, y = 0;
    while (pos_a < n || pos_b < m) {
        if (pos_a == n) {
            y += b[pos_b];
            ++pos_b;
        } else if (pos_b == m) {
            x += a[pos_a];
            ++pos_a;
        } else if (x < y) {
            x += a[pos_a];
            ++pos_a;
        } else {
            y += b[pos_b];
            ++pos_b;
        }
        if (x == y) {
            x = 0;
            y = 0;
            ++ans;
        }
    }
    if (x || y) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}