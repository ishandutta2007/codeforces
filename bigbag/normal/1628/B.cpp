/**
 *  created: 22/01/2022, 16:51:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n;
string s[max_n];

bool solve() {
    for (int i = 0; i < n; ++i) {
        string rev = s[i];
        reverse(rev.begin(), rev.end());
        if (s[i] == rev) {
            return true;
        }
    }
    map<string, int> first, last;
    for (int i = 0; i < n; ++i) {
        last[s[i]] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        first[s[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        string rev1 = s[i];
        reverse(rev1.begin(), rev1.end());
        auto it1 = last.find(rev1);
        if (it1 != last.end() && it1->second > i) {
            return true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i].size() == 3) {
            string rev = s[i];
            reverse(rev.begin(), rev.end());
            rev.pop_back();
            auto it1 = first.find(rev);
            if (it1 != first.end() && it1->second < i) {
                return true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i].size() == 3) {
            string rev = s[i];
            rev.pop_back();
            reverse(rev.begin(), rev.end());
            auto it1 = last.find(rev);
            if (it1 != last.end() && it1->second > i) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}