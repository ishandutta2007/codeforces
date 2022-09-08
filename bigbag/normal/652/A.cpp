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

int h, a, b, x, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> h >> a >> b;
    int k = 8;
    while (true) {
        if (x + k * a >= h) {
            cout << ans << endl;
            return 0;
        }
        ++ans;
        x += k * a - 12 * b;
        k = 12;
        if (ans > 10 && a - b <= 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    return 0;
}