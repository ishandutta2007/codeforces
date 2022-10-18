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
    template <typename T>
    inline void read(T *bg, T *ed){while(bg != ed) read(*(bg ++));}
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){read(x);read(args...);}
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
int n, q, k;
#define MAXN 150005
struct Dat{
    int a[6], c[6];
    Dat(){memset(a, 0, sizeof(a));memset(c, 0, sizeof(c));}
    inline void clear(){memset(a, 0, sizeof(a));memset(c, 0, sizeof(c));}
}t[MAXN << 2];
inline Dat merge(Dat x, Dat y){
    Dat ret = y;
    rep(i, 0, k - 1){
        bool ck = 1;
        rep(j, 0, k - 1){
            if(x.a[i] == ret.a[j]) {
                ret.c[j] += x.c[i];
                ck = 0;break;
            }
        }
        if(!ck) continue;
        int pos = k;ret.c[k] = x.c[i];
        rep(j, 0, k - 1)
            if(ret.c[j] < ret.c[pos]) pos = j;
        int tt = ret.c[pos];
        if(pos < k) ret.a[pos] = x.a[i], ret.c[pos] = x.c[i];
        rep(j, 0, k - 1) ret.c[j] -= tt;
    }
    return ret;
} 
int tag[MAXN << 2], a[MAXN];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
inline void pushup(int rt){t[rt] = merge(t[rt << 1], t[rt << 1 | 1]);}
void build(int rt, int l, int r){
    if(l == r){
        t[rt].a[0] = a[l];
        t[rt].c[0] = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}
inline void update(int rt, int l, int r, int z){
    tag[rt] = z;t[rt].clear();
    t[rt].a[0] = z;t[rt].c[0] = r - l + 1;
}
inline void pushdown(int rt, int l, int r){
    if(tag[rt]){
        int mid = (l + r) >> 1;
        update(LSON, tag[rt]);update(RSON, tag[rt]);
        tag[rt] = 0;
    }
}
void modify(int rt, int l, int r, int x, int y, int z){
    if(x <= l && r <= y) return update(rt, l, r, z);
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    pushup(rt);
}
Dat query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return merge(query(LSON, x, y), query(RSON, x, y));
    if(x <= mid) return query(LSON, x, y);
    else return query(RSON, x, y);
}
int main(){
    read(n, q, k);k = 100 / k;
    read(a + 1, a + n + 1);build(1, 1, n);
    while(q --){
        int opt, l, r, x;read(opt, l, r);
        if(opt == 1){read(x);modify(1, 1, n, l, r, x);}
        else{
            Dat x = query(1, 1, n, l, r);
            int tot = 0, stk[5];
            rep(i, 0, k - 1)
                if(x.a[i]) stk[tot ++] = x.a[i];
            sprint(tot);
            print(stk, stk + tot);
        }
    }
    
}