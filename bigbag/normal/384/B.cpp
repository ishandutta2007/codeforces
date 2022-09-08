#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1011, max_m = 111, inf = 111111111;

int n, m, k, a[max_n][max_m], b[max_n][max_m];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    cout << (m * (m - 1)) / 2 << endl;
    if (k == 0) {
        for (int i = 1; i <= m; ++i) {
            for (int j = i + 1; j <= m; ++j) {
                cout << i << ' ' << j << endl;
            }
        }
    }
    if (k == 1) {
        for (int i = 1; i <= m; ++i) {
            for (int j = i + 1; j <= m; ++j) {
                cout << j << ' ' << i << endl;
            }
        }
    }
    return 0;
}