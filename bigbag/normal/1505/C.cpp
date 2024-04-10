/**
 *  created: 01/04/2021, 17:57:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 2; i < s.size(); ++i) {
        int x = s[i - 2] - 'A' + s[i - 1] - 'A';
        x %= 26;
        int y = s[i] - 'A';
        if (x != y) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}