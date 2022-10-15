#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
int m;
vector<int> g[N];
vector<int> g2[N];
int c[N];
int now;
int sol;
bool has[N];
bool act[N];
bool vis[N];

void dfs1(int a) {
        c[a] = now;
        for (auto &b : g2[a]) {
                if (c[b] == 0) {
                        dfs1(b);
                }
        }
}

void dfs2(int a) {
        sol++;
        vis[a] = act[a] = 1;
        for (auto &b : g[a]) {
                if (vis[b] == 0) {
                        dfs2(b);
                } else {
                        if (act[b]) {
                                if (has[c[a]] == 0) {
                                        sol++;
                                        has[c[a]] = 1;
                                }
                        }
                }
        }
        act[a] = 0;
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
                int a, b;
                cin >> a >> b;
                g[a].push_back(b);
                g2[a].push_back(b);
                g2[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
                if (c[i] == 0) {
                        sol--;
                        now++;
                        dfs1(i);
                }
        }
        for (int i = 1; i <= n; i++) {
                if (vis[i] == 0) {
                        dfs2(i);
                }
        }
        cout << sol << "\n";
}