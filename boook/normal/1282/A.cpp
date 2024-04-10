#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    int t, a, b, c, d;
    cin >> t;
    while (t --) {
        cin >> a >> b >> c >> d;
        int ql = c - d, qr = c + d;
        if (a > b) swap(a, b);
        ql = max(ql, a);
        qr = min(qr, b);
        int ans = b - a;
        if (qr > ql) ans -= qr - ql;
        cout << ans << "\n";
    }
    return 0;
}