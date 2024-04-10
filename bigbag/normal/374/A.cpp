#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int inf = 111111111;

int n, m, a, b, i, j, x[2], y[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> i >> j >> a >> b;
    int ans = inf;
    x[0] = n - i;
    x[1] = i - 1;
    y[0] = m - j;
    y[1] = j - 1;
    for (int q = 0; q < 2; ++q) {
        for (int k = 0; k < 2; ++k) {
            if (x[q] % a == 0 && y[k] % b == 0) {
                int xx = x[q] / a, yy = y[k] / b;
                if (xx % 2 == yy % 2) {
                     if (xx != 0 || xx == 0 && a < n) {
                        if (yy != 0 || yy == 0 && b < m) {
                            ans = min(ans, max(xx, yy));
                        }
                     }
                     if (xx == 0 && yy == 0) {
                         ans = min(ans, max(xx, yy));
                     }
                }
            }
        }
    }
    if (ans != inf) cout << ans;
    else cout << "Poor Inna and pony!" << endl;
    return 0;
}