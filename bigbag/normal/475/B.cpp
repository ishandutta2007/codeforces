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

const int max_n = 33, inf = 1111111111;

int n, m, used[max_n][max_n];
string a, b;
vector<pair<int, int> > v[max_n][max_n];

void dfs(int x, int y) {
    used[x][y] = 1;
    for (int i = 0; i < v[x][y].size(); ++i) {
        int nx = v[x][y][i].first, ny = v[x][y][i].second;
        if (used[nx][ny] == 0) {
            dfs(nx, ny);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '>') {
            for (int j = 0; j + 1 < m; ++j) {
                v[i][j].push_back(make_pair(i, j + 1));
            }
        } else {
            for (int j = 1; j < m; ++j) {
                v[i][j].push_back(make_pair(i, j - 1));
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] == 'v') {
            for (int j = 0; j + 1 < n; ++j) {
                v[j][i].push_back(make_pair(j + 1, i));
            }
        } else {
            for (int j = 1; j < n; ++j) {
                v[j][i].push_back(make_pair(j - 1, i));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            memset(used, 0, sizeof(used));
            dfs(i, j);
            for (int q = 0; q < n; ++q) {
                for (int w = 0; w < m; ++w) {
                    if (used[q][w] == 0) {
                        //cout << i << " " << j << " ? " << q << " " << w << endl;
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}