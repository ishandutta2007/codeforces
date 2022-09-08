/**
 *  created: 14/06/2022, 17:39:02
**/

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, -1, 1};
int t;
string s[8];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 8; ++i) {
            cin >> s[i];
        }
        for (int i = 1; i < 7; ++i) {
            for (int j = 1; j < 7; ++j) {
                bool ok = 1;
                for (int k = 0; k < 5; ++k) {
                    ok &= s[i + dx[k]][j + dy[k]] == '#';
                }
                if (ok) {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }
    return 0;
}