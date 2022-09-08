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

long long n, lx, rx, ly, ry, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    lx = 1e10;
    ly = 1e10;
    rx = -1e10;
    ry = -1e10;
    while (n--) {
        cin >> x >> y;
        lx = min(lx, x);
        rx = max(rx, x);
        ly = min(ly, y);
        ry = max(ry, y);
    }
    n = max(rx - lx, ry - ly);
    cout << n * n << endl;
    return 0;
}