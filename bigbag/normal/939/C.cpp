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

const int max_n = 200111, inf = 1000111222;

int n, l, r, a[max_n], sum[max_n];
int ans, pos = inf;

int get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
        a[i + n] = a[i];
        sum[i + n] = a[i];
    }
    scanf("%d%d", &l, &r);
    int len = r - l;
    for (int i = 1; i <= 2 * n; ++i) {
        sum[i] += sum[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        if (get_sum(i, i + len - 1) > ans) {
            ans = get_sum(i, i + len - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (get_sum(i, i + len - 1) == ans) {
            int res = l - 1;
            res -= i;
            res += n;
            res %= n;
            pos = min(pos, res + 1);
        }
    }
    printf("%d\n", pos);
    return 0;
}