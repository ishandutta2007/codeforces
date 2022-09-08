/**
 *  created: 23/05/2022, 18:00:44
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, ans = inf;
long long x, need;

int best(long long x, int ops) {
    while (x < need) {
        x *= 9;
        ++ops;
    }
    return ops;
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void rec(long long x, int ops) {
    if (best(x, ops) >= ans) {
        return;
    }
    if (x >= need) {
        ans = ops;
    }
    int mask = 0;
    long long kx = x;
    while (kx) {
        mask |= 1 << (kx % 10);
        kx /= 10;
    }
    for (int k = 9; k >= 2; --k) {
        if (get_bit(mask, k)) {
            rec(x * k, ops + 1);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    --n;
    need = 1;
    while (n--) {
        need *= 10;
    }
    rec(x, 0);
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << "\n";
    return 0;
}