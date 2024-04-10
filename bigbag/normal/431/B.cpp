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

const int max_n = 5, inf = 1111111111;

int ans, p[max_n], res[max_n], a[max_n][max_n];

void update(int x, int y) {
    x = p[x];
    y = p[y];
    res[x] += a[x][y];
    res[y] += a[y][x];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 5; ++i) {
        p[i] = i;
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }
    do {
        memset(res, 0, sizeof(res));
        update(0, 1);
        update(2, 3);
        update(1, 2);
        update(3, 4);
        update(2, 3);
        update(3, 4);
        ans = max(ans, res[0] + res[1] + res[2] + res[3] + res[4]);
    } while (next_permutation(p, p + 5));
    cout << ans << endl;
    return 0;
}