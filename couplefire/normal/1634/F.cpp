#include <bits/stdc++.h>
using namespace std;

int MOD;
int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

const int N = 3e5 + 6;
int n, q;
int a[N], b[N];
int f[N];
int x;

void upd(int p, int v) {
    if (b[p] > 0) --x;
    b[p] = add(b[p], v);
    if (b[p] > 0) ++x;
}

void solve() {
    cin >> n >> q >> MOD;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        a[i] = add(a[i], -v);
    }
    f[1] = f[2] = 1;
    for (int i = 3; i <= n + 1; ++i)
        f[i] = add(f[i - 1], f[i - 2]);
    b[1] = a[1];
    for (int i = 2; i <= n; ++i)
        b[i] = add(a[i], -a[i - 1] - a[i - 2]);
    for (int i = 1; i <= n; ++i)
        x += (b[i] > 0);
    while (q--) {
        char c; int l, r;
        cin >> c >> l >> r;
        int k = (c == 'A' ? 1 : -1);
        upd(l, k * 1);
        if (r + 1 <= n) upd(r + 1, -k * f[r - l + 2]);
        if (r + 2 <= n) upd(r + 2, -k * f[r - l + 1]);
        cout << (x ? "NO\n" : "YES\n");
    }
}

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}