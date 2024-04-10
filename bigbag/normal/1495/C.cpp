/**
 *  created: 10/03/2021, 15:02:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int t, n, m;
string s[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            ans[i] = s[i];
        }
        int start = 0;
        if (m % 3 == 0) {
            start = 1;
        }
        for (int i = start; i < m; i += 3) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = 'X';
            }
        }
        for (int i = start; i + 3 < m; i += 3) {
            bool ok = 0;
            for (int j = 0; j < n; ++j) {
                if (s[j][i + 1] == 'X' || s[j][i + 2] == 'X') {
                    ans[j][i + 1] = 'X';
                    ans[j][i + 2] = 'X';
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                ans[0][i + 1] = 'X';
                ans[0][i + 2] = 'X';
            }
        }
        for (int i = 0; i < n; ++i) {
            puts(ans[i].c_str());
        }
    }
    return 0;
}