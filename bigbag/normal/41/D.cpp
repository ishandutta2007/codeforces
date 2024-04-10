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

const int max_n = 111, max_k = 11, inf = 1111111111;

int n, m, k, a[max_n][max_n], d[max_n][max_n][max_k];
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d\n", &n, &m, &k);
    ++k;
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[i][j] - '0';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int q = 0; q < k; ++q) {
                d[i][j][q] = -1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        d[n - 1][i][a[n - 1][i] % k] = a[n - 1][i];
    }
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < m; ++j) {
            for (int q = 0; q < k; ++q) {
                if (d[i][j][q] != -1) {
                    if (j != 0) {
                        d[i - 1][j - 1][(q + a[i - 1][j - 1]) % k] = max(d[i][j][q] + a[i - 1][j - 1], d[i - 1][j - 1][(q + a[i - 1][j - 1]) % k]);
                    }
                    if (j != m - 1) {
                        d[i - 1][j + 1][(q + a[i - 1][j + 1]) % k] = max(d[i][j][q] + a[i - 1][j + 1], d[i - 1][j + 1][(q + a[i - 1][j + 1]) % k]);
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << d[i][j][0] << ' ';
        }
        cout << endl;
    }
    while (1);*/
    int poz, max1 = -1;
    for (int i = 0; i < m; ++i) {
        if (d[0][i][0] > max1) {
            max1 = d[0][i][0];
            poz = i;
        }
    }
    if (max1 == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << max1 << endl;
    string ans;
    int oo = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int o = (oo + 2000 * k - a[i][poz]) % k;
        if (poz != 0 && d[i + 1][poz - 1][o] != -1 && d[i][poz][oo] == d[i + 1][poz - 1][o] + a[i][poz]) {
            ans = ans + 'R';
            poz = poz - 1;
        }
        else {
            ans = ans + 'L';
            poz = poz + 1;
        }
        oo = o;
    }
    reverse(ans.begin(), ans.end());
    cout << poz + 1 << endl << ans << endl;
    return 0;
}