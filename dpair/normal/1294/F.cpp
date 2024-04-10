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
int n;

int head[200005], nxt[400005], e[400005], cnt;

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int rt, dep[200005], deep[200005];
int ans[200005], ret;
int ans1, ans2, ans3, ans4;
void dfs(int x, int pre){
    if(dep[x] > dep[rt]) rt = x;
    for (register int i = head[x];i;i = nxt[i]){
        if(pre == e[i]) continue;
        dep[e[i]] = dep[x] + 1;
        dfs(e[i], x);
    }
}
bitset <200005> on_link;
void link(int x, int pre){
    // printf("x = %d, pre = %d\n", x, pre);
    if(x == ans2) on_link[x] = 1;
    for (register int i = head[x];i;i = nxt[i]){
        if(pre == e[i]) continue;
        link(e[i], x);
        if(on_link[e[i]]) on_link[x] = 1;
    }
}

int getans(int x, int pre){
    int res = x;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        int num = getans(e[i], x);
        if(on_link[e[i]]) continue;
        if(dep[res] < dep[num]) res = num;
    }
    if(on_link[x]){
        if(dep[res] - dep[x] > ans4 && res != ans1 && res != ans2){
            ans4 = dep[res] - dep[x];
            ans3 = res;
        }
    }
    return res;
}

int main(){
    read(n);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    rt = 0;dep[1] = 0;
    dfs(1, 0);
    ans1 = rt;dep[rt] = 0;
    dfs(ans1, 0);
    ans2 = rt;
    ret += dep[rt];ans4 = -0x3f3f3f3f;dep[0] = -1;
    // printf("%d %d %d\n", ans1, ans2, ans3);
    link(ans1, 0);
    getans(ans1, 0);
    fprint(ret + ans4, 10);
    printf("%d %d %d\n", ans1, ans2, ans3);
}