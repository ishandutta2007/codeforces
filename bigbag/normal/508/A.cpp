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

const int max_n = 1111;

int n, m, a[max_n][max_n], k;

bool ok(int x, int y) {
    if (x < 0 || y < 0 || x + 1 >= n || y + 1 >= m) {
        return false;
    }
    return a[x][y] == 1 && a[x][y + 1] == 1 && a[x + 1][y] == 1 && a[x + 1][y + 1] == 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        a[x][y] = 1;
        if (ok(x, y) || ok(x, y - 1) || ok(x - 1, y) || ok(x - 1, y - 1)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}