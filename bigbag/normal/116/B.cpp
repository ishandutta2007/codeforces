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

const int max_n = 11, inf = 1111111111;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
string s[max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'P') {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (is_in(x, y) && s[x][y] == 'W') {
                        s[x][y] = '.';
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}