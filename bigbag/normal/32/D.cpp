#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 111111111;

int n, m, k;
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }
    int cnt = 0;
    for (int r = 1; r <= min(n, m); ++r) {
        for (int i = r; i + r < n; ++i) {
            for (int j = r; j + r < m; ++j) {
                if (s[i][j] == '*' && s[i + r][j] == '*' && s[i - r][j] == '*' && s[i][j - r] == '*' && s[i][j + r] == '*') {
                    ++cnt;
                }
                if (cnt == k) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    cout << i + 1 - r << ' ' << j + 1 << endl;
                    cout << i + 1 + r << ' ' << j + 1 << endl;
                    cout << i + 1 << ' ' << j + 1 - r << endl;
                    cout << i + 1<< ' ' << j + 1 + r << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}