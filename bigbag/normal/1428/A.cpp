#include <bits/stdc++.h>

using namespace std;

int t, x1, y1, x2, y2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        int ans = dx + dy;
        if (dx && dy) {
            ans += 2;
        }
        cout << ans << "\n";
    }
    return 0;
}