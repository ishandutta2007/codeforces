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

const int max_n = 22, inf = 1111111111;

int n, m, a[max_n][max_n], b[max_n][max_n];

bool check(int num) {
    vector<int> v;
    for (int i = 0; i < m; ++i) {
        if (a[num][i] != b[num][i]) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) {
        return true;
    }
    if (v.size() == 2) {
        int x = v[0], y = v[1];
        return a[num][x] == b[num][y] && a[num][y] == b[num][x];
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
            b[i][j] = j;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int f = 1;
            for (int k = 0; k < n; ++k) {
                int ff = 0;
                swap(b[k][i], b[k][j]);
                if (check(k)) {
                    ff = 1;
                }
                swap(b[k][i], b[k][j]);
                swap(a[k][i], a[k][j]);
                if (check(k)) {
                    ff = 1;
                }
                swap(a[k][i], a[k][j]);
                if (ff == 0) {
                    f = 0;
                    break;
                }
            }
            if (f == 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}