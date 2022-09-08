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

const int max_n = 101111;
const long long inf = 1000111222333444555LL;

struct state {
    int d, u, v, cost;
    void read() {
        scanf("%d%d%d%d", &d, &u, &v, &cost);
    }
    bool operator < (const state &s) const {
        return d < s.d;
    }
};

int n, m, k, used[max_n];
state s[max_n];
long long ans = inf, dp1[max_n], dp2[max_n];

void inv() {
    reverse(s, s + m);
    for (int i = 0; i < m; ++i) {
        swap(s[i].u, s[i].v);
    }
}

void get_dp(long long dp[max_n]) {
    memset(used, -1, sizeof(used));
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        if (s[i].v == 0) {
            int v = s[i].u;
            if (used[v] == -1) {
                used[v] = s[i].cost;
                ++cnt;
                sum += used[v];
            } else {
                sum -= used[v];
                used[v] = min(used[v], s[i].cost);
                sum += used[v];
            }
        }
        if (cnt == n) {
            dp[i] = sum;
        } else {
            dp[i] = inf;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        s[i].read();
    }
    sort(s, s + m);
    get_dp(dp1);
    inv();
    get_dp(dp2);
    inv();
    reverse(dp2, dp2 + m);
    dp2[m] = inf;
    int pos = 0;
    for (int i = 0; i < m; ++i) {
        while (pos < m && s[i].d + k >= s[pos].d) {
            ++pos;
        }
        ans = min(ans, dp1[i] + dp2[pos]);
    }
    if (ans == inf) {
        ans = -1;
    }
    printf("%I64d\n", ans);
    return 0;
}