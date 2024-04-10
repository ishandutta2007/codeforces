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

const int max_n = 5333333, inf = 1111111111;

int n, m, dx, dy, used[max_n], num[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &dx, &dy);
    int stx = 0, t = 1;
    while (true) {
        if (used[stx] != 0) {
            break;
        }
        used[stx] = t;
        ++t;
        stx += dx;
        if (stx >= n) {
            stx -= n;
        }
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        int sty = (((long long) (used[x] - 1)) * ((long long) dy)) % n;
        //cout << "!" << x << " " << sty << endl;
        ++num[y - sty + n];
    }
    int ans, mx = -1;
    for (int i = 0; i + n < max_n; ++i) {
        if (mx < num[i] + num[i + n]) {
            mx = num[i] + num[i + n];
            ans = i - n;
            if (ans < 0) {
                ans += n;
            }
        }
    }
    cout << 0 << " " << ans << endl;
    return 0;
}