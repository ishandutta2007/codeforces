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

const int max_n = 55, inf = 1111111111;

int n, m, ans, a[222];
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            a['f'] = a['a'] = a['c'] = a['e'] = 0;
            a[s[i][j]] = 1;
            a[s[i + 1][j]] = 1;
            a[s[i][j + 1]] = 1;
            a[s[i + 1][j + 1]] = 1;
            if (a['f'] && a['a'] && a['c'] && a['e']) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}