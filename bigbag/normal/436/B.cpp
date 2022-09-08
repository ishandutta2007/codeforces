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

const int max_n = 2222, inf = 1111111111;

int n, m, k;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int j = 0; j < m; ++j) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[0][j] == 'D') {
                ++ans;
            }
            if (i + i < n && s[i + i][j] == 'U') {
                ++ans;
            }
            if (j - i >= 0 && s[i][j - i] == 'R') {
                ++ans;
            }
            if (j + i < m && s[i][j + i] == 'L') {
                ++ans;
            }
        }
        printf("%d ", ans);
    }
    return 0;
}