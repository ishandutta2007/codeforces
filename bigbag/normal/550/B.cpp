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

const int max_n = 22, inf = 1111111111;

int n, l, r, x, ans, a[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = 0, sum = 0, mx = -inf, mn = inf;
        for (int i = 0; i < n; ++i) {
            if (get_bit(mask, i)) {
                ++cnt;
                sum += a[i];
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
        if (cnt >= 2 && l <= sum && sum <= r && mx - mn >= x) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}