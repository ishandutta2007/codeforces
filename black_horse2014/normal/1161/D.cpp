#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
const int P = 998244353;

vector<pair<int, int> > adj[N];
int a[N], b[N], vis[N], col[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.length();
    if (s[n-1] == '1') return puts("0"), 0;
    auto add = [&](int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    };
    int ret = 0;
    for (int m = 1; m < n; m++) {
        int num = 0;
        for (int i = 1; i <= (n-1)/2; i++) a[n-1-i] = a[i] = ++num;
        for (int i = 1; i <= (m-1)/2; i++) b[m-1-i] = b[i] = ++num;
        for (int i = 0; i <= num; i++) adj[i].clear();
        a[0] = a[n-1] = b[0] = b[m-1] = 0;
        for (int i = 1; i < n-1; i++) {
            int u = a[i], v = (i < n-m ? -1 : b[i-(n-m)]);
            if (s[i] == '?') continue;
            if (v == -1) {
                add(u, 0, '1'-s[i]);
            } else {
                add(u, v, s[i]-'0');
            }
        }
        int T = 0;
        for (int i = 0; i <= num; i++) col[i] = -1, vis[i] = 0;
        function<bool(int, int)> dfs = [&](int u, int c) {
            col[u] = c;
            vis[u] = T;
            for (auto t : adj[u]) {
                int v = t.first;
                int w = t.second;
                if (col[v] >= 0) {
                    if (col[u] + col[v] + w & 1) return 0;
                } else {
                    if (!dfs(v, c ^ w)) return 0;
                }
            }
            return 1;
        };
        int ans = 1;
        for (int i = 0; i <= num; i++) if (!~col[i]) {
            ++T;
            if (!dfs(i, 0)) {
                ans = 0;
                break;
            }
            if (i) ans = ans * 2 % P;
        }
        ret = (ret + ans) % P;
    }
    cout << ret << endl;
    return 0;
}