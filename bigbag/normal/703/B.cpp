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

int n, k, sum, a[max_n], f[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        f[num] = 1;
    }
    int sum2 = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            sum2 += a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            ans += 1LL * a[i] * (sum - a[i]);
        } else {
            int pr = i - 1, nxt = (i + 1) % n;
            if (pr == -1) {
                pr += n;
            }
            ans += 1LL * a[i] * (sum2 - f[pr] * a[pr] - f[nxt] * a[nxt] + a[pr] + a[nxt]);
        }
    }
    printf("%I64d\n", ans / 2);
    return 0;
}