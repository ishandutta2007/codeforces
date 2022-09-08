#include <bits/stdc++.h>

using namespace std;

int t, n, cost[2], h;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> cost[0] >> cost[1] >> h >> s;
        int ans = 0;
        for (char c : s) {
            ans += min(cost[c - '0'], h + cost['1' - c]);
        }
        cout << ans << "\n";
    }
    return 0;
}