#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
const ll OO = (ll) 1e18;
int n;
ll add[N];
ll cur[N];
ll ans = -OO;
int cnt;
vector<int> g[N];

void dfs1(int a, int p) {
        cur[a] = add[a];
        for (auto &b : g[a]) {
                if (b != p) {
                        dfs1(b, a);
                        if (cur[b] > 0) {
                                cur[a] += cur[b];
                        }
                }
        }
        ans = max(ans, cur[a]);
}

void dfs2(int a, int p) {
        cur[a] = add[a];
        for (auto &b : g[a]) {
                if (b != p) {
                        dfs2(b, a);
                        if (cur[b] > 0) {
                                cur[a] += cur[b];
                        }
                }
        }
        if (cur[a] == ans) {
                cur[a] = -OO;
                cnt++;
        }
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> add[i];
        }
        for (int i = 1; i < n; i++) {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        dfs1(1, -1);
        dfs2(1, -1);
        cout << ans * cnt << " " << cnt << "\n";
}