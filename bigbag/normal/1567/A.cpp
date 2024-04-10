/**
 *  created: 05/09/2021, 17:35:33
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        for (char &c : s) {
            if (c == 'U' || c == 'D') {
                c ^= 'U';
                c ^= 'D';
            }
        }
        cout << s << "\n";
    }
    return 0;
}