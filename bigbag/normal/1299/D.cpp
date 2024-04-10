#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, mod = 1000000007;
const int max_mask = 777;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int n, m, x[max_n], used[max_n], h[max_n], dp[2][max_mask];
int nxt[max_mask][max_mask];
vector<int> g[max_n], w[max_n];
vector<long long> masks;

bool get_bit(long long mask, int pos) {
    return (mask >> pos) & 1;
}

int compress(long long x) {
    int res = lower_bound(masks.begin(), masks.end(), x) - masks.begin();
    if (res >= masks.size() || masks[res] != x) {
        return -1;
    }
    return res;
}

vector<int> basis;

bool add(vector<int> &basis, int x) {
    for (int y : basis) {
        if ((x ^ y) < x) {
            x ^= y;
        }
    }
    if (!x) {
        return false;
    }
    for (int &y : basis) {
        if ((x ^ y) < y) {
            y ^= x;
        }
    }
    basis.push_back(x);
    return true;
}

long long get_all(const vector<int> &basis) {
    long long res = 0;
    for (int mask = 1; mask < (1 << basis.size()); ++mask) {
        int x = 0;
        for (int i = 0; i < basis.size(); ++i) {
            if (get_bit(mask, i)) {
                x ^= basis[i];
            }
        }
        res |= 1LL << x;
    }
    return res;
}

long long upd(long long res) {
    basis.clear();
    for (int i = 0; i < 32; ++i) {
        if (get_bit(res, i)) {
            if (!add(basis, i)) {
                return -1;
            }
        }
    }
    return get_all(basis);
}

int get_nxt(long long m1, long long m2) {
    vector<int> v1, v2;
    for (int i = 0; i < 32; ++i) {
        if (get_bit(m1, i)) {
            add(v1, i);
        }
        if (get_bit(m2, i)) {
            add(v2, i);
        }
    }
    for (int x : v2) {
        if (!add(v1, x)) {
            return -1;
        }
    }
    return compress(get_all(v1));
}

void rec(int pos, long long mask) {
    if (pos == 32) {
        masks.push_back(upd(mask));
        return;
    }
    rec(pos + 1, mask);
    vector<int> cp = basis;
    if (add(basis, pos)) {
        rec(pos + 1, mask | (1LL << pos));
        basis = cp;
    }
}

int f, bad;
long long mask, mask1;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to]) {
            h[to] = h[v] + 1;
            x[to] = x[v] ^ w[v][i];
            dfs(to);
        } else if (h[to] + 1 < h[v]) {
            int X = x[v] ^ x[to] ^ w[v][i];
            //cout << X << ", " << v << " -> " << to << endl;
            if (to == 0) {
                mask1 |= 1LL << X;
                assert(f == 0);
                f = 1;
            } else {
                if (get_bit(mask, X)) {
                    bad = 1;
                }
                mask |= 1LL << X;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    rec(0, 0);
    sort(masks.begin(), masks.end());
    masks.erase(unique(masks.begin(), masks.end()), masks.end());
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
        w[u].push_back(x);
        w[v].push_back(x);
    }
    used[0] = 1;
    for (int i = 0; i < masks.size(); ++i) {
        for (int j = i; j < masks.size(); ++j) {
            nxt[i][j] = nxt[j][i] = get_nxt(masks[i], masks[j]);
        }
    }
    int q1 = 0, q2 = 1;
    dp[q1][0] = 1;
    for (int i = 0; i < g[0].size(); ++i) {
        if (used[g[0][i]]) {
            continue;
        }
        x[g[0][i]] = w[0][i];
        h[g[0][i]] = 1;
        mask = 0;
        mask1 = 0;
        f = 0;
        bad = 0;
        dfs(g[0][i]);
        mask = upd(mask);
        mask1 = upd(mask1);
        vector<int> m;
        if (f == 0) {
            m.push_back(0);
            if (!bad && mask != -1) {
                m.push_back(compress(mask));
            }
        } else {
            m.push_back(0);
            if (!bad && mask != -1) {
                m.push_back(compress(mask));
                m.push_back(compress(mask));
                if (mask1 != -1) {
                    m.push_back(nxt[compress(mask)][compress(mask1)]);
                }
            }
        }
        memset(dp[q2], 0, sizeof(dp[q2]));
        for (int cur = 0; cur < masks.size(); ++cur) {
            if (!dp[q1][cur]) {
                continue;
            }
            for (int M : m) {
                if (M == -1 || nxt[cur][M] == -1) {
                    continue;
                }
                dp[q2][nxt[cur][M]] += dp[q1][cur];
                if (dp[q2][nxt[cur][M]] >= mod) {
                    dp[q2][nxt[cur][M]] -= mod;
                }
            }
        }
        swap(q1, q2);
    }
    long long ans = 0;
    for (int cur = 0; cur < masks.size(); ++cur) {
        ans += dp[q1][cur];
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}