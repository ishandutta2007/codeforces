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

const int max_n = 555, inf = 1000000007;
const int dx[] = {1, 0};
const int dy[] = {0, 1};
const int dx2[] = {-1, 0};
const int dy2[] = {0, -1};
int n, m, dp[2][max_n][max_n];
string s[max_n];

bool in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

bool ok(int x, int y, int a, int b) {
    if (x == a && y == b) {
        return true;
    }
    if (x + 1 == a && y == b) {
        return true;
    }
    if (x == a && y + 1 == b) {
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    if (s[0][0] != s[n - 1][m - 1]) {
        cout << 0 << endl;
        return 0;
    }
    dp[0][0][n - 1] = 1;
    int q1 = 0, q2 = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                dp[q2][j][k] = 0;
            }
        }
        for (int j = 0; j < m; ++j) {
            int len = i + j;
            for (int k = n - 1; k >= 0; --k) {
                int y = n - k - 1 + m - 1 - i - j;
                if (0 <= y && y < m) {
                    if (ok(i, j, k, y)) {
                        //cout << "         += (" << i << " " << j << ") (" << k << " " << y << ") : " << dp[q1][j][k] << endl;
                        ans += dp[q1][j][k];
                        ans %= inf;
                        continue;
                    }
                    //cout << "(" << i << " " << j << ") (" << k << " " << y << ") : " << dp[q1][j][k] << endl;
                    for (int q = 0; q < 2; ++q) {
                        for (int w = 0; w < 2; ++w) {
                            int qq = q1;
                            if (dx[q] == 1) {
                                qq = q2;
                            }
                            int nx = i + dx[q];
                            int ny = j + dy[q];
                            int nx2 = k + dx2[w];
                            int ny2 = y + dy2[w];
                            if (in(nx, ny) && in(nx2, ny2) && s[nx][ny] == s[nx2][ny2]) {
                                //cout << "                  " << i << " " << j << "  " << k << " " << y << " -> " << nx << " " << ny << "  " << nx2 << " " << ny2 << endl;
                                dp[qq][ny][nx2] += dp[q1][j][k];
                                dp[qq][ny][nx2] %= inf;
                            }
                        }
                    }
                }
            }
        }
        swap(q1, q2);
    }
    cout << ans;
    return 0;
}