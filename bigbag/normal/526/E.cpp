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

const int max_n = 1011111, inf = 1111111111;

int n, q, ans, a[max_n], dp[max_n], last[max_n], r[max_n];
long long sum, x, allsum;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        allsum += a[i];
    }
    while (q--) {
        scanf("%d", &x);
        if (allsum <= x) {
            printf("1\n");
            continue;
        }
        sum = a[0];
        int poz = n - 1;
        while (sum + a[poz] <= x) {
            sum += a[poz];
            --poz;
        }
        int rr = n - 1;
        r[n - 1] = rr;
        last[n - 1] = n - 1;
        dp[n - 1] = 1;
        long long sum2 = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sum2 += a[i];
            while (sum2 > x) {
                sum2 -= a[rr];
                --rr;
            }
            r[i] = rr;
            dp[i] = 1 + dp[rr + 1];
            last[i] = last[rr + 1];
            if (dp[i] == 1) {
                last[i] = i;
            }
        }
        ans = inf;
        for (int i = 0; i + 1 < n; ++i) {
            bool qqq = (last[i + 1] >= poz + 1);
            //cout << i << " " << 1 + dp[i + 1] - qqq << "   " << poz << "   " << last[i + 1] << endl;
            ans = min(ans, 1 + dp[i + 1] - qqq);
            sum += a[i + 1];
            while (sum > x && poz < n) {
                ++poz;
                sum -= a[poz];
            }
            if (poz == n) {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}