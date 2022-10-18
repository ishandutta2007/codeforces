//
#include <cstdio>
#include <cstring>
// #include <algorithm>
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
#define INFll 0x3f3f3f3f3f3f3f3fll
//
#define MAXN 300005
int n, m;
LL id[MAXN], od[MAXN], c[MAXN];
int a[MAXN], b[MAXN];
int ca, cb;

struct EDGE{
    int u, v;
    LL w;
    EDGE(){}
    EDGE(int u, int v, LL w) : u(u), v(v), w(w) {}
};
EDGE ans[MAXN];
int tp = 0;
// inline bool cmp(int &x, int &y){return c[x] > c[y];}
int main(){
    read(n, m);
    rep(i, 1, m){
        int u, v, w;read(u, v, w);
        id[v] += w;od[u] += w;
    }

    rep(i, 1, n){
        c[i] = id[i] - od[i];
        if(c[i] < 0) a[++ ca] = i;
        if(c[i] > 0) b[++ cb] = i;
    }
    // std :: sort(a + 1, a + ca + 1, cmp);
    // std :: sort(b + 1, b + cb + 1, cmp);

    int it = 1;
    rep(i, 1, ca){
        while(it <= cb && c[a[i]] < 0){
            LL t = mn(-c[a[i]], c[b[it]]);
            c[a[i]] += t;c[b[it]] -= t;
            ans[++ tp] = EDGE(a[i], b[it], t);
            if(!c[b[it]]) ++ it;
        }
    }
    print(tp);
    rep(i, 1, tp) print(ans[i].u, ans[i].v, ans[i].w);
}