#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) if (a[i]) ans = max(ans, n - a[i] + 1);
    for (int i = 1; i <= n; i++) {
        if (b[i]) {
            ans = max(ans, i + 1 + n - b[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
            int ret = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j]) ret = max(ret, n - a[j] + 1);
            }
            for (int j = 1; j < i; j++) {
                if (b[j]) {
                    ret = max(ret, n - b[j] + 1 + j);
                }
            }
            for (int j = i + 1; j <= n; j++) {
                if (b[j] != j - i + 1) {
                    cout << ans << endl;
                    return 0;
                }
            }
            if (ret <= i - 1) {
                cout << i - 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}