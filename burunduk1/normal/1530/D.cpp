#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, x = 1, res = 0;
    cin >> n;
    vector<int> a(n + 1), used(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        used[a[i]] = 1;
    }

    vector<int> ans(n + 1, 0), rev(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (used[a[i]] != 2) {
            ans[i] = a[i], rev[a[i]] = i;
            used[a[i]] = 2;
            res++;
        }
        else {
            while (used[x])
                x++;
            ans[i] = x, rev[x] = i;
            used[x] = -1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == i) {
            swap(ans[i], ans[rev[a[i]]]);
        }
    }
    cout << res << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
//    check();
    while (t--) {
        solve();
    }
    return 0;
}