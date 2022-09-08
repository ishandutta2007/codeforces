/**
 *  created: 19/05/2022, 17:36:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s;
        if (s.size() == 2) {
            cout << s.back() << "\n";
        } else {
            cout << *min_element(s.begin(), s.end()) << "\n";
        }
    }
    return 0;
}