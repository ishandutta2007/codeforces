#include <map>
#include <set>
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

const int max_n = 1000011, max_x = 10000011, inf = 10000000;

int n, k, a[max_n], used[max_x];
long long ans[max_x], cnt[max_x];
vector <int> p;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 2; i <= inf; ++i) {
        if (used[i] == 0) {
            p.push_back(i);
            for (int j = 2; j <= n / i; ++j) {
                used[i * j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; p[j] * p[j] <= a[i]; ++j) {
            if (a[i] <= 1) {
                break;
            }
            if (a[i] % p[j] == 0) {
                ++cnt[p[j]];
                while (a[i] % p[j] == 0) {
                    a[i] /= p[j];
                }
            }
        }
        if (a[i] != 1) {
            ++cnt[a[i]];
        }
    }
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = cnt[2];
    for (int i = 3; i < max_x; ++i) {
        ans[i] = ans[i - 1] + cnt[i];
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r >= max_x) {
            r = max_x - 1;
        }
        if (l > r) {
            l = r;
        }
        if (l == 0) {
            printf("%I64d\n", ans[r]);
        } else {
            printf("%I64d\n", ans[r] - ans[l - 1]);
        }
    }
    return 0;
}