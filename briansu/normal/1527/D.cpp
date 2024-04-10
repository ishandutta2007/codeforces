#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 2e5 + 5;
vector<int> v[MAXn];
int n, sz[MAXn], p[MAXn], vis[MAXn], chld[MAXn];
ll ans[MAXn];

void dfs(int now, int f) {
    sz[now] = 1;
    p[now] = f;
    for (auto k : v[now])
        if (k != f)
            dfs(k, now), sz[now] += sz[k];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            v[i].clear(), vis[i] = chld[i] = 0;
        fill_n(ans, n + 2, 0);
        for (int i = 1, a, b; i < n; i++)
            cin >> a >> b, v[a].pb(b), v[b].pb(a);
        dfs(0, 0);
        ans[0] = (ll)n * (n - 1) / 2;
        for (int k : v[0])
            ans[0] -= (ll)sz[k] * (sz[k] - 1) / 2;
        bool fg = 0;
        set<int> st;
        vis[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int x = i; !vis[x]; x = p[x]) {
                vis[x] = 1;
                if (chld[p[x]] && p[x] != 0)
                    fg = 1;
                if (vis[p[x]] && !chld[p[x]])
                    st.erase(p[x]);
                chld[p[x]] = x;
                if (!chld[x])
                    st.insert(x);
            }
            if (fg || SZ(st) > 2)
                break;
            if (SZ(st) == 1) {
                int x = *st.begin();
                ans[i] += (ll)sz[x] * (sz[0] - sz[chld[0]]);
            }
            else {
                int x = *st.begin();
                int y = *next(st.begin());
                ans[i] += (ll)sz[x] * sz[y];
            }
        }
        ll s = (ll)n * (n - 1) / 2;
        for (int i = 0; i <= n; i++)
            cout << s - ans[i] << " \n"[i == n], s = ans[i];
    }
}