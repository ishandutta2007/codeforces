#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

const int nn = 1<<17;

typedef long long LL;
typedef pair<int, int> pii;

int N;
int a[nn];
int b[nn];

int pos[nn * 4];

void build(int id, int l, int r) {
    memset(pos, -1, sizeof pos);
}

void set(int id, int l, int r, int L, int R, int iA) {
    if (l > R) return;
    if (L > r) return;
    if (L <= l && r <= R) {
        pos[id] = iA + l - L;
        return;
    }

    int m = (l + r) / 2;
    if (pos[id] >= 0) {
        set(id*2, l, m, l, m, pos[id]);
        set(id*2 + 1, m + 1, r, m + 1, r, pos[id] + m + 1 - l);
    }

    pos[id] = -1;
    set(id*2, l, m, L, R, iA);
    set(id*2 + 1, m + 1, r, L, R, iA);
}

int get(int id, int l, int r, int p) {
    if (pos[id] >= 0) return a[pos[id] + p - l];
    if (l == r) return b[p];
    int m = (l+r) / 2;
    if (p <= m)
        return get(id*2, l, m, p);
    else
        return get(id*2 + 1, m + 1, r, p);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    int N = 1;
    while (N < n) N *= 2;

    build(1, 1, N);

    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            set(1, 1, N, y, y + k - 1, x);
        } else {
            int p;
            scanf("%d", &p);
            printf("%d\n", get(1, 1, N, p));
        }
    }
}

int main() {
    solve();
    return 0;
}