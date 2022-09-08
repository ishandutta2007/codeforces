#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, d, m, a[max_n];
long long sum[max_n];

long long get_sum(int l, int r) {
    if (!l) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &d, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        sum[i] = a[i];
        if (i) {
            sum[i] += sum[i - 1];
        }
        if (a[i] <= m) {
            pos = i;
        }
    }
    long long ans = 0;
    if (pos != -1) {
        ans = sum[pos];
    }
    for (int i = 1; i <= n; ++i) {
        int cnt = 1 + (i - 1) * (d + 1);
        if (cnt > n || a[n - i] <= m) {
            break;
        }
        long long res = get_sum(n - i, n - 1);
        if (pos != -1) {
            int add = min(pos + 1, n - cnt);
            res += get_sum(pos - add + 1, pos);
        }
        //cout << i << ": " << res << endl;
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}