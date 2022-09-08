#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        int cnt = 0;
        string t = "";
        for (int i = 0; i < s.length(); ++i) {
            t += s[i];
            while (t.length() >= 2 && t.back() != t[t.size() - 2]) {
                t.pop_back();
                t.pop_back();
                ++cnt;
            }
        }
        if (cnt % 2) {
            puts("DA");
        } else {
            puts("NET");
        }
    }
    return 0;
}