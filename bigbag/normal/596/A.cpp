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

const int max_n = 11, inf = 1111111111;

int n, lx, rx, ly, ry, x[4], y[4];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    lx = ly = inf;
    rx = ry = -inf;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        lx = min(lx, x[i]);
        ly = min(ly, y[i]);
        rx = max(rx, x[i]);
        ry = max(ry, y[i]);
    }
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 4) {
        cout << (rx - lx) * (ry - ly) << endl;
        return 0;
    }
    if (n == 2) {
        if (lx != rx && ly != ry) {
            cout << (rx - lx) * (ry - ly) << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    cout << (rx - lx) * (ry - ly) << endl;
    return 0;
}