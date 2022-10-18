/*
    author: DPair
    language: C++11

    description:
    
    E.HERO 
*/
#include <cstdio>
#include <cstring>
namespace IO{
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 23, stdin), SS == TT) ? EOF : *SS++)
    char BB[1 << 23], *SS = BB, *TT = BB;
    template <typename T>
    inline void read(T &x){
        x = 0;int fu = 1;
        char c = getcha();
        while(c > 57 || c < 48){
            if(c == 45) fu = -1;
            c = getcha();
        }
        while(c <= 57 && c >= 48){
            x = x * 10 + c - 48;
            c = getcha();
        }
        x *= fu;
    }
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){
        read(x);read(args...);
    }
    char out[1 << 22], *Out = out;
    #define flush() fwrite(out, 1, Out - out, stdout)
    inline void putcha(char x) {*Out++ = x;if(Out - out >= (1 << 22)) flush(), Out = out;}
    template <typename T>
    inline void fprint(T x){
        if(x < 0) putcha(45), x = -x;
        if(x > 9) fprint(x / 10);
        putcha(x % 10 + 48);
    }
    template <typename T>
    inline void print(T x){fprint(x);putcha(10);}
    inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
    inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    template <typename T, typename ...Args>
    inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
    template <typename T>
    inline void sprint(T x){fprint(x);putcha(32);}
    template <typename T, typename ...Args>
    inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;
namespace MyMinMax{
    template <typename T>
    inline T mn(T x, T y) {return x < y ? x : y;}
    template <typename T>
    inline T mx(T x, T y) {return x > y ? x : y;}
    template <typename T>
    inline void chmin(T &x, T y) {(x > y) && (x = y);}
    template <typename T>
    inline void chmax(T &x, T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
#define MAXN 500005

int fa[MAXN], a[MAXN], id[MAXN];
int n;

int sz[MAXN], son[MAXN], dep[MAXN];

int head[MAXN], e[MAXN], cnt, nxt[MAXN];

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

void dfs1(int x, int pre){
    dep[x] = dep[pre] + 1;sz[x] = 1;
    for (int i = head[x];i;i = nxt[i]){
        id[e[i]] = (id[x] ^ (1 << a[e[i]]));
        dfs1(e[i], x);sz[x] += sz[e[i]];
        if(sz[son[x]] < sz[e[i]]) son[x] = e[i];
    }
}

int ans[MAXN];

int dp[1 << 22 | 5];

void del(int x){
    dp[id[x]] = -0x3f3f3f3f;
    for (int i = head[x];i;i = nxt[i]) del(e[i]);
}

void bruh(int x, int d, int &ret){
    for (int i = 0;i < 22;++ i) chmax(ret, dep[x] + dp[id[x] ^ (1 << i)] - (d << 1));
    chmax(ret, dep[x] + dp[id[x]] - (d << 1));
    for (int i = head[x];i;i = nxt[i]) bruh(e[i], d, ret);
}

void force(int x){
    chmax(dp[id[x]], dep[x]);
    for (int i = head[x];i;i = nxt[i]) force(e[i]);
}

void solve(int x){
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == son[x]) continue;
        solve(e[i]);del(e[i]);
        chmax(ans[x], ans[e[i]]);
    }
    if(son[x]) solve(son[x]), chmax(ans[x], ans[son[x]]);
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == son[x]) continue;
        bruh(e[i], dep[x], ans[x]);force(e[i]);
    }
    for (int i = 0;i < 22;++ i) chmax(ans[x], dp[id[x] ^ (1 << i)] - dep[x]);
    chmax(ans[x], dp[id[x]] - dep[x]);
    chmax(dp[id[x]], dep[x]);
}

int main(){
    read(n);
    for (int i = 2;i <= n;++ i){
        read(fa[i]);add(fa[i], i);
        a[i] = getcha() - 97;
    }
    dfs1(1, 0);
    memset(dp, 128, sizeof(dp));
    solve(1);
    for (int i = 1;i <= n;++ i) sprint(ans[i]);
    putcha(10);
}