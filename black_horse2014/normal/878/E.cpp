#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
const int inf = 1e9;
const int N = 110000;

#define prev asdf

int prev[N], a[N], b[N], h[N], p2[N], f[17][N], g[17][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int j = i - 1;
		long long sum = a[i];
        while (sum > 0 && j) {
            int k = prev[j];
            if (j - k >= 31 || 1 << (j - k) > (inf - b[j]) / sum) {
                sum = inf;
                j = 0;
            } else {
            	sum <<= j - k;
            	sum += b[j];
                j = k;
            }
        }
        prev[i] = j, b[i] = sum;
    }
    for (int i = n; i > 0; i--) h[i] = (h[i + 1] * 2LL + a[i] + P) % P;
    for (int i = 0; i <= n; i++) p2[i] = i == 0 ? 1 : p2[i - 1] * 2 % P;
    for (int i = 1; i <= n; i++) {
        f[0][i] = prev[i];
        g[0][i] = (h[prev[i] + 1] + (P - h[i + 1]) * 1LL * p2[i - prev[i]]) % P;
    }
    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i-1][f[i-1][j]];
            g[i][j] = (g[i-1][j] + g[i-1][f[i-1][j]]) % P;
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        int sum = 0;
        for (int j = 16; j >= 0; j--) {
            if (f[j][r] <= l-1) continue;
            sum = (sum + g[j][r]) % P;
            r = f[j][r];
        }
        sum = (sum * 2LL + h[l] + (P - h[r + 1]) * 1LL * p2[r - l + 1]) % P;
        cout << sum << endl;
    }
    return 0;
}