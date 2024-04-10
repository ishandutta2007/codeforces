#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 303333, max_c = 26, inf = 1011111111;

int n, pos, sz[max_n], ans[max_n], nxt[max_n][max_c], tm, last[max_n][max_c];
vector<int> all[max_n];
int res;

void proc(int v, int v2) {
    for (int i = 0; i < all[v2].size(); ++i) {
        int col = all[v2][i];
        if (last[v][col] < tm) {
            last[v][col] = tm;
            nxt[v][col] = nxt[v2][col];
        } else {
            ++res;
            proc(nxt[v][col], nxt[v2][col]);
        }
    }
}

void dfs(int v, int lev) {
    sz[v] = 1;
    pair<int, int> mx = make_pair(0, 0);
    for (int i = 0; i < all[v].size(); ++i) {
        int col = all[v][i];
        int to = nxt[v][col];
        dfs(to, lev + 1);
        sz[v] += sz[to];
        mx = max(mx, make_pair(sz[to], to));
    }
    res = all[v].size();
    ++tm;
    for (int i = 0; i < all[v].size(); ++i) {
        int col = all[v][i];
        int to = nxt[v][col];
        if (to != mx.second) {
            proc(mx.second, to);
        }
    }
    ans[lev + 1] -= res;
    //cout << v << " lev = " << lev << "   res = " << res << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        ans[i] = n;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        char c;
        scanf("%d%d %c", &u, &v, &c);
        nxt[u][c] = v;
        all[u].push_back(c);
        last[u][c] = inf;
    }
    dfs(1, 0);
    pair<int, int> mn = make_pair(inf, inf);
    for (int i = 1; i <= n; ++i) {
        //cout << i << ": " << ans[i] << endl;
        mn = min(mn, make_pair(ans[i], i));
    }
    printf("%d\n%d\n", mn.first, mn.second);
    return 0;
}