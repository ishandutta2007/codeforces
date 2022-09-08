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

const int max_n = 311111, inf = 1111111111;

int n, a[max_n];
long long dp[max_n], ans[max_n];
pair<int, pair<int, int> > p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &p[i].second.first, &p[i].first);
        p[i].second.second = i;
    }
    sort(p, p + q);
    int lastb = -1;
    for (int i = 0; i < q; ++i) {
        if (p[i].first > 500) {
            for (int j = p[i].second.first; j <= n; j += p[i].first) {
                ans[p[i].second.second] += a[j];
            }
        } else {
            if (lastb != p[i].first) {
                lastb = p[i].first;
                for (int i = n; i > 0; --i) {
                    dp[i] = a[i];
                    if (i + lastb <= n) {
                        dp[i] += dp[i + lastb];
                    }
                }
            }
            ans[p[i].second.second] = dp[p[i].second.first];
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}