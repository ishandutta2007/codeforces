#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

#define MAXN 100005
int a[MAXN], prime[2000005], tot, n, m, head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
bool b[2000005];
int p[2000005];
inline void init(){
    for (register int i = 2;i <= 2000000;i ++){
        if(!b[i]) prime[++ tot] = i, p[i] = tot;
        for (register int j = 1;j <= tot && 1ll * i * prime[j] <= 2000000;j ++){
            b[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int ans[MAXN], res[MAXN], dep[MAXN];
typedef pair <int, int> pi;
set <pi> s[2000005];
vector <int> vec[MAXN];
void dfs(int x, int pre){
    dep[x] = dep[pre] + 1;
    int tmp = a[x];
    vec[x].clear();
    for (register int i = 1;i <= tot && 1ll * prime[i] * prime[i] <= tmp;i ++){
        if(tmp % prime[i] == 0){
            vec[x].push_back(i);
            while(tmp % prime[i] == 0) tmp /= prime[i];
        }
    }
    if(tmp > 1) vec[x].push_back(p[tmp]);
    for (register int i = 0;i < vec[x].size();i ++){
        if(s[vec[x][i]].empty()) continue;
        auto it = s[vec[x][i]].begin();
        if(res[x] > (*it).first) {
            res[x] = (*it).first;
            ans[x] = (*it).second;
        }
    }
    for (register int i = 0;i < vec[x].size();i ++){
        s[vec[x][i]].insert(make_pair(-dep[x], x));
    }
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);
    }
    for (register int i = 0;i < vec[x].size();i ++){
        s[vec[x][i]].erase(make_pair(-dep[x], x));
    }
}

inline void rebuild(){
    memset(ans, -1, sizeof(ans));
    memset(res, 0, sizeof(res));
    dfs(1, 0);
}

int main(){
    read(n);read(m);
    init();
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i < n;i ++){
        int u, v;read(u);read(v);
        add(u, v);add(v, u);
    }
    rebuild();
    while(m --){
        int opt, x, y;read(opt);read(x);
        if(opt == 1) fprint(ans[x], 10);
        else read(y), a[x] = y, rebuild();
    }
}