#include <cstdio>
#include <cstring>
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define per(i,t,s) for(int i=t;i>=s;--i)
#define elif else if
#define gup(x) return puts(#x), 0
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
namespace IO{
    #define DPAIRSIZ 1 << 18
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS++)
    char BB[DPAIRSIZ], *SS = BB, *TT = BB;
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
    template <typename T>
    inline void read(T *bg, T *ed){while(bg != ed) read(*bg ++);}
    inline void read(char &ch){
        ch = getcha();
        while(ch <= 32) ch = getcha();
    }
    inline void read(char *s){
        char ch = getcha();
        while(ch <= 32) ch = getcha();
        while(ch > 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    inline void sread(char *s){
        char ch = getcha();
        while(ch < 32) ch = getcha();
        while(ch >= 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    inline void pread(char *&s){
        char ch = getcha();
        while(ch <= 32) ch = getcha();
        while(ch > 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    inline void spread(char *&s){
        char ch = getcha();
        while(ch < 32) ch = getcha();
        while(ch >= 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){read(x);read(args...);}
    char out[DPAIRSIZ], *Out = out;
    #define flush() fwrite(out, 1, Out - out, stdout)
    inline void putcha(char x) {*Out++ = x;if(Out - out >= (DPAIRSIZ)) flush(), Out = out;}
    template <typename T>
    inline void fprint(T x){
        if(x < 0) putcha(45), x = -x;
        if(x > 9) fprint(x / 10);
        putcha(x % 10 + 48);
    }
    template <typename T>
    inline void print(T x){fprint(x);putcha(10);}
    inline void print(char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    inline void put(char *ch){while(*ch != '\0') putcha(*(ch ++));}
    inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
    template <typename T, typename ...Args>
    inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
    template <typename ...Args>
    inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
    template <typename ...Args>
    inline void print(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
    template <typename T, typename ...Args>
    inline void printl(T x, Args ...args){fprint(x);putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
    template <typename T>
    inline void sprint(T x){fprint(x);putcha(32);}
    template <typename T, typename ...Args>
    inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
    template <typename T>
    inline void sprint(T *bg, T *ed){while(bg != ed) sprint(*bg ++);}
    template <typename T>
    inline void print(T *bg, T *ed){while(bg != ed) sprint(*bg ++);putcha(10);}
    template <typename T>
    inline void printl(T *bg, T *ed){while(bg != ed) print(*bg ++);}
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
#define INF 0x3f3f3f3f
//

#define MAXN 200005
#define MAXM 800005
int head[MAXN], dep[MAXN];
int cnt, nxt[MAXM << 1], e[MAXM << 1], val[MAXM << 1];
inline void add(int u, int v, int w){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
    val[cnt] = w;
    nxt[++ cnt] = head[v];
    head[v] = cnt;
    e[cnt] = u;
    val[cnt] = 0;
}
int s, t;
inline void init(){
    memset(head, -1, (t + 1) * sizeof(int));
    cnt = -1;
}
int q[MAXN], hd, ed;
inline bool bfs(){
    memset(dep, 0, (t + 1) * sizeof(int));
    dep[s] = 1;hd = 1;ed = 0;q[++ ed] = s;
    while(hd <= ed){
        int x = q[hd ++];
        for (register int i = head[x];~i;i = nxt[i]){
            if(!dep[e[i]] && val[i]){
                dep[e[i]] = dep[x] + 1;
                q[++ ed] = e[i];
            }
        }
    }
    return dep[t];
}
int cur[MAXN];
int dfs(int x, int flow){
    if(x == t) return flow;
    int res = flow;
    for (register int i = cur[x];~i;i = nxt[i]){
        cur[x] = i;
        if(val[i] > 0 && dep[x] + 1 == dep[e[i]]){
            int num = dfs(e[i], mn(res, val[i]));
            val[i] -= num;val[i ^ 1] += num;
            res -= num;
            if(!num) dep[e[i]] = 0;
            if(!res) return flow;
        }
    }
    return flow - res;
}
inline int dinic(){
    int ans = 0;
    while(bfs()){
        memcpy(cur, head, (t + 1) * sizeof(int));
        while(int num = dfs(s, 2147483647)) ans += num;
    }
    return ans;
}
int n, m, limit;

inline void work(){
    read(n, m);limit = (m + 1) >> 1;
    s = 0;t = n + m + 1;init();
    rep(i, 1, n) add(i + m, t, limit);
    rep(i, 1, m){
        add(s, i, 1);
        int k;read(k);
        while(k --){
            int x;read(x);
            add(i, x + m, 1);
        }
    }
    if(dinic() == m) {
        print("YES");
        rep(i, 1, m){
            // print("i =", i);
            for (int j = head[i];~j;j = nxt[j]){
                // sprint(e[j] - m);
                if(e[j] == s || val[j]) continue;
                sprint(e[j] - m);break;
            }
            // putcha(10);
        }
        putcha(10);
    }
    else print("NO");
}
int main(){
    int T;read(T);
    while(T --) work();
}