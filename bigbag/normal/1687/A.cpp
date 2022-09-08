/**
 *  created: 03/06/2022, 17:38:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, k, a[max_n];

long long get_max(int k) {
    long long cur = accumulate(a, a + k, 0LL);
    long long res = cur;
    for (int i = k; i < n; ++i) {
        cur += a[i] - a[i - k];
        res = max(res, cur);
    }
    return res;
}

long long get_sum(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long ans = get_max(min(k, n));
        if (k <= n) {
            ans += get_sum(k);
        } else {
            ans += 1LL * (k - n) * n;
            ans += get_sum(n);
        }
        cout << ans << "\n";
    }
    return 0;
}