/**
 *  created: 24/05/2021, 12:13:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n;
string s, ans = "blue", tp = "unlock";

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "lock" || s == "unlock") {
            tp = s;
        } else if (tp != "lock") {
            ans = s;
        }
    }
    cout << ans << endl;
    return 0;
}