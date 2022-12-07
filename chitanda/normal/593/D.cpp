#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

const int maxn = 200100;
int n, x, y, tot, m, ty;
ll p;
int FA[maxn], u[maxn], v[maxn], to[maxn * 2], ne[maxn * 2], he[maxn], fa[maxn][18], dp[maxn];
ll co[maxn * 2], cost[maxn], c[maxn];

void link(int x, int y, ll w){
    to[++tot] = y, ne[tot] = he[x], he[x] = tot, co[tot] = w;
}

void dfs(int t, int tfa){
    for(int i = 1; i < 18; i++) fa[t][i] = fa[fa[t][i - 1]][i - 1];
    FA[t] = tfa;
    dp[t] = dp[fa[t][0]] + 1;
    for(int i = he[t]; i; i = ne[i])
        if (to[i] != fa[t][0]){
            fa[to[i]][0] = t;
            cost[to[i]] = co[i];
            dfs(to[i], co[i] == 1 ? tfa : to[i]);
        }
}

int lca(int x, int y){
    if (dp[x] > dp[y]) swap(x, y);
    for(int i = 17; i >= 0; i--)
        if (dp[fa[y][i]] >= dp[x]) y = fa[y][i];
    if (x == y) return x;
    for(int i = 17; i >= 0; i--)
        if (fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    return fa[x][0];
}

void find(int x, int li){
    if (dp[FA[x]] <= li || !p) return;
    if (cost[FA[x]] == 1){
        find(FA[x], li);
        FA[x] = FA[FA[x]];
    }else{
        p /= cost[FA[x]];
        find(fa[FA[x]][0], li);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++){
        scanf("%d%d%I64d", u + i, v + i, c + i);
        link(u[i], v[i], c[i]);
        link(v[i], u[i], c[i]);
    }
    dfs(1, 1);

    for(int i = 1; i <= m; i++){
        scanf("%d", &ty);
        if (ty == 1){
            scanf("%d%d%I64d", &x, &y, &p);
            int f = lca(x, y);
            find(x, dp[f]);
            find(y, dp[f]);
            printf("%I64d\n", p);
        }else{
            scanf("%d%I64d", &x, &p);
            if (dp[u[x]] > dp[v[x]]) x = u[x]; else x = v[x];
            cost[x] = p;
            if (p == 1) FA[x] = FA[fa[x][0]];
        }
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