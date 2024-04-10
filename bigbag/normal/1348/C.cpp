#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        if (k == 1) {
            cout << s << "\n";
            continue;
        }
        if (s[k - 1] != s[0]) {
            cout << s[k - 1] << "\n";
            continue;
        }
        if (s.back() == s[0]) {
            string ans((n + k - 1) / k, s[0]);
            cout << ans << "\n";
            continue;
        }
        string ans;
        ans += s[0];
        if (s[k] == s.back()) {
            int cnt = n - k;
            ans += string((cnt + k - 1) / k, s[k]);
        } else {
            ans += s.substr(k);
        }
        cout << ans << "\n";
    }
    return 0;
}