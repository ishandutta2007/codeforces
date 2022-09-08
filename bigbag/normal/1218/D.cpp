#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

const int max_lev = 17;
const int max_n = 1 << max_lev;
const int mod = 1000000007;
const int mod1 = 1000000009;

int n, dp[max_n], sz[max_n], used[max_n], parent[max_n], pw[max_n];
int ans[max_n], cnt[max_n], h[max_n];
int ans1[max_n], cnt1[max_n];
vector<int> g[max_n], w[max_n];

int mul(int x, int y, int mod) {
    return 1LL * x * y % mod;
}

int power(int x, int y, int mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(mul(x, x, mod), y / 2, mod);
    }
    return mul(x, power(x, y - 1, mod), mod);
}

int rn = power(max_n, mod - 2, mod), all;
int rn1 = power(max_n, mod1 - 2, mod1);

void proc(int lev, int *a, int mod) {
    if (lev == 0) {
        return;
    }
    const int n = 1 << (lev - 1);
    for (int i = 0; i < n; ++i) {
        int x = (a[i] + a[i + n]) % mod;
        int y = (a[i] + mod - a[i + n]) % mod;
        a[i] = x;
        a[i + n] = y;
    }
    proc(lev - 1, a, mod);
    proc(lev - 1, a + n, mod);
}

void dfs(int v, int p) {
    used[v] = 1;
    parent[v] = p;
    //cout << "@" << v << endl;
    for (int i = 0; i < g[v].size(); ++i) {
        const int to = g[v][i];
        if (to == p) {
            continue;
        }
        if (used[to]) {
            if (h[to] > h[v]) {
                continue;
            }
            //cout << "$" << v << " " << to << endl;
            memset(cnt, 0, sizeof(cnt));
            memset(cnt1, 0, sizeof(cnt1));
            cnt[w[v][i]] = 1;
            cnt1[w[v][i]] = 1;
            int cur = v;
            while (true) {
                if (cur == to) {
                    break;
                }
                ++cnt[pw[cur]];
                ++cnt1[pw[cur]];
                cur = parent[cur];
            }
            proc(max_lev, cnt, mod);
            proc(max_lev, cnt1, mod1);
            for (int i = 0; i < max_n; ++i) {
                ans[i] = mul(ans[i], cnt[i], mod);
                ans1[i] = mul(ans1[i], cnt1[i], mod1);
            }
        } else {
            h[to] = h[v] + 1;
            pw[to] = w[v][i];
            dfs(to, v);
        }
    }
}

int main() {
    //freopen("inputD.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        --u;
        --v;
        g[u].push_back(v);
        w[u].push_back(x);
        g[v].push_back(u);
        w[v].push_back(x);
        all ^= x;
    }
    ans[all] = 1;
    ans1[all] = 1;
    proc(max_lev, ans, mod);
    proc(max_lev, ans1, mod1);
    dfs(0, -1);
    proc(max_lev, ans, mod);
    proc(max_lev, ans1, mod1);
    for (int i = 0; i < max_n; ++i) {
        ans[i] = mul(ans[i], rn, mod);
        ans1[i] = mul(ans1[i], rn1, mod1);
    }
    for (int i = 0; i < max_n; ++i) {
        //assert(ans[i] == ans1[i]);
        if (ans[i] || ans1[i]) {
            printf("%d %d", i, ans[i]);
            return 0;
        }
    }
    return 0;
}