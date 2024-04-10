#include <bits/stdc++.h>

#define M ((L + R) / 2)
using namespace std;

typedef long long ll;

const int N = 100010;

int val[N * 4], a[N], n, m;
ll sum;

void build(int x, int L, int R) {
    if (L == R) {
        val[x] = (a[L] != a[L + 1]);
        sum += 1ll * val[x] * L * (n - L);
        return;
    }
    build(x << 1, L, M);
    build(x << 1 | 1, M + 1, R);
    val[x] = val[x << 1] + val[x << 1 | 1];
}
void change(int x, int L, int R, int pos) {
    if (pos < L||R < pos) return;
    if (L == R) {
        sum -= 1ll * val[x] * L * (n - L);
        val[x] = (a[L] != a[L + 1]);
        sum += 1ll * val[x] * L * (n - L);
        return;
    }
    change(x << 1, L, M, pos);
    change(x << 1 | 1, M + 1, R, pos);
    val[x] = val[x << 1] + val[x << 1 | 1];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1) {
        for (int i = 1; i <= m; i++)
            cout << 1 << endl;
        return 0;
    }
    build(1, 1, n - 1);
    while (m--) {
        int x, v;
        cin >> x >> v;
        a[x] = v;
        if (x - 1 >= 1)
            change(1, 1, n - 1, x - 1);
        if (x <= n - 1)
            change(1, 1, n - 1, x);
        cout << sum + 1ll * n * (n + 1) / 2 << endl;
    }
    return 0;
}