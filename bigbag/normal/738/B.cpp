#include <map>
#include <set>
#include <stack>
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

const int max_n = 1011, inf = 1111111111;

int n, m, a[max_n][max_n], ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int f = 0;
        for (int j = 0; j < m; ++j) {
            if (f && a[i][j] == 0) {
                ++ans;
            }
            if (a[i][j]) {
                f = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int f = 0;
        for (int j = m - 1; j >= 0; --j) {
            if (f && a[i][j] == 0) {
                ++ans;
            }
            if (a[i][j]) {
                f = 1;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int f = 0;
        for (int j = 0; j < n; ++j) {
            if (f && a[j][i] == 0) {
                ++ans;
            }
            if (a[j][i]) {
                f = 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int f = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (f && a[j][i] == 0) {
                ++ans;
            }
            if (a[j][i]) {
                f = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}