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

const int max_n = 5005, inf = 1011111111;

int n, p[max_n], b[max_n];
int pos[max_n];

vector<pair<vector<int>, pair<vector<int>, vector<int>>>> all;
vector<pair<vector<int>, pair<vector<int>, vector<int>>>> my_all;

void find_b() {
    for (int i = 0; i < n; ++i) {
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        b[i] = pos[i];
    }
}

int ans[2][max_n];
int res[max_n], tm, used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "? " << i + j << " " << i << endl;
            cout.flush();
            cin >> ans[j][i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        p[0] = i;
        for (int j = 0; j + 1 < n; ++j) {
            int x = ans[0][j] ^ ans[1][j];
            p[j + 1] = p[j] ^ x;
        }
        find_b();
        int f = 1;
        for (int j = 0; j + 1 < n; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (ans[k][j] != (p[j + k] ^ b[j])) {
                    f = 0;
                    break;
                }
            }
        }
        ++tm;
        for (int j = 0; j < n; ++j) {
            if (p[j] >= n) {
                f = 0;
                break;
            }
            if (used[p[j]] == tm) {
                f = 0;
                break;
            }
            used[p[j]] = tm;
        }
        if (0) {
            for (int j = 0; j < n; ++j) {
                cout << p[j] << " ";
            }
            cout << endl;
            for (int j = 0; j < n; ++j) {
                cout << b[j] << " ";
            }
            cout << "f = " << f << endl;
        }
        cnt += f;
        if (f) {
            for (int j = 0; j < n; ++j) {
                res[j] = p[j];
            }
        }
    }
    cout << "!" << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    cout.flush();
    return 0;
}