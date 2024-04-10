#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1, inf = 1011111111;

int s, x1, x2, t1, t2, x, dx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> x1 >> x2 >> t1 >> t2 >> x >> dx;
    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        x = s - x;
        dx *= -1;
    }
    int ans = t2 * (x2 - x1);
    if (t1 < t2) {
        if (x1 < x && dx == 1) {
            x = s + (s - x);
            dx = -1;
        }
        int t = 0;
        if (dx == -1) {
            t = x * t1;
            x = 0;
            dx = 1;
        }
        t += (x2 - x) * t1;
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}