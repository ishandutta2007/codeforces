#include <bits/stdc++.h>

using namespace std;

const int max_n = 1, inf = 1000111222;

int n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            bool can = true;
            if (i && s[i - 1] == '1') {
                can = false;
            }
            if (i + 1 < n && s[i + 1] == '1') {
                can = false;
            }
            if (can) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            bool can = true;
            if (i && s[i - 1] == '1') {
                can = false;
            }
            if (i + 1 < n && s[i + 1] == '1') {
                can = false;
            }
            if (!can) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}