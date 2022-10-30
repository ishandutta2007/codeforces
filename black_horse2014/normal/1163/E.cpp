
#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], b[N], id[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(b + 1, b + n + 1);
    for (int x = 18; x >= 0; x--) {
        int m = lower_bound(b + 1, b + n + 1, 1 << x) - b - 1;
        for (int i = 1; i <= m; i++) a[i] = b[i], id[i] = i;
        int r = 1;
        for (int i = 0; r <= m && i < x; i++) {
            for (int j = r; j <= m; j++) if (a[j] >> i & 1) {
                swap(a[j], a[r]);
                swap(id[j], id[r]);
                break;
            }
            if (~a[r] >> i & 1) continue;
            for (int j = 1; j <= m; j++) {
                if (j == r) continue;
                if (a[j] >> i & 1) a[j] ^= a[r];
            }
            r++;
        }
        if (r - 1 == x) {
            cout << x << endl;
            for (int i = 0; i < 1 << x; i++) {
                int j = i ^ (i >> 1);
                int ans = 0;
                for (int k = 0; k < x; k++) if (j >> k & 1) ans ^= b[id[k + 1]];
                cout << ans << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}