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

int n, a[max_n][max_n], x[max_n], y[max_n];
string s;
vector<int> dx, dy;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    memset(a, -1, sizeof(a));
    for (int i = 5; i <= 7; ++i) {
        for (int j = 5; j <= 7; ++j) {
            a[i][j] = (i - 5) * 3 + j - 4;
        }
    }
    a[8][6] = 0;
    for (int i = 5; i <= 8; ++i) {
        for (int j = 5; j <= 7; ++j) {
            if (a[i][j] != -1) {
                x[a[i][j]] = i;
                y[a[i][j]] = j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        s[i] -= '0';
    }
    int X = x[s[0]], Y = y[s[0]];
    for (int i = 1; i < n; ++i) {
        dx.push_back(x[s[i]] - X);
        dy.push_back(y[s[i]] - Y);
        X = x[s[i]];
        Y = y[s[i]];
        //cout << dx.back() << " " << dy.back() << endl;
    }
    for (int i = 5; i <= 8; ++i) {
        for (int j = 5; j <= 7; ++j) {
            if (a[i][j] == -1) {
                continue;
            }
            if (i == x[s[0]] && j == y[s[0]]) {
                continue;
            }
            int X = i, Y = j, f = 0;
            for (int k = 0; k < dx.size(); ++k) {
                X += dx[k];
                Y += dy[k];
                if (a[X][Y] == -1) {
                    //cout << i << " " << j << " #" << k << endl;
                    f = 1;
                    break;
                }
            }
            if (f == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}