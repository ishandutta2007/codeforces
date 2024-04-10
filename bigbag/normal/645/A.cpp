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

const int max_n = 8, inf = 1111111111;

int used[2][1 << max_n];

int get(char c) {
    if (c == 'A') return 0;
    if (c == 'B') return 1;
    if (c == 'C') return 2;
    if (c == 'X') return 3;
}

void dfs(int mask, int num) {
    int x = mask, a[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = x % 4;
            x /= 4;
        }
    }
    used[num][mask] = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int w = 0; w < 2; ++w) {
                    if (a[i][j] != 3 && a[k][w] == 3) {
                        if (abs(i - k) + abs(j - w) < 2) {
                            swap(a[i][j], a[k][w]);
                            int to = a[0][0] + 4 * a[0][1] + 16 * a[1][0] + 64 * a[1][1];
                            if (used[num][to] == 0) {
                                dfs(to, num);
                            }
                            swap(a[i][j], a[k][w]);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 2; ++i) {
        string a[2];
        for (int j = 0; j < 2; ++j) {
            cin >> a[j];
        }
        int mask = get(a[0][0]) + 4 * get(a[0][1]) + 16 * get(a[1][0]) + 64 * get(a[1][1]);
        dfs(mask, i);
    }
    for (int i = 0; i < (1 << max_n); ++i) {
        if (used[0][i] == 1 && used[1][i] == 1) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}