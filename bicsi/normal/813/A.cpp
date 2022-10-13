#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int s = 0;
    while (n--) {
        int x; cin >> x; s += x;
    }

    int m; cin >> m;
    int ans = 2e9;
    while (m--) {
        int l, r; cin >> l >> r;
        if (r >= s) {
            ans = min(ans, max(l, s));
        }
    }
    
    if (ans == 2e9) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}