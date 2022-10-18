//
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
template <typename T>
inline void swap(T &x, T &y){T tmp = x;x = y;y = tmp;}
typedef long long LL;
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
//
#define MAXN 100005
#define MAXM 200005
int n, Q;
char s[MAXN], w[MAXM];

int lc[MAXN << 6], rc[MAXN << 6], tot;
void ins(int &rt, int l, int r, int x){
    if(!rt) rt = ++ tot;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    if(x <= mid) ins(lc[rt], l, mid, x);
    else ins(rc[rt], mid + 1, r, x);
}
int merge(int rt, int RT){
    if(!rt || !RT) return rt | RT;
    int o = ++ tot;
    lc[o] = merge(lc[rt], lc[RT]);
    rc[o] = merge(rc[rt], rc[RT]);
    return o;
}
bool query(int rt, int l, int r, int x, int y){
    if(!rt) return 0;
    if(x <= l && r <= y) return 1;
    int mid = (l + r) >> 1;
    if(x <= mid && query(lc[rt], l, mid, x, y)) return 1;
    if(y > mid && query(rc[rt], mid + 1, r, x, y)) return 1;
    return 0;
}
struct SAM{//index 0, double size
    int len[MAXN << 1], link[MAXN << 1];
    int nxt[MAXN << 1][26];
    int sz, lst;
    SAM(){
        len[0] = 0;link[0] = -1;
        ++ sz;lst = 0;
    }
    int root[MAXN << 1];
    inline void extend(int c){
        int x = sz ++;
        len[x] = len[lst] + 1;
        int it = lst;
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
        lst = x;
    }
    int c[MAXN], a[MAXN << 1];
    inline void init(){
        rep(i, 0, sz - 1) ++ c[len[i]];
        rep(i, 1, n) c[i] += c[i - 1];
        rep(i, 0, sz - 1) a[-- c[len[i]]] = i;
        int it = 0;
        rep(i, 1, n){
            it = nxt[it][s[i] - 97];
            ins(root[it], 1, n, i);
        }
        per(i, sz - 1, 1) {
            int x = a[i];
            root[link[x]] = merge(root[link[x]], root[x]);
        }
    }
    char ch[MAXN], *tp;
    bool dfs(char *p, int l, int r, int it){
        if(*p == '\0') {
            rep(i, 0, 25){
                if(nxt[it][i]){
                    int x = nxt[it][i];
                    if(query(root[x], 1, n, l + p - w, r)){
                        *++ tp = i + 97;*++ tp = '\0';
                        print(ch + 1);
                        return 1;
                    }
                }
            }
            return 0;
        }
        if(nxt[it][*p - 97]){
            *++ tp = *p;
            if(dfs(p + 1, l, r, nxt[it][*p - 97])) return 1;
            -- tp;
        }
        rep(i, *p - 96, 25){
            if(nxt[it][i]){
                int x = nxt[it][i];
                if(query(root[x], 1, n, l + p - w, r)){
                    *++ tp = i + 97;*++ tp = '\0';
                    print(ch + 1);
                    return 1;
                }
            }
        }
        return 0;
    }
}t;

inline void init(){
    read(s + 1);read(Q);
    n = strlen(s + 1);
    rep(i, 1, n) t.extend(s[i] - 97);
    t.init();
}

int main(){
    init();
    while(Q --){
        int l, r;read(l, r);read(w);
        t.tp = t.ch;
        if(!t.dfs(w, l, r, 0)) print("-1");
    }
}