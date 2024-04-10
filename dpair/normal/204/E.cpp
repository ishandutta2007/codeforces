//
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,l,r) for(int i=(l);i<(r);++i)
#define PER(i,l,r) for(int i=(l);i>(r);--i)
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
    template <typename T = int>
    inline T read(){
        T x = 0;int fu = 1;
        char c = getcha();
        while(c > 57 || c < 48){
            if(c == 45) fu = -1;
            c = getcha();
        }
        while(c <= 57 && c >= 48){
            x = x * 10 + c - 48;
            c = getcha();
        }
        x *= fu;return x;
    }
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
#define INFll 0x3f3f3f3f3f3f3f3fll
//
#define MAXN 100005

int n, k, N;
char BUF[MAXN << 1], *p[MAXN];
int t[MAXN][26], tot;
inline void ins(char *p){
    int rt = 0;
    for (char *it = p;*it != '\0';++ it){
        if(!t[rt][*it - 97]) t[rt][*it - 97] = ++ tot;
        rt = t[rt][*it - 97];
    }
}
int len[MAXN << 1], link[MAXN << 1];
int nxt[MAXN << 1][26];
int sz, lst[MAXN << 1];
inline int extend(int c, int pre){
    int x = sz ++;
    len[x] = len[pre] + 1;
    int it = pre;
    while(~it && !nxt[it][c]){
        nxt[it][c] = x;
        it = link[it];
    }
    if(!~it) link[x] = 0;
    else{
        int t = nxt[it][c];
        if(len[it] + 1 == len[t]) link[x] = t;
        else{
            int y = sz ++;
            len[y] = len[it] + 1;
            memcpy(nxt[y], nxt[t], sizeof(nxt[y]));
            link[y] = link[t];
            while(~it && nxt[it][c] == t){
                nxt[it][c] = y;
                it = link[it];
            }
            link[t] = link[x] = y;
        }
    }
    return x;
}
int buf[MAXN];
inline void layer(){
    link[0] = -1;++ sz;
    int *hd = buf, *ed = buf + 1;
    while(hd != ed){
        int x = *hd ++;
        rep(i, 0, 25) if(t[x][i]){
            *ed ++ = t[x][i];
            lst[t[x][i]] = extend(i, lst[x]);
        }
    }
}
int head[MAXN << 1], e[MAXN << 1], nt[MAXN << 1], cnt;
inline void add(int u, int v){
    nt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
int s[MAXN << 1], tp[MAXN << 1], siz[MAXN << 1], son[MAXN << 1], dep[MAXN << 1], dfn[MAXN << 1], _tot;
void dfs1(int x){
    siz[x] = 1;
    for (int i = head[x];i;i = nt[i]){
        dep[e[i]] = dep[x] + 1;
        dfs1(e[i]);
        siz[x] += siz[e[i]];
        if(siz[son[x]] < siz[e[i]]) son[x] = e[i];
    }
}
void dfs2(int x, int tt){
    tp[x] = tt;dfn[x] = ++ _tot;
    if(son[x]) dfs2(son[x], tt);
    for (int i = head[x];i;i = nt[i]){
        if(e[i] == son[x]) continue;
        dfs2(e[i], e[i]);
    }
}
inline int LCA(int x, int y){
    while(tp[x] ^ tp[y]){
        if(dep[tp[x]] < dep[tp[y]]) std :: swap(x, y);
        x = link[tp[x]];
    }
    if(dep[x] > dep[y]) return y;
    else return x;
}
void dfs(int x){for (int i = head[x];i;i = nt[i]) dfs(e[i]), s[x] += s[e[i]];}
inline void build(){
    rep(i, 1, sz - 1) add(link[i], i);
    dep[0] = 1;dfs1(0);dfs2(0, 0);
}
int tmp[MAXN], ttp;
int fa[MAXN << 1][21], c[MAXN], a[MAXN << 1];
inline void prework(){
    rep(i, 0, sz - 1) ++ c[len[i]];
    rep(i, 1, N) c[i] += c[i - 1];
    rep(i, 0, sz - 1) a[-- c[len[i]]] = i;

    rep(i, 1, sz - 1){
        int x = a[i];fa[x][0] = link[x];
        rep(j, 1, 20) fa[x][j] = fa[fa[x][j - 1]][j - 1];
    }
}
inline bool cmp(int x, int y){return dfn[x] < dfn[y];}
inline void init(){
    layer();build();
    rep(i, 1, n){
        int rt = 0;ttp = 0;
        for (char *it = p[i];*it != '\0';++ it){
            rt = nxt[rt][*it - 97];
            tmp[++ ttp] = rt;++ s[rt];
        }
        std :: sort(tmp + 1, tmp + ttp + 1, cmp);
        REP(j, 1, ttp) -- s[LCA(tmp[j], tmp[j + 1])];
    }
    dfs(0);prework();
}
inline int work(int x){
    per(i, 20, 0) if(s[fa[x][i]] < k) x = fa[x][i];
    if(s[x] < k) x = link[x];
    return len[x];
}
inline void solve(){
    init();
    rep(i, 1, n){
        int rt = 0;LL ans = 0;
        for (char *it = p[i];*it != '\0';++ it){
            rt = nxt[rt][*it - 97];
            ans += work(rt);
        }
        sprint(ans);
    }
    putcha(10);
}
int main(){
    read(n, k);
    char *it = BUF;
    rep(i, 1, n){
        p[i] = ++ it;pread(it);
        ins(p[i]);chmax(N, (int)strlen(p[i]));
    }
    solve();
}
/*
 k 
DPair
SAM

 endpos...





*/