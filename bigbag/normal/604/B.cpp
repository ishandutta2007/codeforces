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

const int max_n = 111111, inf = 1011111111;

int n, k, a[max_n], used[max_n];

bool ok(int x) {
    memset(used, 0, sizeof(used));
    int l = 0, r = n - 1, res = 0;
    while (l < n) {
        if (a[l] > x) {
            return false;
        }
        if (used[l] == 0) {
            used[l] = 1;
            while (r >= 0 && a[l] + a[r] > x) {
                --r;
            }
            if (r >= 0) {
                used[r] = 1;
                --r;
            }
            ++res;
        }
        ++l;
    }
    return res <= k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 0, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}