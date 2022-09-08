#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 1111111111;

int n, m, a[max_n][max_n];
int x1[max_n][max_n], x2[max_n][max_n];
int y1[max_n][max_n], y2[max_n][max_n];


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    x1[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
        x1[i][0] = a[i][0] + x1[i - 1][0];
    }
    for (int i = 1; i < m; ++i) {
        x1[0][i] = a[0][i] + x1[0][i - 1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            x1[i][j] = a[i][j] + max(x1[i - 1][j], x1[i][j - 1]);
        }
    }
    x2[n - 1][m - 1] = a[n - 1][m - 1];
    for (int i = n - 2; i >= 0; --i) {
        x2[i][m - 1] = a[i][m - 1] + x2[i + 1][m - 1];
    }
    for (int i = m - 2; i >= 0; --i) {
        x2[n - 1][i] = a[n - 1][i] + x2[n - 1][i + 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            x2[i][j] = a[i][j] + max(x2[i + 1][j], x2[i][j + 1]);
        }
    }

    y1[n - 1][0] = a[n - 1][0];
    for (int i = n - 2; i >= 0; --i) {
        y1[i][0] = a[i][0] + y1[i + 1][0];
    }
    for (int i = 1; i < m; ++i) {
        y1[n - 1][i] = a[n - 1][i] + y1[n - 1][i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 1; j < m; ++j) {
            y1[i][j] = a[i][j] + max(y1[i][j - 1], y1[i + 1][j]);
        }
    }
    y2[0][m - 1] = a[0][m - 1];
    for (int i = m - 2; i >= 0; --i) {
        y2[0][i] = a[0][i] + y2[0][i + 1];
    }
    for (int i = 1; i < n; ++i) {
        y2[i][m - 1] = a[i][m - 1] + y2[i - 1][m - 1];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = m - 2; j >= 0; --j) {
            y2[i][j] = a[i][j] + max(y2[i - 1][j], y2[i][j + 1]);
        }
    }

    /*cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << y2[i][j] << ' ';
        }
        cout << endl;
    }*/
    int ans = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < m; ++j) {
            if (ans < y1[i][j - 1] + x1[i - 1][j] + y2[i][j + 1] + x2[i + 1][j]) {
                ans = y1[i][j - 1] + x1[i - 1][j] + y2[i][j + 1] + x2[i + 1][j];
                //cout << "!" << i << ' ' << j << endl;
            }
            if (ans < x1[i][j - 1] + y1[i + 1][j] + x2[i][j + 1] + y2[i - 1][j]) {
                ans = x1[i][j - 1] + y1[i + 1][j] + x2[i][j + 1] + y2[i - 1][j];
                //cout << i << ' ' << j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}