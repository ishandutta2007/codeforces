/**
 *  created: 19/05/2022, 17:47:27
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << c + b + a << " " << c + b << " " << c << "\n";
    }
    return 0;
}