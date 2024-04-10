/*
    author: DPair
    language: C++11

    description:
    
*/
#include <cstdio>
#include <cstring>
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
#define MAXN 200005
int n, m, k;
struct POINT{
    int dat[5];
    inline void input(){read(dat, dat + k);}
}a[MAXN];

struct NODE{
    int f[1 << 5];
    NODE(){memset(f, 128, sizeof(f));}
    inline NODE operator + (const NODE &b) const{
        NODE ret;for (int i = 0;i < (1 << k);++ i) ret.f[i] = mx(f[i], b.f[i]);
        return ret;
    }
    inline void set(POINT x){
        for (int i = 0;i < (1 << k);++ i){
            f[i] = 0;
            for (int j = 0;j < k;++ j)
                if((i >> j) & 1) f[i] += x.dat[j];
                else f[i] -= x.dat[j];
        }
    }
}t[MAXN << 2];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
void build(int rt, int l, int r){
    if(l == r) return t[rt].set(a[l]);
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);pushup(rt);
}
void modify(int rt, int l, int r, int x, POINT z){
    if(l == r) return t[rt].set(z);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, z);
    else modify(RSON, x, z);
    pushup(rt);
}
NODE query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return query(LSON, x, y) + query(RSON, x, y);
    if(x <= mid) return query(LSON, x, y);
    else return query(RSON, x, y);
}
int main(){
    read(n, k);
    for (int i = 1;i <= n;++ i) a[i].input();
    build(1, 1, n);read(m);
    int mod = (1 << k) - 1;
    while(m --){
        int opt;read(opt);
        if(opt == 1){
            int x;read(x);
            POINT z;z.input();
            modify(1, 1, n, x, z);
        }
        else {
            int l, r;read(l, r);
            NODE res = query(1, 1, n, l, r);
            int ans = -INF;
            for (int i = 0;i < (1 << k);++ i) chmax(ans, res.f[i] + res.f[mod ^ i]);
            print(ans);
        }
    }
}