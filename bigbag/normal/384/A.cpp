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

const int max_n = 1011, inf = 111111111;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, cnt;
char ans[max_n][max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int f = 0;
            for (int k = 0; k < 4; ++k) {
                int a = i + dx[k], b = j + dy[k];
                if (is_in(a, b) && ans[a][b] == 'C') {
                    f = 1;
                    break;
                }
            }
            ans[i][j] = '.';
            if (f == 0) {
                ans[i][j] = 'C';
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}