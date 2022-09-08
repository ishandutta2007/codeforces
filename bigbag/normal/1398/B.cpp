#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        vector<int> v;
        for (int i = 0; i < s.length(); ) {
            if (s[i] == '1') {
                int pos = i;
                while (i < s.length() && s[i] == '1') {
                    ++i;
                }
                v.push_back(i - pos);
            } else {
                ++i;
            }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); i += 2) {
            ans += v[i];
        }
        cout << ans << "\n";
    }
    return 0;
}