/**
 *  created: 04/04/2021, 21:48:14
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 303333, inf = 1000111222;

int t;
string s;

bool is_palindrom(const string &s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        string ans;
        vector<int> v;
        for (int pos = 0; pos <= 0; ++pos) {
            v.push_back(pos);
            if (s.size() > pos) {
                v.push_back(s.size() - pos - 1);
            }
        }
        for (int pos : v) {
            string t = s;
            t.insert(t.begin() + pos, 'a');
            if (!is_palindrom(t)) {
                ans = t;
                break;
            }
        }
        if (ans == "") {
            puts("NO");
        } else {
            puts("YES");
            puts(ans.c_str());
        }
    }
    return 0;
}