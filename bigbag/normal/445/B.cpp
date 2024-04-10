#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int n, m, a[max_n][max_n], used[max_n];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        long long aa = 1;
        memset(used, 0, sizeof(used));
        used[i] = 1;
        for (int qq = 2; qq <= n; ++qq) {
            int ff = 0;
            for (int j = 1; j <= n; ++j) {
                if (used[j] == 0) {
                    int f = 0;
                    for (int k = 1; k <= n; ++k) {
                        if (used[k] == 1 && a[j][k] == 1) {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 1) {
                        used[j] = 1;
                        aa *= 2;
                        ff = 1;
                        break;
                    }
                }
            }
            if (ff == 0) {
                for (int j = 1; j <= n; ++j) {
                    if (used[j] == 0) {
                        used[j] = 1;
                        break;
                    }
                }
            }
        }
        ans = max(ans, aa);
    }
    cout << ans << endl;
    return 0;
}