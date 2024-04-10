#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int c[N];
vector<int> g[N], black;
bool vis[N];
int k;

inline void bfs(int x) {
    vector<int> tmpblack, tmpwhite;
    tmpwhite.push_back(x);

    queue<int> que;
    que.push(x);
    vis[x] = 1;

    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (auto to :g[tmp]) {
            if (c[to]) tmpblack.push_back(to);
            else {
                if (vis[to]) continue;
                vis[to] = 1;
                tmpwhite.push_back(to);
                que.push(to);
            }
        }
    }

    sort(tmpblack.begin(), tmpblack.end(), [&](int x, int y) { return x < y; });
    tmpblack.erase(unique(tmpblack.begin(), tmpblack.end()), tmpblack.end());
    if (tmpblack.size() == k) return;

    for (auto u : tmpwhite) c[u] = 1;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        if (c[i] == 1) black.push_back(i);
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int siz = black.size();
    k = siz;
    for (int i = 0; i < siz; ++i) {
        for (auto to : g[black[i]]) {
            c[to] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i] || c[i]) continue;
        vis[i] = 1;
        bfs(i);
    }
    for (int i = 1; i <= n; ++i) cout << c[i] << " ";
    return 0;
}