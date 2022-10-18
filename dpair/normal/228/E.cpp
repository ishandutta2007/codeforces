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

inline char next_char(){
    char ch = getchar();
    while(ch == '\r' || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

int n, m;
int head[2000010], nxt[5000010], cnt, e[5000010];
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int dep, dfn[2000010], col[2000010], cnt_col, low[2000010];
bool ins[2000010];
stack <int> stk;

void tarjan(int x){
    dfn[x] = low[x] = ++ dep;
    ins[x] = 1;stk.push(x);
    for (register int i = head[x];i;i = nxt[i]){
        if(!dfn[e[i]]){
            tarjan(e[i]);
            low[x] = min(low[x], low[e[i]]);
        }
        if(ins[e[i]]) low[x] = min(low[x], low[e[i]]);
    }
    if(dfn[x] == low[x]){
        int cur;cnt_col ++;
        do{
            cur = stk.top();
            stk.pop();ins[cur] = 0;
            col[cur] = cnt_col;
        }while(cur ^ x);
    }
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= m;i ++){
        int x, y, w;read(x);read(y);read(w);
        if(w) add(x, y), add(y, x), add(x + n, y + n), add(y + n, x + n);
        else add(x, y + n), add(y + n, x), add(x + n, y), add(y, x + n);
    }
    for (register int i = 1;i <= (n << 1);i ++){
        if(!dfn[i]) tarjan(i);
    }
    for (register int i = 1;i <= n;i ++){
        if(col[i] == col[i + n]){
            printf("Impossible\n");
            return 0;
        }
    }
    vector <int> vec;
    for (register int i = 1;i <= n;i ++){
        if(col[i] < col[i + n]) vec.push_back(i);
    }
    fprint(vec.size(), 10);
    for (register int i = 0;i < vec.size();i ++){
        fprint(vec[i], 32);
    }
    putchar(10);
    return 0;
}