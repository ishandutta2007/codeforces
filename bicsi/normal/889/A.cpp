#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<char> ok(n + 1, 0);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ok[i] = true;
        
        if (ok[x]) {
            ok[x] = false;
        } else {
            ans += 1;
        }
    }
    cout << ans << endl;

    return 0;
}