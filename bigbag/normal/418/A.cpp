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

const int max_n = 1111, inf = 111111111;

int n, k, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; cnt < k && j <= n; ++j) {
            if (i != j && a[i][j] == 0 && a[j][i] == 0) {
                ++cnt;
                a[i][j] = 1;
            }
        }
        if (cnt < k) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << n * k << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 1) {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}