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

const int max_n = 55, inf = 1111111111;

int n, a[max_n][max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int x = 1; x <= n; ++x) {
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                int f = 1;
                for (int j = 0; j < n; ++j) {
                    if (a[i][j] > x || a[j][i] > x) {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    ans[i] = x;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}