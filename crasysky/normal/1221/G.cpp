#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
void FMT_or(int *a, int n){
    for (int l = 2; l <= n; l <<= 1){
        int m = l >> 1;
        for (int *p = a; p != a + n; p += l)
            for (int k = 0; k < m; ++ k)
                p[k + m] += p[k];
    }
}
const int maxn = 102;
vector <int> G[maxn];
int col[maxn];
bool vis[maxn];
bool dfs(int u){
    vis[u] = true;
    bool bin = true;
    for (int i = 0; i < G[u].size(); ++ i){
        int v = G[u][i];
        if (vis[v] && col[u] == col[v])
            bin = false;
        if (! vis[v]){
            col[v] = col[u] ^ 1;
            bin = dfs(v) && bin;
        }
    }
    return bin;
}
int outs[2000006], outt[2000006], outst[2000006], f[2000006];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), m = read();
    for (int i = 1; i <= m; ++ i){
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    long long ans = 1LL << n;
    int com = 0, bin = 1;
    for (int i = 1; i <= n; ++ i)
        if (! vis[i])
            ++ com, col[i] = 1, bin = dfs(i) && bin;
    ans -= 1LL << com; //no 1
    if (bin)
        ans += 1LL << com; //no 0 2
    int sin = 0;
    for (int i = 1; i <= n; ++ i)
        if (G[i].size() == 0)
            ++ sin;
    ans += 2 * (1LL << sin); //no 0 1    no 1 2
    if (sin == n)
        ans -= 1LL << n;//no 0 1 2
    //no 0    no 2
    m = n / 2;
    for (int s = 0; s < 1 << m; ++ s)
        for (int i = 1; i <= m; ++ i)
            if (s & (1 << i - 1))
                for (int j = 0; j < G[i].size(); ++ j){
                    int v = G[i][j];
                    if (v <= m)
                        outs[s] |= 1 << v - 1;
                    else
                        outst[s] |= 1 << v - m - 1;
                }
    for (int s = 0; s < 1 << n - m; ++ s)
        for (int i = 1; i <= n - m; ++ i)
            if (s & (1 << i - 1))
                for (int j = 0; j < G[m + i].size(); ++ j){
                    int v = G[m + i][j];
                    if (v > m)
                        outt[s] |= 1 << v - m - 1;
                }
    for (int s = 0; s < 1 << n - m; ++ s)
        if ((outt[s] & s) == 0)
            f[s] = 1;
    FMT_or(f, 1 << n - m);
    for (int s = 0; s < 1 << m; ++ s)
        if ((outs[s] & s) == 0)
            ans -= 2 * f[(1 << n - m) - 1 - outst[s]];
    cout << ans << endl;
}