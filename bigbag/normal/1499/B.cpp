/**
 *  created: 18/03/2021, 16:54:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t;
string s;

bool check() {
    for (int i = 0; i <= s.length(); ++i) {
        vector<int> v;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '1') {
                v.push_back(j);
            }
        }
        for (int j = i; j < s.length(); ++j) {
            if (s[j] == '0') {
                v.push_back(j);
            }
        }
        bool ok = 1;
        for (int j = 0; j + 1 < v.size(); ++j) {
            ok &= (v[j] + 1) != v[j + 1];
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        s = read();
        if (check()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}