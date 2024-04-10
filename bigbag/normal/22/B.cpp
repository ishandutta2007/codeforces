#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 33, inf = 111111111;

int n, m;
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int q = 0; q < m; ++q) {
                    if (i <= k && j <= q) {
                        int f = 0;
                        for (int a = i; a <= k; ++a) {
                            for (int b = j; b <= q; ++b) {
                                if (s[a][b] == '1') {
                                    f = 1;
                                    break;
                                }
                            }
                        }
                        if (f == 0) {
                            ans = max(ans, 2 * (k - i + 1 + q - j + 1));
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}