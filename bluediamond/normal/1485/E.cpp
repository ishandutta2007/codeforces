#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
const int INF = (int) 1e18;
int n, v[N], par[N], dep[N], dm, mn[N], mx[N], dp[N], lol1[N], lol2[N];
vector<int> g[N];
vector<int> la[N];
bool done[N];

void dfs(int a, int p = 0) {
        par[a] = p;
        dep[a] = dep[p] + 1;
        la[dep[a]].push_back(a);
        dm = max(dm, dep[a]);
        vector<int> rl;
        for (auto &b : g[a])
                if (b != p) {
                        dfs(b, a);
                        rl.push_back(b);
                }
        g[a] = rl;
}

int f(int s) {
        return max(abs(v[s] - v[mn[dep[s]]]), abs(v[s] - v[mx[dep[s]]]));
}

int compute(int s) {
        if (dp[s] != -1)
                return dp[s];
        dp[s] = f(s);
        if (s == 1) {
                return dp[s];
        }
        dp[s] += compute(par[s]);
        if (!done[dep[s]]) {
                done[dep[s]] = 1;
                for (auto &s2 : la[dep[s]]) {
                        lol1[dep[s]] = max(lol1[dep[s]], -v[s2] + compute(par[s2]));
                        lol2[dep[s]] = max(lol2[dep[s]], +v[s2] + compute(par[s2]));
                }
        }
        dp[s] = max(dp[s], v[s] + lol1[dep[s]]);
        dp[s] = max(dp[s], -v[s] + lol2[dep[s]]);
        return dp[s];
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);


        ///freopen ("input", "r", stdin);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                dm = 0;
                for (int i = 1; i <= n; i++) {
                        done[i] = 0;
                        dp[i] = -1;
                        la[i].clear();
                        g[i].clear();
                        mn[i] = mx[i] = -1;
                        lol1[i] = lol2[i] = -INF;
                }
                for (int i = 2; i <= n; i++) {
                        int x, y;
                        x = i;
                        cin >> y;
                        g[x].push_back(y);
                        g[y].push_back(x);
                }
                for (int i = 2; i <= n; i++) {
                        cin >> v[i];
                }
                dfs(1);
                for (int i = 1; i <= dm; i++) {
                        mn[i] = mx[i] = la[i][0];
                        for (auto &it : la[i]) {
                                if (v[it] < v[mn[i]])
                                        mn[i] = it;
                                if (v[it] > v[mx[i]])
                                        mx[i] = it;
                        }
                }
                for (int i = 1; i <= dm; i++) {
                        assert(mn[i] != -1);
                        assert(mx[i] != -1);
                }
                int ret = -INF;
                for (auto &x : la[dm])
                        ret = max(ret, compute(x));
                cout << ret << "\n";
        }
}