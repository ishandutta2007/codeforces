/*
    author: DPair
    language: C++11

    hitokoto:

*/
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
    inline void read(T *bg, T *ed){while(bg != ed) read(*(bg ++));}
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
    inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
    inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    template <typename T, typename ...Args>
    inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
    template <typename ...Args>
    inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
    template <typename T, typename ...Args>
    inline void printl(T x, Args ...args){fprint(x);putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
    template <typename T>
    inline void sprint(T x){fprint(x);putcha(32);}
    template <typename T, typename ...Args>
    inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
    template <typename T>
    inline void sprint(T *bg, T *ed){while(bg != ed) sprint(*(bg ++));}
    template <typename T>
    inline void print(T *bg, T *ed){while(bg != ed) sprint(*(bg ++));putcha(10);}
    template <typename T>
    inline void printl(T *bg, T *ed){while(bg != ed) print(*(bg ++));}
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
#define INF 0x3f3f3f3f
//
int n;
#define MAXN 100005
int head[MAXN], e[MAXN << 1], cnt, nxt[MAXN << 1];
LL val[MAXN << 1];
inline void add(int u, int v, LL w){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
    val[cnt] = w;
}
inline void link(int u, int v, LL w){add(u, v, w);add(v, u, w);}
LL f[MAXN], dep[MAXN];
void dfs(int x, int pre){
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        chmax(f[e[i]], dep[e[i]] = dep[x] + val[i]);
        dfs(e[i], x);
    }
}
bool vis[MAXN];
int fa[MAXN], t[MAXN], ans;
int find(int x){return fa[x] == x? x : fa[x] = find(fa[x]);}
inline void unin(int u, int v){
    int x = find(u), y = find(v);
    if(t[x] < t[y]) x ^= y ^= x ^= y;
    fa[y] = x;t[x] += t[y];
    chmax(ans, t[x]);
}
struct NODE{
    int u;LL w;
    inline bool operator < (const NODE &tmp) const{return w > tmp.w;}
}a[MAXN];
#include <algorithm>
using std :: sort;
signed main(){
    read(n);
    rep(i, 2, n){
        int u, v, w;read(u, v, w);
        link(u, v, w);
    }
    dfs(1, 0);int root = 1;
    rep(i, 1, n) if(dep[i] > dep[root]) root = i;
    dep[root] = 0;dfs(root, 0);
    rep(i, 1, n) if(dep[i] > dep[root]) root = i;
    dep[root] = 0;dfs(root, 0);
    rep(i, 1, n) a[i].u = i, a[i].w = f[i];
    sort(a + 1, a + n + 1);
    int q;read(q);
    while(q --){
        LL l;read(l);
        int r = 0;
        memset(vis, 0, sizeof(vis));
        rep(i, 1, n) fa[i] = i, t[i] = 1;
        ans = 1;
        rep(i, 1, n){
            while(r < n && a[i].w - a[r + 1].w <= l) {
                int x = a[++ r].u;
                for (int j = head[x];j;j = nxt[j])
                    if(vis[e[j]]) unin(x, e[j]);
                vis[x] = 1;
            }
            int x = a[i].u;
            -- t[find(x)];
            vis[x] = 0;
        }
        print(ans);
    }
}