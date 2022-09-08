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

const int max_n = 1, inf = 1111111111;

int n, a, b, c, d, e[5];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> c >> d;
    for (int i = 1; i <= n; ++i) {
        int q = a + b + i;
        int l = q + 1, r = q + n;
        e[0] = a + c + i;
        e[1] = b + d + i;
        e[2] = c + d + i;
        for (int j = 0; j < 3; ++j) {
            l = max(l, 1 + e[j]);
            r = min(r, n + e[j]);
        }
        if (l <= r) {
            ans += r - l + 1;
        }
    }
    cout << ans << endl;
    return 0;
}