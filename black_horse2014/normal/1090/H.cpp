#include <bits/stdc++.h>
using namespace std;

int sum[20][220000];
int a[220000];
int c[20];

int main() {
    ios::sync_with_stdio(0);
    int n; string s; cin >> n >> s;
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    int m = 20;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[j][i] = a[i] ^ a[i - 1];
            if (i >= (1 << j)) sum[j][i] += sum[j][i - (1 << j)];
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int m = __builtin_ctz(r - l + 1);
        c[m] = 0;
        for (int j = 0; j < m; j++) {
            int to = r + 1 - (1 << j);
            int from = l;
            c[j] = sum[j][to] - sum[j][from];
        }
        for (int j = 0; j < m; j++) c[j] -= c[j + 1];
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int cnt = (r - l + 1) >> (j + 1);
            ans += min(c[j], cnt - c[j]);
        }
        ans = (ans + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}