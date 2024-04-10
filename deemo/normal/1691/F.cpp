#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, k;
vector<int> adj[MAXN];

int ss[MAXN], tt[MAXN];
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1ll*res*a%MOD;
        b >>= 1;
        a = 1ll*a*a%MOD;
    }
    return res;
}

void prep() {
    ss[0] = 1;
    for (int i = 1; i < MAXN; i++)
        ss[i] = 1ll* ss[i-1] * i % MOD;
    tt[0] = 1;
    for (int i = 1; i < MAXN; i++)
        tt[i] = 1ll*tt[i-1]*pw(i, MOD-2) % MOD;
}

int choose(int a, int b) {
    if (a < b) return 0;
    return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

int fix(int x) {
    while (x < 0) x += MOD;
    while (x >= MOD) x -= MOD;
    return x;
}

int sub[MAXN], ways[MAXN], ta[MAXN];
ll cur, ans;
void dfs(int v, int p = -1) {
    if (~p)
        adj[v].erase(find(adj[v].begin(), adj[v].end(), p));

    sub[v] = 1;
    for (int u: adj[v]) {
        dfs(u, v), sub[v] += sub[u];
        ways[v] = fix(ways[v] - choose(sub[u], k));
    }
    ta[v] = fix(-ways[v]);
    ways[v] = fix(ways[v] + choose(sub[v], k));
    cur = (cur + 1ll*ways[v]*sub[v]) % MOD;
}

void go(int v) {
    //cout << v << "  " << cur << endl;
    ans = fix(ans + cur);
    for (int u: adj[v]) {
        int c1 = cur;
        cur = fix(cur - 1ll*ways[v]*sub[v]%MOD);
        cur = fix(cur - 1ll*ways[u]*sub[u]%MOD);
        int ta1 = ta[v], ta2 = ta[u];
        ta[v] = fix(ta[v] - choose(sub[u], k));
        sub[v] -= sub[u];
        sub[u] = n;
        ta[u] = fix(ta[u] + choose(sub[v], k));

        int w1 = ways[v], w2 = ways[u];
        ways[v] = fix(choose(sub[v], k) - ta[v]);
        ways[u] = fix(choose(n, k) - ta[u]);
        cur = fix(cur + 1ll*ways[v]*sub[v]%MOD);
        cur = fix(cur + 1ll*ways[u]*sub[u]%MOD);

        go(u);

        sub[u] -= sub[v];
        sub[v] = n;
        ta[v] = ta1;
        ta[u] = ta2;
        ways[v] = w1;
        ways[u] = w2;
        cur = c1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    prep();
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    go(0);
    cout << ans << "\n";
    return 0;
}