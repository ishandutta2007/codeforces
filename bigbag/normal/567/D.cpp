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

const int max_n = 222222, inf = 1111111111;

int q, n, k, m, a[max_n], t[max_n];

bool ok(int poz) {
    memset(t, 0, sizeof(t));
    for (int i = 0; i <= poz; ++i) {
        t[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        t[i] += t[i - 1];
    }
    int cnt = 0;
    for (int i = 1; i + m - 1 <= n; ++i) {
        if (t[i + m - 1] == t[i - 1]) {
            ++cnt;
            i += m;
        }
    }
    return cnt >= k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &k, &m, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &a[i]);
    }
    int l = -1, r = q;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r == q) {
        r = -2;
    }
    printf("%d\n", r + 1);
    return 0;
}