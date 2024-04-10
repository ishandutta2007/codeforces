#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
const int N = 2e6 + 1;
const int mod = 1e9 + 7;
int v[N], st[N], st1[N], en[N], en1[N], d[N], f[N], deep[N], w[N];
int n, m, tot;
vector<int>g[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m ; i ++) {
        int l = tot + 1;
        int x =i;
        while (x) {
            v[++tot] = x % 10;
            x /= 10;
        }
        en[i] = l;
        st[i] = tot;
        for (int j = l ; j< tot; j ++)
            g[j].push_back(j + 1),g[j+1].push_back(j);
        l = tot + 1;
        x =i;
        while (x) {
            v[++tot] = x % 10;
            x /= 10;
        }
        en1[i] = l;
        st1[i] = tot;
        for (int j = l ; j< tot; j ++)
            g[j].push_back(j + 1),g[j+1].push_back(j);
    }
    for (int i = 1; i <= m; i ++){
        int x ,y;
        scanf("%d %d", &x, &y);
        g[x + tot].push_back(st[i]);
        g[en[i]].push_back(y + tot);
        g[y + tot].push_back(st1[i]);
        g[en1[i]].push_back(x + tot);
    }
    for (int i = 1; i <= tot + n ; i ++)
        sort(g[i].begin(), g[i].end(), [](int x, int y){return v[x] < v[y];});
    int l = 0, r = 1;
    d[1] = tot + 1;
    deep[tot + 1] = 1;
    while (l < r) {
        if (deep[d[l]] != deep[d[l+ 1]]){
            sort(d + l + 1, d + r + 1, [](int x, int y) {
                return w[x] < w[y];
            });
            int tot = 0;
            int last = w[d[l+ 1]];
            w[d[l+1]] = ++tot;
            for (int i= l + 2; i <= r; i ++) {
                if (w[d[i]] != last) ++tot;
                last =w[d[i]];
                w[d[i]] = tot;
            }
        }
        for (auto u:g[d[++l]])
            if (u > tot) {
                if (deep[u]) continue;
                deep[u] = deep[d[l]];
                f[u] = f[d[l]];
                for (auto vv:g[u])
                    if (!deep[vv]|(deep[vv] == deep[d[l]] +1 && w[vv] > w[d[l]] * 10 + v[vv])){
                        if (!deep[vv])d[++r]=vv;
                        deep[vv] = deep[d[l]] + 1;
                        w[vv] = w[d[l]] * 10  +v[vv];
                        f[vv] = (1ll * f[d[l]] * 10 + v[vv]) %mod;
                    }
            } else {
                if (!deep[u]|| (deep[u] == deep[d[l]] + 1 && w[u] > w[d[l]] * 10 + v[u])) {
                    if (!deep[u])d[++r] = u;
                    deep[u] = deep[d[l]] + 1;
                    w[u] = w[d[l]] * 10 + v[u];
                    f[u] = (1ll * f[d[l]] * 10 + v[u]) % mod;
                }
            }
    }
    for (int i = 2; i <= n ; i++)
        printf("%d\n", f[i + tot]);
    return 0;
}