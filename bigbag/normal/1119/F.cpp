#include <bits/stdc++.h>

using namespace std;

const int max_n = 250555;
const long long inf = 1000111222000111222LL;

class tree {
public:
    void build(const vector<int> &w) {
        sz = w.size();
        resize(sz + 1);
        if (sz) {
            build(1, 0, sz - 1, w);
        }
    }

    void update(int pos) {
        update(1, 0, sz - 1, pos);
    }

    int get_cnt() const {
        return cnt[1];
    }

    long long get_sum(int c) const {
        return get_sum(1, 0, sz - 1, c);
    }

private:
    int sz;
    vector<long long> sum;
    vector<int> cnt;

    void resize(int sz) {
        sum.resize(sz * 4);
        cnt.resize(sz * 4);
    }

    void build(int v, int l, int r, const vector<int> &w) {
        if (l == r) {
            sum[v] = w[l];
            cnt[v] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid, w);
        build(2 * v + 1, mid + 1, r, w);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
    }

    void update(int v, int l, int r, int pos) {
        if (l == r) {
            sum[v] = 0;
            cnt[v] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(2 * v, l, mid, pos);
        } else {
            update(2 * v + 1, mid + 1, r, pos);
        }
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
    }

    long long get_sum(int v, int l, int r, int c) const {
        if (cnt[v] <= c) {
            return sum[v];
        }
        int mid = (l + r) / 2;
        long long res = get_sum(2 * v, l, mid, c);
        if (cnt[2 * v] < c) {
            res += get_sum(2 * v + 1, mid + 1, r, c - cnt[2 * v]);
        }
        return res;
    }
};

int n, p[max_n], pw[max_n], lev[max_n], f[max_n], pos[max_n];
long long dp[max_n][2], ans[max_n];
vector<pair<int, int>> e[max_n];
vector<int> g[max_n], w[max_n], all[max_n], g2[max_n], w2[max_n];
tree t[max_n];

void dfs(int v) {
    sort(e[v].begin(), e[v].end());
    for (int i = 0; i < e[v].size(); ++i) {
        int to = e[v][i].second;
        if (to == p[v]) {
            continue;
        }
        pos[to] = g[v].size();
        g[v].push_back(to);
        w[v].push_back(e[v][i].first);
        p[to] = v;
        pw[to] = e[v][i].first;
        lev[to] = lev[v] + 1;
        dfs(to);
    }
    t[v].build(w[v]);
}

bool cmp(int v1, int v2) {
    return lev[v1] < lev[v2];
}

int mx;

void get_dp(int v) {
    dp[v][1] = inf;
    dp[v][0] = inf;
    vector<long long> diff;
    long long res = 0;
    for (int i = 0; i < g2[v].size(); ++i) {
        int to = g2[v][i];
        get_dp(g2[v][i]);
        long long add = min(dp[to][0], dp[to][1] + w2[v][i]);
        res += add;
        diff.push_back(dp[to][1] + w2[v][i] - add);
    }
    sort(diff.begin(), diff.end());
    int sz = e[v].size();
    for (int i = 0; i <= diff.size() && mx + i <= sz; ++i) {
        if (t[v].get_cnt() >= sz - mx - i) {
            dp[v][0] = min(dp[v][0], res + t[v].get_sum(sz - mx - i));
        }
        if (sz - mx - i - 1 >= 0 && t[v].get_cnt() >= sz - mx - i - 1) {
            dp[v][1] = min(dp[v][1], res + t[v].get_sum(sz - mx - i - 1));
        }
        if (i < diff.size()) {
            res += diff[i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        e[u].push_back(make_pair(d, v));
        e[v].push_back(make_pair(d, u));
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < e[i].size(); ++j) {
            all[j].push_back(i);
        }
    }
    f[0] = -1;
    for (int deg = n - 1; deg >= 0; --deg) {
        mx = deg;
        sort(all[deg].begin(), all[deg].end(), cmp);
        for (int v : all[deg]) {
            dp[v][0] = dp[v][1] = -1;
            g2[v].clear();
            w2[v].clear();
            f[v] = deg;
        }
        for (int v : all[deg]) {
            if (f[p[v]] == deg) {
                g2[p[v]].push_back(v);
                w2[p[v]].push_back(pw[v]);
                t[p[v]].update(pos[v]);
            }
        }
        //cout << deg << endl;
        for (int v : all[deg]) {
            if (dp[v][0] == -1) {
                get_dp(v);
                //cout << v << ": " << dp[v][0] << ", " << dp[v][1] << " + " << pw[v] << endl;
                if (v == 1) {
                    ans[deg] += dp[v][0];
                } else {
                    ans[deg] += min(dp[v][0], dp[v][1] + pw[v]);
                }
            }
        }
    }
    for (int deg = 0; deg < n; ++deg) {
        printf("%I64d ", ans[deg]);
    }
    printf("\n");
    return 0;
}