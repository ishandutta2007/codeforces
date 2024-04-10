#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int m, a, b, dp[max_n];
priority_queue<pair<int, int>> q;
long long ans;

long long get_sum(int r) {
    return (1LL * r * (r + 1)) / 2;
}

long long get_sum(int l, int r) {
    return get_sum(r) - get_sum(l - 1);
}

int get_cnt(int r) {
    return r / a + 1;
}

int get_cnt(int l, int r, int x) {
    l -= x;
    r -= x;
    return get_cnt(r) - get_cnt(l - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> m >> a >> b;
    for (int i = 0; i < max_n; ++i) {
        dp[i] = inf;
    }
    q.push({0, 0});
    dp[0] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int v = p.second, d = -p.first;
        if (d != dp[v]) {
            continue;
        }
        if (v >= b && dp[v - b] > dp[v]) {
            dp[v - b] = dp[v];
            q.push({-dp[v - b], v - b});
        }
        if (v + a < max_n && dp[v + a] > max(v + a, dp[v])) {
            dp[v + a] = max(v + a, dp[v]);
            q.push({-dp[v + a], v + a});
        }
    }
    int to = max_n - 1;
    while (to % a) {
        --to;
    }
    for (int i = 0; i < to && i <= m; ++i) {
        if (dp[i] != inf) {
            ans += max(0, m - dp[i] + 1);
        }
    }
    if (to <= m) {
        for (int i = 0; i < a; ++i) {
            if (dp[i] != inf) {
                int cnt = get_cnt(to, m, i);
                ans += 1LL * (m + 1 - to - i) * cnt - 1LL * a * get_sum(cnt - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}