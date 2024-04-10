/**
 *  created: 12/06/2022, 17:45:38
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int T, n;
string s[2], t[2][3];

bool check(string a, string b) {
    if (a.size() != b.size()) {
        return 0;
    }
    vector<int> v1, v2;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 'b') {
            v1.push_back(i);
        }
        if (b[i] == 'b') {
            v2.push_back(i);
        }
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] < v2[i]) {
            return false;
        }
    }
    return true;
}

bool ok() {
    if (t[0][1] != t[1][1]) {
        return false;
    }
    return check(t[0][2], t[1][2]) && check(t[1][0], t[0][0]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            cin >> s[i];
            t[i][0] = "";
            t[i][1] = "";
            t[i][2] = "";
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < n; ++j) {
                    if ('a' + k != s[i][j]) {
                        t[i][k] += s[i][j];
                    }
                }
            }
        }
        if (ok()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}