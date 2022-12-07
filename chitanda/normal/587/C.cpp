#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, m, Q;
int u, v, x, ans[15];
int tot, to[maxn * 2], ne[maxn * 2], he[maxn], dp[maxn], fa[maxn][17];
struct sta{
    int x[11];
}unit, p[maxn][17], q, tmp;

inline sta merge(const sta a, const sta b){
    memset(unit.x, 0, sizeof(unit.x));
    for(int i = 1, j = 1, k = 1; k <= 10 && (a.x[i] || b.x[j]); k++)
        if (!a.x[i] || (a.x[i] > b.x[j] && b.x[j])) unit.x[k] = b.x[j++];
        else unit.x[k] = a.x[i++];
    return unit;
}

void link(int u, int v){
    to[++tot] = v, ne[tot] = he[u], he[u] = tot;
}

void dfs(int t){
    dp[t] = dp[fa[t][0]] + 1;
    for(int i = 1; i < 17; i++){
        fa[t][i] = fa[fa[t][i - 1]][i - 1];
        p[t][i] = merge(p[t][i - 1], p[fa[t][i - 1]][i - 1]);
    }
    
    for(int i = he[t]; i; i = ne[i])
        if (to[i] != fa[t][0]){
            fa[to[i]][0] = t;
            dfs(to[i]);
        }
}

void lca(int u, int v){
    if (dp[u] > dp[v]) swap(u, v);
    for(int i = 16; i >= 0; i--)
        if (dp[fa[v][i]] >= dp[u]){
            q = merge(q, p[v][i]);
            v = fa[v][i];
        }
    if (u == v){
        q = merge(q, p[v][0]);
        return;
    }
    for(int i = 16; i >= 0; i--)
        if (fa[u][i] != fa[v][i]){
            q = merge(q, p[u][i]);
            q = merge(q, p[v][i]);
            u = fa[u][i];
            v = fa[v][i];
        }
    q = merge(q, p[v][0]);
    q = merge(q, p[u][0]);
    q = merge(q, p[fa[u][0]][0]);
}

int main(){
    scanf("%d%d%d", &n, &m, &Q);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        link(u, v), link(v, u);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", &u);
        tmp.x[1] = i;
        p[u][0] = merge(p[u][0], tmp);
    }
    dfs(1);
    for(int i = 1; i <= Q; i++){
        memset(q.x, 0, sizeof(q.x));
        scanf("%d%d%d", &u, &v, &x);
        lca(u, v);
        int ans = 0;
        for(int j = 1; j <= x; j++) if (q.x[j]) ans++;
        printf("%d", ans);
        for(int j = 1; j <= ans; j++) printf(" %d", q.x[j]);
        printf("\n");
    }
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/