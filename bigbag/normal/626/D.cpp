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

const int max_n = 5055, inf = 1111111111;

int n, a[max_n], b[max_n], sum[max_n];
long long ans, cnt, all;

long long get_sum(int l, int r) {
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
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && a[i] > a[j]) {
                ++b[a[i] - a[j]];
                ++all;
            }
        }
    }
    sum[0] = b[0];
    for (int i = 1; i < max_n; ++i) {
        sum[i] = b[i] + sum[i - 1];
    }
    for (int x = 1; x < max_n; ++x) {
        for (int y = 1; y < max_n; ++y) {
            int z = x + y + 1;
            if (z < max_n) {
                ans += 1LL * b[x] * b[y] * get_sum(z, max_n - 1);
            }
        }
    }
    cnt = all * all * all;
    printf("%.10f\n", 1.0 * ans / cnt);
    return 0;
}