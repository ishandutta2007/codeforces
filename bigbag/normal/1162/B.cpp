#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, m, a[max_n][max_n], b[max_n][max_n];

bool check(int a[max_n][max_n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n && a[i][j] >= a[i + 1][j]) {
                return false;
            }
            if (j + 1 < m && a[i][j] >= a[i][j + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            if (a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
        }
    }
    if (check(a) && check(b)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}