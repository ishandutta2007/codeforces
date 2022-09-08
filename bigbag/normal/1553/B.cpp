/**
 *  created: 22/07/2021, 17:44:14
**/

#include <bits/stdc++.h>

using namespace std;

int t;
string a, b;

bool check() {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size() && i + j < a.size(); ++j) {
            if (a[i + j] != b[j]) {
                break;
            }
            int pos = i + j - 1, k = j + 1;
            while (k < b.size() && pos >= 0 && a[pos] == b[k]) {
                --pos;
                ++k;
            }
            if (k == b.size()) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (check()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}