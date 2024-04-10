#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set<pair<pair<int, int>, pair<int, int>>> q;
        int x = 0, y = 0, ans = 0;
        for (char c : s) {
            int nx = x, ny = y;
            if (c == 'N') {
                --ny;
            } else if (c == 'S') {
                ++ny;
            } else if (c == 'W') {
                --nx;
            } else {
                ++nx;
            }
            pair<int, int> p1(x, y), p2(nx, ny);
            if (q.count({p1, p2}) || q.count({p2, p1})) {
                ++ans;
            } else {
                ans += 5;
            }
            x = nx;
            y = ny;
            q.insert({p1, p2});
        }
        cout << ans << "\n";
    }
    return 0;
}