#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int N = 2e5 + 1;
const int mod = 998244353;
int h[N], fa[N], w[N], f[N * 4], l[N], r[N], b[N][2], sz[N], ff[N * 4];
vector<int>g[N];
int n, m, tot;
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = 1ll * x * z % mod;
        x = 1ll * x * x %mod, y /= 2;
    }
    return z;
}
void dfs(int x){
    for (auto u:g[x])
        if (u != fa[x]) {
            fa[u] = x;
            dfs(u);
            if (b[u][1] + 1> b[x][1])
                b[x][0] = u, b[x][1] = b[u][1] + 1;
        }
}
void dfs1(int x) {
    l[x] = ++tot;
    if (b[x][0]) {
        h[b[x][0]] = h[x];
        dfs1(b[x][0]);
    }
    for (auto u:g[x])
        if (u != fa[x] && u != b[x][0]) {
            h[u] = u, dfs1(u);
        }
    r[x] = tot;
    sz[x] = r[x] - l[x] + 1;
}
void ins(int l, int r, int s, int ll, int v, int *f) {
    (f[s] += v) %= mod;
    if (l == r) {
        return;
    }
    if ((l + r) / 2 >= ll) ins(l, (l + r) / 2, s + s, ll, v, f);
    else
        ins((l+ r) / 2 + 1, r, s + s + 1, ll, v, f);
}
int get(int l, int r, int s ,int ll,int rr, int*f){
    if (rr < l || r < ll) return 0;
    if (ll <= l && r <= rr) return f[s];
    return (get(l,(l + r)/ 2, s + s, ll, rr, f) + get((l +r)/ 2 + 1, r, s + s + 1,ll, rr, f)) % mod;
}
int main() {
   // freopen("input","r",stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1;i < n ; i++)
    {
        int x ,y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    h[1] = 1;
    dfs1(1);
    int all = 0;
    int invn = calc(n, mod- 2);
    while (m --) {
        int x, y, z;
        scanf("%d %d", &x, &y);
        if (x == 1) {
            scanf("%d", &z);
            int v = 1ll * invn * sz[y] % mod * z % mod;
            (all += v) %= mod;
            ins(1, n, 1, l[y], v, f);
            (w[y] += z) %= mod;
            v = 1ll * invn * (n - sz[b[y][0]]) % mod * z % mod;
            ins(1, n, 1, l[y], v, ff);
        } else {
            int ans = all;
            ans = (ans + 1ll * invn * sz[b[y][0]] %mod * w[y] %mod ) % mod;
            while (y) {
                ans = (ans - get(1, n, 1, l[h[y]], l[y], f) + mod) % mod;
                ans = (ans + get(1, n, 1, l[h[y]], l[y], ff)) % mod;
                if (fa[h[y]]) {
                    int z = fa[y = h[y]];
                    ans = (ans - 1ll * invn * (n - sz[b[z][0]]) % mod * w[z] % mod + mod) % mod;
                    ans = (ans + 1ll * invn * (n - sz[y]) % mod * w[z] % mod + mod) % mod;
                }
                y = fa[h[y]];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}