#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans += 1LL * a[i] * m;
    
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] < a[n - 1]) {
            cout << -1 << endl;
            return 0;
        }
        if (b[i] == a[n - 1]) continue;
        cnt += 1;
        if (cnt == m) {
            if (n == 1) {
                cout << -1 << endl;
                return 0;
            }
            assert(b[i] != a[n - 2]);
            if (m == 1) {
                cout << -1 << endl;
                return 0;
            }
            ans += b[i] - a[n - 2];
        } else {
            ans += b[i] - a[n - 1];
        }
    }
    cout << ans << endl;

    return 0;
}