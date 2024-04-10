/**
 *  created: 06/02/2022, 16:36:51
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        string t = s;
        reverse(t.begin(), t.end());
        if (s != t && k) {
            cout << "2\n";
        } else {
            cout << "1\n";
        }
    }
    return 0;
}