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

const int max_n = 111111, inf = 1111111111;

int n, mx, q, w, md, poz, ans[max_n];
long long m, res, sum[max_n];
pair<int, int> a[max_n];

bool check(int l, int r, int x) {
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid].first <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return 1LL * x * (l + 1) - sum[l] <= m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%I64d", &n, &mx, &q, &w, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    sum[0] = a[0].first;
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i].first;
    }
    res = -1;
    for (int i = 0; i <= n; ++i) {
        if (i) {
            m -= (mx - a[n - i].first);
        }
        if (m < 0) {
            break;
        }
        if (i == n) {
            res = 1LL * q * n + 1LL * w * mx;
            poz = n;
            break;
        }
        int l = a[0].first, r = mx + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(0, n - i, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        long long xx = 0;
        xx += 1LL * i * q;
        xx += 1LL * l * w;
        if (res < xx) {
            res = xx;
            poz = i;
            md = l;
        }
    }
    printf("%I64d\n", res);
    for (int i = n - 1; i >= n - poz; --i) {
        a[i].first = mx;
    }
    for (int i = 0; i < n - poz; ++i) {
        a[i].first = max(md, a[i].first);
    }
    for (int i = 0; i < n; ++i) {
        ans[a[i].second] = a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}