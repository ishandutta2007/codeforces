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
int head[205], nxt[405], e[405], cnt;

int u[205], v[205];

int dp[205], ans;

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int ans1, ans2;
void dfs(int x, int pre, int &ret){
    dp[x] = 0;
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x, ret);
        ret = max(ret, dp[x] + dp[e[i]] + 1);
        dp[x] = max(dp[x], dp[e[i]] + 1);
    }
}

int main(){
    read(n);
    for (register int i = 1;i < n;i ++){
        read(u[i]);read(v[i]);
        add(u[i], v[i]);add(v[i], u[i]);
    }
    for (register int i = 1;i < n;i ++){
        ans1 = ans2 = 0;
        dfs(u[i], v[i], ans1);dfs(v[i], u[i], ans2);
        ans = max(ans, ans1 * ans2);
    }
    fprint(ans, 10);
    return 0;
}