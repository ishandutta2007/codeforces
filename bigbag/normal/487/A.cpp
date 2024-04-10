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

int a, b, c, x, y, z, c1, c2, c3, ans = inf;

bool ok(int hp, int atk, int def) {
    int cnt1 = inf, cnt2 = inf;
    int dm1 = max(0, atk - z);
    int dm2 = max(0, y - def);
    if (dm1 == 0) {
        return false;
    }
    if (dm2 == 0) {
        return true;
    }
    cnt1 = x / dm1;
    if (x % dm1 != 0) ++cnt1;
    cnt2 = hp / dm2;
    if (hp % dm2 != 0) ++cnt2;
    return cnt1 < cnt2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> x >> y >> z >> c1 >> c2 >> c3;
    for (int i = 0; i < 10011; ++i) {
        for (int j = 0; j < 200; ++j) {
            for (int k = 0; k < 100; ++k) {
                int cost = i * c1 + j * c2 + k * c3;
                if (cost < ans) {
                    if (ok(a + i, b + j, c + k)) {
                        ans = cost;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}