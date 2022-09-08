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

const int max_n = 111;

int n, a[max_n][max_n];
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                a[j][k] = s[j][k] - '0';
            }
        }
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                for (int k = 0; k < n; ++k) {
                    a[k][j] ^= 1;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < n; ++k) {
                cnt += a[j][k];
            }
            if (cnt == n) {
                ++res;
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}