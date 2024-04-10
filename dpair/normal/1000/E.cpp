#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}

int n, m;

int head[1000005], nxt[4000005], e[4000005], cnt, tot;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

int dfn[1000005], low[1000005], dep, sig, col[1000005], cnt_col;
stack <int> stk;
void tarjan(int x, int pre){
    dfn[x] = low[x] = ++ dep;
    stk.push(x);
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        if(!dfn[e[i]]){
            tarjan(e[i], x);
            low[x] = min(low[x], low[e[i]]);
        }
        else low[x] = min(low[x], dfn[e[i]]);
    }
    if(dfn[x] == low[x]){
        int cur;cnt_col ++;
        do{
            cur = stk.top();stk.pop();
            col[cur] = cnt_col;
        }while(cur ^ x);
    }
}

int dp[1000005], deep;

void dfs(int x, int pre){
    if(dp[x] > dp[deep]) deep = x;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dp[e[i]] = dp[x] + 1;
        dfs(e[i], x);
    }
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= m;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    for (register int i = 1;i <= n;i ++){
        if(!dfn[i]) tarjan(i, 0);
    }
    for (register int i = 1;i <= n;i ++){
        for (register int j = head[i];j;j = nxt[j]){
            if(col[i] == col[e[j]]) continue;
            add(col[i] + n, col[e[j]] + n);
        }
    }
    dfs(1 + n, 0);
    dp[deep] = 0;
    dfs(deep, 0);
    fprint(dp[deep], 10);
}