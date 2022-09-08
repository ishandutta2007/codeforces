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

int n, k, x;
long long ans, a[max_n], s1[max_n], s2[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
    }
    s1[0] = a[0];
    for (int i = 1; i < n; ++i) {
        s1[i] = s1[i - 1] | a[i];
    }
    s2[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        s2[i] = s2[i + 1] | a[i];
    }
    for (int i = 0; i < n; ++i) {
        long long y = a[i];
        for (int j = 0; j < k; ++j) {
            y *= x;
        }
        if (i) {
            y |= s1[i - 1];
        }
        if (i + 1 < n) {
            y |= s2[i + 1];
        }
        ans = max(ans, y);
    }
    printf("%I64d\n", ans);
    return 0;
}