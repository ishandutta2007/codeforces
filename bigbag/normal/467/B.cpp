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

const int max_n = 1111, inf = 1111111111;

int n, m, k, x[max_n], a[max_n][22];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i <= m; ++i) {
        cin >> x[i];
        for (int j = 0; j < 22; ++j) {
            a[i][j] = get_bit(x[i], j);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < 22; ++j) {
            if (a[i][j] != a[m][j]) {
                ++cnt;
            }
        }
        if (cnt <= k) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}