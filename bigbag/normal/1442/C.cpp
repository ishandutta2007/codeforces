#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222, mod = 998244353;
const int max_k = 20;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, m, dp1[max_k][max_n];
vector<int> g[2][max_n];

const int max_d = 1000111;

vector<pair<int, int>> all[max_d];

void update(int k, int v, int res) {
    if (k >= max_k) {
        return;
    }
    if (dp1[k][v] == -1 || dp1[k][v] > res) {
        dp1[k][v] = res;
        all[res].push_back({k, v});
    }
}

int calc_dp1() {
    memset(dp1, -1, sizeof(dp1));
    dp1[0][0] = 0;
    all[0].push_back({0, 0});
    for (int d = 0; d < max_d; ++d) {
        for (auto p : all[d]) {
            const int k = p.first, v = p.second;
            if (dp1[k][v] != d) {
                continue;
            }
            const int tp = k % 2;
            if (k + 1 < max_k) {
                update(k + 1, v, d + (1 << k));
            }
            for (int to : g[tp][v]) {
                update(k, to, d + 1);
            }
        }
    }
    int ans = inf;
    for (int k = 0; k < max_k; ++k) {
        if (dp1[k][n - 1] != -1) {
            ans = min(ans, dp1[k][n - 1]);
        }
    }
    return ans;
}

pair<int, int> dp2[2][max_n];

struct state {
    int k, d, tp, v;

    state(int k, int d, int tp, int v): k(k), d(d), tp(tp), v(v) {
    }

    bool operator < (const state &s) const {
        return make_pair(k, d) > make_pair(s.k, s.d);
    }
};


priority_queue<state> q;

void update2(int k, int d, int tp, int v) {
    if (dp2[tp][v] > make_pair(k, d)) {
        dp2[tp][v] = {k, d};
        q.push({k, d, tp, v});
    }
}

pair<int, int> calc_dp2() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            dp2[i][j] = {inf, inf};
        }
    }
    dp2[0][0] = {0, 0};
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
        state s = q.top();
        q.pop();
        if (make_pair(s.k, s.d) != dp2[s.tp][s.v]) {
            continue;
        }
        update2(s.k + 1, s.d, s.tp ^ 1, s.v);
        for (int to : g[s.tp][s.v]) {
            update2(s.k, s.d + 1, s.tp, to);
        }
    }
    return min(dp2[0][n - 1], dp2[1][n - 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }
    int ans = calc_dp1();
    pair<int, int> p = calc_dp2();
    long long res = p.second;
    int pw = 1;
    for (int i = 0; i < p.first; ++i) {
        res += pw;
        pw = mul(pw, 2);
    }
    if (ans != inf) {
        res = min(res, 1LL * ans);
    }
    res %= mod;
    cout << res << "\n";
    return 0;
}