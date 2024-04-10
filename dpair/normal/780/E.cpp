/*
    author: DPair
    language: C++11

    description:
    ko no Dio da!
*/
#include <cstdio>
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
#define MAXN 200005

int fa[MAXN];
int find(int x){return x == fa[x]? x : fa[x] = find(fa[x]);}
int n, m, k;
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;

inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}

inline void link(int u, int v){add(u, v), add(v, u);}
int ans[MAXN << 1], tot;

void dfs(int x, int pre){
    ans[++ tot] = x;
    bool ck = 0;
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        ck = 1;dfs(e[i], x);
        ans[++ tot] = x;
    }
}

int main(){
    read(n, m, k);
    for (int i = 1;i <= n;++ i) fa[i] = i;
    while(m --){
        int u, v;read(u, v);
        int x = find(u), y = find(v);
        if(x == y) continue;
        fa[x] = y;link(u, v);
    }
    dfs(1, 0);
    int it = 0;
    for (int i = 1;i <= k;++ i){
        int len = (tot / k);
        if(i <= tot % k) ++ len;
        sprint(len);
        while(len --) sprint(ans[++ it]);
        putcha(10);
    }
}