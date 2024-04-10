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

const int max_n = 111111, inf = 2111111111;

int n, k, a[max_n], b[max_n];

bool check(long long x) {
    long long o = k;
    for (int i = 0; i < n; ++i) {
        long long f = 1LL * a[i] * x;
        if (f > b[i]) {
            f -= b[i];
            o -= f;
        }
        if (o < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    long long l = 0, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%I64d\n", l);
    return 0;
}