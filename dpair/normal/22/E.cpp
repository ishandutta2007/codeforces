#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef pair <int, int> pi;

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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

int nxt[MAXN], n, d[MAXN], fa[MAXN], dd[MAXN];
vector <int> in[MAXN];
int out[MAXN];
bool vis[MAXN];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int dfn[MAXN], low[MAXN], dep, col[MAXN], num[MAXN], tot;
stack <int> stk;bool ins[MAXN];

void tarjan(int x){
    dfn[x] = low[x] = ++ dep;
    stk.push(x);ins[x] = 1;
    if(!dfn[nxt[x]]){
        tarjan(nxt[x]);
        low[x] = min(low[x], low[nxt[x]]);
    }
    else if(ins[nxt[x]]) low[x] = min(low[x], low[nxt[x]]);
    if(dfn[x] == low[x]){
        int cur;tot ++;
        do{
            cur = stk.top();stk.pop();ins[cur] = 0;
            col[cur] = tot;
            num[tot] = cur;
        }while(cur ^ x);
    }
}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(nxt[i]), fa[i] = i;
    for (register int i = 1;i <= n;i ++){
        int u = find(i), v = find(nxt[i]);
        if(u ^ v) fa[u] = v;
    }
    int ans = 0;
    for (register int i = 1;i <= n;i ++){
        if(!dfn[i]) tarjan(i);
    }
    if(tot == 1) return printf("0\n"), 0;
    for (register int i = 1;i <= n;i ++) if(col[nxt[i]] ^ col[i]) d[col[nxt[i]]] ++, dd[col[i]] ++;
    for (register int i = 1;i <= tot;i ++){
        if(!d[i]) in[find(num[i])].push_back(num[i]), ans ++;
        if(!dd[i]) out[find(num[i])] = num[i];
    }
    int root = 0, pre = 0;
    fprint(ans, 10);
    for (register int i = 1;i <= n;i ++){
        int x = find(i);
        if(vis[x]) continue;
        vis[x] = 1;
        if(!pre) root = x;
        else while(!in[x].empty()) fprint(out[pre], 32), fprint(in[x].back(), 10), in[x].pop_back();
        pre = x;
    }
    while(!in[root].empty()) fprint(out[pre], 32), fprint(in[root].back(), 10), in[root].pop_back();
}