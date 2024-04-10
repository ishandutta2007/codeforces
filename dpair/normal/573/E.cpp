/*
    author: DPair
    language: C++11

    description:
    ,
*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
#include <cstring>
#include <random>
using std :: mt19937;
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
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 22, stdin), SS == TT) ? EOF : *SS++)
    char BB[1 << 22], *SS = BB, *TT = BB;
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
    template <typename ...Args>
    inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
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
typedef long long LL;
#define INF 0x3f3f3f3f3f3f3f3f
int n;
#define MAXN 100005
mt19937 rnd(11451488);
namespace FHQTreap{
    int root;
    LL t[MAXN], tag[MAXN];
    int lc[MAXN], rc[MAXN], val[MAXN], sz[MAXN], tot;
    inline void pushup(int rt){sz[rt] = sz[lc[rt]] + sz[rc[rt]] + 1;}
    inline int NewNode(LL x){
        t[++ tot] = x;val[tot] = rnd();
        sz[tot] = 1;return tot;
    }
    inline void update(int rt, LL val){
        t[rt] += val;
        tag[rt] += val;
    }
    inline void pushdown(int rt){
        if(tag[rt]){
            if(lc[rt]) update(lc[rt], tag[rt]);
            if(rc[rt]) update(rc[rt], tag[rt]);
            tag[rt] = 0;
        }
    }
    void split(int rt, LL key, int &x, int &y, int &base){
        if(!rt){x = y = 0;++ base;return ;}
        pushdown(rt);
        if(key * (sz[lc[rt]] + 1 + base) <= t[rt]) {x = rt;base += sz[lc[rt]] + 1;split(rc[rt], key, rc[rt], y, base);}
        else {y = rt;split(lc[rt], key, x, lc[rt], base);}
        pushup(rt);
    }
    int merge(int x, int y){
        if(!x || !y) return x | y;
        if(val[x] < val[y]) {
            pushdown(x);rc[x] = merge(rc[x], y);
            pushup(x);return x;
        }
        else{
            pushdown(y);lc[y] = merge(x, lc[y]);
            pushup(y);return y;
        }
    }
    int tp = 0;
    LL b[MAXN];
    
    void dfs(int rt){
        pushdown(rt);
        if(lc[rt]) dfs(lc[rt]);
        b[++ tp] = t[rt];
        if(rc[rt]) dfs(rc[rt]);
    }
    inline void grab(){
        tp = 0;
        dfs(root);
    }
}
using namespace FHQTreap;
LL a[MAXN];
int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(a[i]);
    for (int i = 1;i <= n;++ i){
        int l, r, pos = 0;
        split(root, a[i], l, r, pos);
        if(r) update(r, a[i]);
        root = merge(l, merge(NewNode(a[i] * pos), r));
    }
    grab();
    LL ans = 0;
    for (int i = 1;i <= n;++ i) chmax(ans, b[i] += b[i - 1]);
    print(ans);
}