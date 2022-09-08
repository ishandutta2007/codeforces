#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_p = 70;

int t, z[max_p], pos[max_p];
long long ans[max_n];
pair<long long, int> p[max_n];

long long sq(long long n) {
    int l = 0, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (1LL * mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

bool ok(long long x, int p, long long n) {
    long long res = 1;
    for (int i = 0; i < p; ++i) {
        if (res > n / x) {
            return false;
        }
        res *= x;
    }
    return res <= n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%I64d", &p[i].first);
        p[i].second = i;
    }
    sort(p, p + t);
    for (int i = 2; i < max_p; ++i) {
        int rz = -1 - z[i];
        z[i] = rz;
        for (int j = 2 * i; j < max_p; j += i) {
            z[j] += rz;
        }
        pos[i] = 1;
    }
    for (int i = 0; i < t; ++i) {
        long long n = p[i].first;
        long long res = n - sq(n) + 1;
        for (int j = 3; j < max_p; ++j) {
            while (ok(pos[j] + 1, j, n)) {
                ++pos[j];
            }
            res += z[j] * (pos[j] - 1);
        }
        ans[p[i].second] = res - 1;
    }
    for (int i = 0; i < t; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}