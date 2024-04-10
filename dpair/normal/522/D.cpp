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
#include <algorithm>
using std :: sort;
using std :: unique;
using std :: lower_bound;
int n, m;
#define MAXN 500005
struct Quest{
    int l, r, id;
    inline bool operator < (const Quest &tmp) const{return r < tmp.r;}
}q[MAXN];
int b[MAXN];
int lst[MAXN];
int a[MAXN];
int ret[MAXN];

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
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
int t[MAXN << 2];
void build(int rt, int l, int r){
    t[rt] = 0x3f3f3f3f;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
}
void modify(int rt, int l, int r, int x, int y){
    chmin(t[rt], y);
    if(l == r) return ;
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y);
    else modify(RSON, x, y);
}
int query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1, ans = 0x3f3f3f3f;
    if(x <= mid) ans = query(LSON, x, y);
    if(y > mid) chmin(ans, query(RSON, x, y));
    return ans;
}

int main(){
    read(n, m);
    for (int i = 1;i <= n;++ i) read(a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    int tot = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1;i <= n;++ i) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    for (int i = 1;i <= m;++ i) {
        read(q[i].l, q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int it = 0;
    build(1, 1, n);
    for (int i = 1;i <= m;++ i){
        while(it < q[i].r){
            ++ it;
            if(lst[a[it]]) modify(1, 1, n, lst[a[it]], it - lst[a[it]]);
            lst[a[it]] = it;
        }
        ret[q[i].id] = query(1, 1, n, q[i].l, q[i].r);
    }
    for (int i = 1;i <= m;++ i) print(ret[i] == 0x3f3f3f3f? -1 : ret[i]);
}