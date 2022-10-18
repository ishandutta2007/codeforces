/*
    author: DPair
    language: C++11

    description:
     NOI 
*/
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
inline int jdz(int x){return x > 0? x : -x;}
#define MAXN 100005
int n, m;
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
        int l, r, val;
        NODE(int l, int r, int val) : l(l), r(r), val(val) {}
        inline bool operator < (const NODE &tmp) const{return l < tmp.l;}
    };
    set <NODE> t;
    typedef set <NODE> :: iterator IT;
    inline IT split(int x){
        IT it = t.lower_bound(NODE(x, 0, 0));
        if(it != t.end() && it -> l == x) return it;
        -- it;
        int l = it -> l, r = it -> r, val = it -> val;
        t.erase(it);t.emplace(NODE(l, x - 1, val));
        return t.emplace(NODE(x, r, val)).first;
    }
    inline void assign(int l, int r, int x){
        IT R = split(r + 1), L = split(l);
        for (IT it = L;it != R;++ it) SegTree :: modify(1, 1, n, it -> l, it -> r, jdz(it -> val - x));
        t.erase(L, R);t.emplace(NODE(l, r, x));
    }
}

#define INF 0x3f3f3f3f
int main(){
    read(n, m);
    for (int i = 1;i <= n;++ i) ODT :: t.emplace(ODT :: NODE(i, i, i));
    while(m --){
        int opt, l, r;read(opt, l, r);
        if(opt == 1){
            int x;read(x);
            ODT :: assign(l, r, x);
        }
        else print(SegTree :: query(1, 1, n, l, r));
    }
}