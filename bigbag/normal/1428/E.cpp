#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011;
const long long inf = 1000111222333LL;

int n, k, a[max_n], b[max_n];

long long func(long long x, int cnt) {
    long long y = x / cnt;
    x %= cnt;
    return x * (y + 1) * (y + 1) + (cnt - x) * y * y;
}

long long get_cnt(long long x) {
    long long res = 0;
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        while (cur < a[i] && func(a[i], cur) - func(a[i], cur + 1) >= x) {
            ++cur;
        }
        b[i] = cur;
        res += cur - 1;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    k -= n;
    long long l = 0, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (get_cnt(mid) <= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    k -= get_cnt(r);
    //cout << "$" << k << " " << r << endl;
    long long ans = -k * l;
    for (int i = 0; i < n; ++i) {
        ans += func(a[i], b[i]);
    }
    cout << ans << "\n";
    return 0;
}