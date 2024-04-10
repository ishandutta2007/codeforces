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

const int max_n = 111, inf = 1111111111;

int n, m, a[max_n][max_n], sum[max_n][max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'W') {
                a[i][j] = 1;
            } else {
                a[i][j] = -1;
            }
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int nx = sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1];
            int x = a[i][j] - nx;
            //cout << nx << "  " << a[i][j] << "    " << x << endl;
            if (x != 0) {
                ++ans;
            }
            sum[i][j] = nx + x;
        }
    }
    cout << ans << endl;
    return 0;
}