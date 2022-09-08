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

const int max_n = 111, inf = 111111111;
const int dx[] = {-1, 1, -1, 1, -2, 2, -2, 2};
const int dy[] = {-2, 2, 2, -2, -1, 1, 1, -1};

int n, cnt[max_n][max_n], used[max_n][max_n];
char s[max_n][max_n];

bool is_krest(int x, int y) {
    return s[x][y] == '#' && s[x - 1][y] == '#' && s[x + 1][y] == '#' && s[x][y - 1] == '#' && s[x][y + 1] == '#' && used[x][y] == 0 && used[x - 1][y] == 0 && used[x + 1][y] == 0 && used[x][y - 1] == 0 && used[x][y + 1] == 0;
}

bool is_in(int x, int y) {
    return x > 0 && y > 0 && x + 1 < n && y + 1 < n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }
    if (s[0][0] == '#' || s[0][n - 1] == '#' || s[n - 1][0] == '#' || s[n - 1][n - 1] == '#') {
        cout << "NO";
        return 0;
    }
    int f = 0;
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 1; j + 1 < n; ++j) {
            if (is_krest(i, j)) {
                used[i][j] = 1;
                used[i - 1][j] = 1;
                used[i + 1][j] = 1;
                used[i][j - 1] = 1;
                used[i][j + 1] = 1;
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << used[i][j];
        }
        cout << endl;
    }*/
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[i][j] == 0 && s[i][j] == '#') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}