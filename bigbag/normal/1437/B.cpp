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
        for (int i = 1; i < s.length(); ++i) {
            ans += s[i] == s[i - 1];
        }
        cout << (ans + 1) / 2 << "\n";
    }
    return 0;
}