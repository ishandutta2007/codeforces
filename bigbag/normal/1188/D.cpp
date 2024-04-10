#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;
const int max_bit = 64;

int n, dp[2][max_n];
long long a[2][max_n];
int q1 = 0, q2 = 1;

bool get_bit(long long x, int pos) {
    return (x >> pos) & 1;
}

void upd(int q, int i, int cnt) {
    i = n - i;
    //cout << "upd " << i << " " << cnt << endl;
    dp[q][i] = min(dp[q][i], cnt);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[q1][i]);
        mx = max(mx, a[q1][i]);
        dp[q1][i] = inf;
    }
    for (int i = 0; i < n; ++i) {
        a[q1][i] = mx - a[q1][i];
    }
    for (int b = 0; b < max_bit; ++b) {
        for (int i = 0; i <= n; ++i) {
            dp[q2][i] = inf;
        }
        int c01 = 0, c11 = 0;
        for (int i = 0; i < n; ++i) {
            c11 += get_bit(a[q1][i], b);
        }
        for (int i = 0; i <= n; ++i) {
            const int c00 = i - c01;
            const int c10 = n - i - c11;
            //cout << b << " " << i << ": " << dp[q1][i] << ", " << c00 << " " << c01 << " " << c10 << " " << c11 << endl;
            upd(q2, c11, dp[q1][i] + c01 + c10);
            upd(q2, c11 + c10 + c01, dp[q1][i] + c00 + c11);
            c01 += get_bit(a[q1][i], b);
            c11 -= get_bit(a[q1][i], b);
        }
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (!get_bit(a[q1][i], b)) {
                a[q2][pos++] = a[q1][i];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (get_bit(a[q1][i], b)) {
                a[q2][pos++] = a[q1][i];
            }
        }
        swap(q1, q2);
    }
    printf("%d\n", dp[q1][n]);
    return 0;
}