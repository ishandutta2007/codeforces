#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

struct state {
    int x, y, id;

    bool operator < (const state &s) const {
        return x - y < s.x - s.y;
    }
};

int n, m;
state a[max_n];
long long ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        int res = min(a[u].x + a[v].y, a[u].y + a[v].x);
        ans[u] -= res;
        ans[v] -= res;
    }
    sort(a, a + n);
    long long sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        sy += a[i].y;
    }
    for (int i = 0; i < n; ++i) {
        sy -= a[i].y;
        ans[a[i].id] += sx + 1LL * i * a[i].y;
        ans[a[i].id] += sy + 1LL * (n - i - 1) * a[i].x;
        sx += a[i].x;
    }
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", ans[i]);
    }
    printf("\n");
    return 0;
}