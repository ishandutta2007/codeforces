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
#define INF 0x3f3f3f3f
#define MAXN 100005
int ans[MAXN];
int tot, n, m;
struct NODE{
    int x, y;LL val;
    NODE(){}
    NODE(int x, int y, LL val) : x(x), y(y), val(val) {}
    inline int num(){return ((x & 1) << 1) | (y & 1);}
}e[MAXN << 2], g[MAXN << 2];

LL BIT[4][1005];
inline int lowbit(int x){return x & -x;}
inline void modify(LL c[], int x, LL y){for (;x <= n;x += lowbit(x)) c[x] ^= y;}
inline LL query(LL c[], int x){LL ret = 0;for (;x;x -= lowbit(x)) ret ^= c[x];return ret;}
void CDQ(int l, int r){
    if(l == r) return ;
    int mid = (l + r) >> 1;
    CDQ(l, mid);CDQ(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(e[i].x <= e[j].x){
            if(e[i].val >= 0) modify(BIT[e[i].num()], e[i].y, e[i].val);
            g[k ++] = e[i ++];
        }
        else{
            if(e[j].val < 0) ans[-e[j].val] ^= query(BIT[e[j].num()], e[j].y);
            g[k ++] = e[j ++];
        }
    }
    while(j <= r){
        if(e[j].val < 0) ans[-e[j].val] ^= query(BIT[e[j].num()], e[j].y);
        g[k ++] = e[j ++];
    }
    for (int t = l;t < i;++ t) if(e[t].val >= 0) modify(BIT[e[t].num()], e[t].y, e[t].val);
    while(i <= mid) g[k ++] = e[i ++];
    for (int t = l;t <= r;++ t) e[t] = g[t];
}
bool b[MAXN];
int main(){
    read(n, m);
    for (int i = 1;i <= m;++ i){
        int opt, x1, y1, x2, y2;LL w;
        read(opt, x1, y1, x2, y2);
        if(opt == 2){
            read(w);
            e[++ tot] = NODE(x1, y1, w);
            e[++ tot] = NODE(x1, y2 + 1, w);
            e[++ tot] = NODE(x2 + 1, y1, w);
            e[++ tot] = NODE(x2 + 1, y2 + 1, w);
        }
        else{
            b[i] = 1;
            e[++ tot] = NODE(x1 - 1, y1 - 1, -i);
            e[++ tot] = NODE(x1 - 1, y2, -i);
            e[++ tot] = NODE(x2, y1 - 1, -i);
            e[++ tot] = NODE(x2, y2, -i);
        }
    }
    memset(ans, 0, sizeof(ans));
    CDQ(1, tot);
    for (int i = 1;i <= m;++ i)
        if(b[i]) print(ans[i]);
}