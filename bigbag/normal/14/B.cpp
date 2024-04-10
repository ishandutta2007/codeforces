#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, x, lp, rp;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> lp >> rp;
    if (lp > rp) swap(lp, rp);
    for (int i = 1; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        lp = max(lp, l);
        rp = min(rp, r);
    }
    if (lp <= rp) {
        if (lp <= x && x <= rp) {
            cout << 0;
        } else {
            cout << min(fabs(lp - x), fabs(rp - x));
        }
    }
    else {
        cout << -1;
    }
    return 0;
}