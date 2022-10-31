#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1, cur = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] == a[i]) {
            ans = max(ans, cur);
            cur = 1;
        } else {
            cur++;
        }
    }
    ans = max(ans, cur);
    cout << ans << endl;
    return 0;
}