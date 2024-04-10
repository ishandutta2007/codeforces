/**
 *  created: 21/12/2020, 17:13:13
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n;
string a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                ++cnt;
            } else if (a[i] < b[i]) {
                --cnt;
            }
        }
        if (cnt > 0) {
            puts("RED");
        } else if (cnt == 0) {
            puts("EQUAL");
        } else {
            puts("BLUE");
        }
    }
    return 0;
}