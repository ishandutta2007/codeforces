/**
 *  created: 01/04/2021, 17:43:50
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 11, inf = 1000111222;

int h, w;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    int x = 0, y = 0, ans = 0;
    while (x != h - 1 || y != w - 1) {
        ans += s[x][y] == '*';
        if (x == h - 1) {
            ++y;
        } else if (y == w - 1) {
            ++x;
        } else if (s[x][y + 1] == '*') {
            ++y;
        } else if (s[x + 1][y] == '*') {
            ++x;
        } else {
            ++y;
        }
    }
    ans += s[x][y] == '*';
    cout << ans << endl;
    return 0;
}