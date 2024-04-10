#include <bits/stdc++.h>

using namespace std;

const int inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = inf;
        for (int c = 0; c < 50000; ++c) {
            ans = min(ans, c + (n + c) / (c + 1) - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}