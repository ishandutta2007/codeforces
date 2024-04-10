/**
 *  created: 17/07/2021, 17:36:01
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        cout << *max_element(s.begin(), s.end()) << "\n";
    }
    return 0;
}