#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn = 200005;
const int P = 1000000007;
vector <int> G[maxn];
int dfn[maxn], dc, fa[maxn][20], d[maxn], res[maxn];
long long a[maxn], gfa[maxn][20];
long long gcd(long long x, long long y){
    return y == 0 ? x : gcd(y, x % y);
}
void dfs(int u, int f){
	dfn[++ dc] = u;
    d[u] = d[f] + 1;
    fa[u][0] = f, gfa[u][0] = gcd(a[u], a[f]);
    for (int i = 1; i <= 17; ++ i){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        gfa[u][i] = gcd(gfa[u][i - 1], gfa[fa[u][i - 1]][i - 1]);
    }
    for (int i = 0; i < G[u].size(); ++ i){
        int v = G[u][i];
        if (v != f)
            dfs(v, u);
    }
}
long long read(){
    long long c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
signed main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    for (int i = 1; i < n; ++ i){
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int id = 1; id <= n; ++ id){
    	int i = dfn[id];
        if (a[i] == 0){
            res[i] = res[fa[i][0]];
            continue;
        }
        int u = i;
        long long g = a[i];
        while (true){
            int c = 1;
            for (int j = 17; j >= 0; -- j)
                if (fa[u][j] && gfa[u][j] % g == 0)
                    u = fa[u][j], c += 1 << j;
            res[i] = (res[i] + g % P * c) % P;
            u = fa[u][0], g = gcd(g, a[u]);
            if (u == 0 || g == 1){
                res[i] = (res[i] + d[u]) % P;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans = (ans + res[i]) % P;
    cout << ans << endl;
}