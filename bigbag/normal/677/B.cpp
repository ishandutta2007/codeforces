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

int n, h, k, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &h, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ) {
        if (x + a[i] > h) {
            int q = (x + a[i] - h) / k;
            if ((x + a[i] - h) % k) {
                ++q;
            }
            x = max(0, x - q * k);
            ans += q;
        }
        while (i < n && x + a[i] <= h) {
            x += a[i];
            ++i;
        }
        ++ans;
        x = max(0, x - k);
    }
    ans += x / k;
    if (x % k) {
        ++ans;
    }
    printf("%I64d\n", ans);
    return 0;
}