#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1011111111;
//const long long inf = 1011011011022022022LL;

int n, m, sum;
string s[max_n];

bool ok(int n, int l, int r, int len) {
    return len <= n;
    return l + len <= n || r - len >= -1;
}

int main() {
    cin >> n >> m;
    int lx = inf, ly = inf, rx = -inf, ry = -inf;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'B') {
                lx = min(lx, i);
                rx = max(rx, i);
                ly = min(ly, j);
                ry = max(ry, j);
                ++sum;
            }
        }
    }
    if (lx == inf) {
        cout << 1 << endl;
    } else {
        int len = max(rx - lx + 1, ry - ly + 1);
        if (ok(n, lx, rx, len) && ok(m, ly, ry, len)) {
            cout << len * len - sum << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}