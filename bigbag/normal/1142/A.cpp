#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000111222000111222LL;

int n, k, a, b;
long long mn_x = inf, mx_y = -inf;

void go(int s, int nxt) {
    if (nxt == k) {
        return;
    }
    long long l = 1, tot = 1LL * n * k;
    while ((s + l) % k != nxt) {
        ++l;
    }
    while (l <= tot) {
        long long res = tot / __gcd(l, tot);
        mn_x = min(mn_x, res);
        mx_y = max(mx_y, res);
        l += k;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> a >> b;
    go(a, b);
    go(a, k - b);
    go(k - a, b);
    go(k - a, k - b);
    cout << mn_x << " " << mx_y << endl;
    return 0;
}