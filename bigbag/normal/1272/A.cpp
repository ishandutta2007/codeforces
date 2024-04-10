#include <bits/stdc++.h>

using namespace std;

int q, a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        long long ans = 1e18;
        for (int d1 = -1; d1 <= 1; ++d1) {
            for (int d2 = -1; d2 <= 1; ++d2) {
                for (int d3 = -1; d3 <= 1; ++d3) {
                    int x = a + d1;
                    int y = b + d2;
                    int z = c + d3;
                    ans = min(ans, 1LL * abs(x - y) + abs(y - z) + abs(x - z));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}