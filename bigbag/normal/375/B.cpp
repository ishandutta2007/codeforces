#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5010, inf = 111111111;

int n, m, f, d1[max_n][max_n], d2[max_n][max_n];
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    f = 0;
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '0') {
                int poz = j - 1;
                while (poz >= 0 && s[i][poz] == '1') {
                    ++d1[poz][j - 1];
                    --poz;
                }
            }
        }
    }
    int ans = 0;
    for (int l = 0; l < m; ++l) {
        d2[l][l] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i][l] == '1') {
                ++d2[l][l];
            }
        }
        ans = max(ans, d2[l][l]);
        for (int r = l + 1; r < m; ++r) {
            d2[l][r] = d2[l][r - 1] - d1[l][r - 1];
            ans = max(ans, (r - l + 1) * d2[l][r]);
        }
    }
    cout << ans << endl;
    return 0;
}