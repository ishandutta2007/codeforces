/**
 *  created: 12/11/2021, 16:42:23
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ones = 0;
        for (char c : s) {
            ones += c == '1';
        }
        vector<int> ans;
        for (int i = 0; i < n - ones; ++i) {
            if (s[i] == '1') {
                ans.push_back(i);
            }
        }
        for (int i = n - ones; i < n; ++i) {
            if (s[i] == '0') {
                ans.push_back(i);
            }
        }
        if (ans.empty()) {
            cout << "0\n";
        } else {
            cout << "1\n";
            cout << ans.size() << " ";
            for (int x : ans) {
                cout << 1 + x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}