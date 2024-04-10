#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, a[2][max_n];
long long sum[2][max_n];
long long rsum[2][max_n];
long long sumk[2][max_n];
long long rsumk[2][max_n];

long long get_sum(int tp, int l, int r, long long t) {
    return (sumk[tp][r] - sumk[tp][l - 1]) + (t - l) * (sum[tp][r] - sum[tp][l - 1]);
}

long long get_rsum(int tp, int l, int r, long long t) {
    return (rsumk[tp][r] - rsumk[tp][l + 1]) + t * (rsum[tp][r] - rsum[tp][l + 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int tp = 0; tp < 2; ++tp) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[tp][i]);
        }
        sum[tp][0] = a[tp][0];
        for (int i = 1; i < n; ++i) {
            sum[tp][i] = sum[tp][i - 1] + a[tp][i];
            sumk[tp][i] = sumk[tp][i - 1] + 1LL * i * a[tp][i];
        }
        rsum[tp][n - 1] = a[tp][n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rsum[tp][i] = rsum[tp][i + 1] + a[tp][i];
            rsumk[tp][i] = rsumk[tp][i + 1] + 1LL * (n - 1 - i) * a[tp][i];
        }
    }
    int tp = 0;
    long long sum = 0, t = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += t * a[tp][i];
        ++t;

        long long x = sum;
        x += get_sum(tp, i + 1, n - 1, t);
        //cout << i << ": " << x << endl;
        x += get_rsum(tp ^ 1, n - 1, i, t + n - i - 1);
        //cout << i << ": " << x << endl;
        ans = max(ans, x);

        tp ^= 1;
        sum += t * a[tp][i];
        ++t;
    }
    printf("%I64d\n", ans);
    return 0;
}