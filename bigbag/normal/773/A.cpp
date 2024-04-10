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

const int max_n = 1011;
const long long inf = 1011111111000000000LL;

int t, x, y, p, q;

long long solve(int x, int y, int p, int q) {
    if (p == 0) {
        if (x == 0) {
            return 0;
        }
        return -1;
    }
    if (p == q) {
        if (x == y) {
            return 0;
        }
        return -1;
    }
    long long ma = (1LL * y * p - 1LL * x * q + q - p - 1) / (q - p);
    ma = max(0LL, ma);
    ma += x;
    if (ma % p) {
        ma += p - ma % p;
    }
    ma /= p;
    ma *= q;
    return ma - y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> y >> p >> q;
        cout << solve(x, y, p, q) << endl;
    }
    return 0;
}