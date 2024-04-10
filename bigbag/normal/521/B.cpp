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

const int max_n = 111111, mod = 1000000009;
const int dx[] = {-1, 0, 1};

int n, x[max_n], y[max_n], pw[max_n], cnt[max_n];
set<int> g[max_n], rg[max_n];
map<pair<int, int>, int> m;
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (1LL * pw[i - 1] * n) % mod;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        m[make_pair(x[i], y[i])] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (m.count(make_pair(x[i] + dx[j], y[i] + 1))) {
                g[i].insert(m[make_pair(x[i] + dx[j], y[i] + 1)]);
                rg[m[make_pair(x[i] + dx[j], y[i] + 1)]].insert(i);
                //cout << "rg[" << m[make_pair(x[i] + dx[j], y[i] + 1)] << "] insert " << i << endl;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (rg[i].size() > 1) {
            for (set<int>::iterator it = rg[i].begin(); it != rg[i].end(); ++it) {
                ++cnt[*it];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == cnt[i]) {
            q.insert(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        if (i % 2 == 0) {
            x = *q.rbegin();
        } else {
            x = *q.begin();
        }
        q.erase(x);
        //cout << x << endl;
        ans += (1LL * x * pw[n - 1 - i] % mod);
        ans %= mod;
        for (set<int>::iterator it = g[x].begin(); it != g[x].end(); ++it) {
            int y = *it;
            rg[y].erase(x);
            //if (rg[y].size() == 0) cout << "FAIL\n";
            if (rg[y].size() == 1) {
                int v = *rg[y].begin();
                --cnt[v];
                if (cnt[v] + 1 == g[v].size()) {
                    q.erase(v);
                }
            }
        }
        int sz = rg[x].size();
        for (set<int>::iterator it = rg[x].begin(); it != rg[x].end(); ++it) {
            int y = *it;
            //cout << "                 erase " << y << " " << x << endl;
            g[y].erase(x);
            if (sz > 1) {
                --cnt[y];
            }
            //cout << "                 " << y << " " << g[y].size() << " " << cnt[y] << endl;
            if (g[y].size() == cnt[y]) {
                q.insert(y);
            }
        }
        //cout << ans << endl;
    }
    printf("%d\n", ans);
    return 0;
}