#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                last = i;
            } else if (last != -1) {
                ans = max(ans, i - last);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}