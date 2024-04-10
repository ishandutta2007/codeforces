/**
 *  created: 25/03/2021, 16:39:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        vector<int> v;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                v.push_back(i);
            }
        }
        int ans = 1, last = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (i + 1 < v.size() && v[i + 1] - last <= k) {
                continue;
            }
            last = v[i];
            ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}