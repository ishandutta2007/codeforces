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

const int max_n = 333333, inf = 1111111111;

int pw1 = 37, mod1 = 1000000007;
int pw2 = 43, mod2 = 1000000009;

int n, a[max_n];
char s[max_n];
vector<int> g[max_n];

set<pair<int, int> > dfs(int v, int h1, int h2, int p) {
    h1 = (1LL * h1 * pw1 + s[v - 1] - 'a' + 1) % mod1;
    h2 = (1LL * h2 * pw2 + s[v - 1] - 'a' + 1) % mod2;
    set<pair<int, int> > res, to;
    res.insert(make_pair(h1, h2));
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            to = dfs(g[v][i], h1, h2, v);
            if (res.size() < to.size()) {
                swap(res, to);
            }
            for (set<pair<int, int> >::iterator it = to.begin(); it != to.end(); ++it) {
                res.insert(*it);
            }
        }
    }
    a[v] += res.size();
    //cout << v << " " << h1 << " sz = " << res.size() << endl;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%s", s);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0, -1);
    int ans = -1, cnt;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == ans) {
            ++cnt;
        } else if (a[i] > ans) {
            ans = a[i];
            cnt = 1;
        }
    }
    printf("%d\n%d\n", ans, cnt);
    return 0;
}