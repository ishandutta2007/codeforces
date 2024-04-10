/*
    author: DPair
    language: C++11

    description:
    
*/
#pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
#include <cstring>
#include <set>
using std :: set;
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
    inline char nxt_char(){
        char ch;
        for (ch = getcha();ch != '+' && ch != 's';ch = getcha());
        return ch;
    }
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
int n, q;
#define MAXN 100005
LL a[MAXN], b[MAXN];
namespace SegTree{
    LL t[MAXN << 2], tag[MAXN << 2];
    inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}
    inline void update(int rt, int l, int r, LL z){
        t[rt] += z * (r - l + 1);
        tag[rt] += z;
    }
    #define RT rt, l, r
    #define LSON rt << 1, l, mid
    #define RSON rt << 1 | 1, mid + 1, r
    inline void pushdown(int rt, int l, int r){
        if(tag[rt]){
            int mid = (l + r) >> 1;
            update(LSON, tag[rt]);update(RSON, tag[rt]);
            tag[rt] = 0;
        }
    }
    void modify(int rt, int l, int r, int x, int y, LL z){
        if(x <= l && r <= y) return update(RT, z);
        pushdown(RT);
        int mid = (l + r) >> 1;
        if(x <= mid) modify(LSON, x, y, z);
        if(y > mid) modify(RSON, x, y, z);
        pushup(rt);
    }
    void build(int rt, int l, int r){
        if(l == r) {t[rt] = a[l];return ;}
        int mid = (l + r) >> 1;
        build(LSON);build(RSON);
        pushup(rt);
    }
    LL query(int rt, int l, int r, int x, int y){
        if(x <= l && r <= y) return t[rt];
        pushdown(RT);
        int mid = (l + r) >> 1;LL ret = 0;
        if(x <= mid) ret = query(LSON, x, y);
        if(y > mid) ret += query(RSON, x, y);
        return ret;
    }
}
namespace ODT{
    struct NODE{
        int l, r;LL x;
        NODE(int l, int r, LL x) : l(l), r(r), x(x) {}
        inline bool operator < (const NODE &tmp)const {return l < tmp.l;}
    };
    typedef set <NODE> :: iterator IT;
    set <NODE> t;
    inline IT split(int x){
        IT it = t.lower_bound(NODE(x, 0, 0));
        if(it != t.end() && it -> l == x) return it;
        -- it;int val = it -> x, l = it -> l, r = it -> r;
        t.erase(it);t.emplace(l, x - 1, val);
        return t.emplace(x, r, val + b[x] - b[l]).first;
    }
    inline void work(int p, LL x){
        IT L = split(p);LL val = L -> x;int r = L -> r;
        IT it;
        for (it = L;it != t.end();++ it){
            int l = it -> l;LL v = it -> x;
            if(val + x + b[l] - b[p] <= v) break;
            r = it -> r;
            SegTree :: modify(1, 1, n, l, r, val + x + b[l] - b[p] - v);
        }
        t.erase(L, it);
        t.emplace(p, r, val + x);
    }
}
int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(a[i]);
    for (int i = 2;i <= n;++ i) read(b[i]), b[i] += b[i - 1];
    SegTree :: build(1, 1, n);
    int lst = 1;
    for (int i = 2;i <= n;++ i) {
        if(a[i] > a[lst] + b[i] - b[lst]){
            ODT :: t.emplace(lst, i - 1, a[lst]);
            lst = i;
        }
    }
    ODT :: t.emplace(lst, n, a[lst]);
    read(q);
    while(q --){
        char opt = nxt_char();
        int l, r;read(l, r);
        if(opt == '+') ODT :: work(l, r);
        else print(SegTree :: query(1, 1, n, l, r));
    }
}