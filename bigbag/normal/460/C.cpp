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

long long n, m, w, a[max_n], h[max_n];

bool check(long long x) {
    long long sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        h[i] = max(0LL, x - sum - a[i]);
        cnt += h[i];
        sum += h[i];
        if (i - w + 1 >= 0) {
            sum -= h[i - w + 1];
        }
    }
    return cnt <= m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 0, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}