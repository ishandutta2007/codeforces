#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1011111111;

int n, q, c, a[11][max_n][max_n];

int get(int k, int lx, int ly, int rx, int ry) {
    int res = a[k][rx][ry];
    if (lx) {
        res -= a[k][lx - 1][ry];
    }
    if (ly) {
        res -= a[k][rx][ly - 1];
    }
    if (lx && ly) {
        res += a[k][lx - 1][ly - 1];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; ++i) {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        a[t][x][y] += 1;
    }
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < max_n; ++j) {
            for (int k = 1; k < max_n; ++k) {
                a[i][j][k] += a[i][j][k - 1];
            }
        }
        for (int j = 1; j < max_n; ++j) {
            for (int k = 0; k < max_n; ++k) {
                a[i][j][k] += a[i][j - 1][k];
            }
        }
    }
    while (q--) {
        int t, lx, ly, rx, ry;
        scanf("%d%d%d%d%d", &t, &lx, &ly, &rx, &ry);
        int ans = 0;
        for (int i = 0; i <= 10; ++i) {
            int sum = get(i, lx, ly, rx, ry);
            //cout << "#" << sum << "   " << ((i + t) % c) << endl;
            ans += sum * ((i + t) % (c + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}