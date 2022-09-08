#include <bits/stdc++.h>

using namespace std;

int t, a[2], x[2], n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> x[0] >> x[1] >> n;
        long long ans = 1LL * a[0] * a[1];
        for (int i = 0; i < 2; ++i) {
            int a0 = a[0], a1 = a[1], kn = n;
            int cnt = min(n, a[i] - x[i]);
            a[i] -= cnt;
            n -= cnt;
            cnt = min(n, a[i ^ 1] - x[i ^ 1]);
            a[i ^ 1] -= cnt;
            n -= cnt;
            ans = min(ans, 1LL * a[0] * a[1]);
            a[0] = a0;
            a[1] = a1;
            n = kn;
        }
        cout << ans << "\n";
    }
    return 0;
}