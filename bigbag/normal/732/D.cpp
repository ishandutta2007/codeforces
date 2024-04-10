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

int n, m, a[max_n], b[max_n], used[max_n];

bool check(int last) {
    memset(used, 0, sizeof(used));
    int res = 0, x = 0;
    for (int i = last; i >= 0; --i) {
        if (a[i] && used[a[i]] == 0) {
            used[a[i]] = 1;
            x += b[a[i]];
            ++res;
        } else {
            if (x) {
                --x;
            }
        }
    }
    return res == m && x == 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
    }
    //cout << check(n - 1);
    //return 0;
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == n) {
        r = -2;
    }
    printf("%d\n", r + 1);
    return 0;
}