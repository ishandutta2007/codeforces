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

const int max_n = 1001111;
const long long inf = 1000111222333444555LL;

int n, x, y, a[max_n], used[max_n];
long long sum[2][max_n];

void get_all_p() {
    for (int i = 2; i < max_n; ++i) {
        if (used[i] == 0 && i < 40000) {
            for (int j = i * i; j < max_n; j += i) {
                used[j] = 1;
            }
        }
    }
}

long long get_sum(int tp, int l, int r) {
    if (l == 0) {
        return sum[tp][r];
    }
    return sum[tp][r] - sum[tp][l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_p();
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++sum[0][a[i]];
        sum[1][a[i]] += a[i];
    }
    for (int tp = 0; tp < 2; ++tp) {
        for (int i = 1; i < max_n; ++i) {
            sum[tp][i] += sum[tp][i - 1];
        }
    }
    int mx = x / y;
    long long ans = inf;
    for (int i = 2; i < max_n; ++i) {
        if (used[i] == 0) {
            int cnt = 0;
            long long res = 0;
            for (int j = i; j < 2 * max_n; j += i) {
                int l = max(j - i + 1, j - mx), r = min(j, max_n - 1);
                if (l > r) {
                    continue;
                }
                int c = get_sum(0, l, r);
                cnt += c;
                res += 1LL * c * j - get_sum(1, l, r);
            }
            res *= y;
            cnt = n - cnt;
            if (ans > res + 1LL * cnt * x) {
                ans = res + 1LL * cnt * x;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}