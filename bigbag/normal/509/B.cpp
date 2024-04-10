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

int n, k, mx, a[max_n], b[max_n], ans[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        mx = max(a[i], mx);
    }
    int col = 1, f = 0;
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j]) {
                ans[j][i] = col;
                if (col > k) {
                    cout << "NO" << endl;
                    return 0;
                }
                --a[j];
            } else {
                f = 1;
            }
        }
        if (f == 1) {
            ++col;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b[i]; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}