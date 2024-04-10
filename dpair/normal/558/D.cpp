/*
    author: DPair
    language: C++11

    description:
    
*/
#include <cstdio>
#include <cstring>
#include <set>
using std :: set;
#define rep(i,s,t) for(int i=s;i<=t;++i)
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
struct NODE{
    LL l, r;
    int val;
    NODE(LL l, LL r, int val) : l(l), r(r), val(val){}
    inline bool operator < (const NODE &tmp) const{return l < tmp.l;}
};
struct Inter{
    LL l, r;
    Inter(){}
    Inter(LL l, LL r) : l(l), r(r){}
    inline Inter operator + (const Inter &b) const{return Inter(mx(l, b.l), mn(r, b.r));}
    inline void operator += (const Inter &b){chmax(l, b.l);chmin(r, b.r);}
    inline bool empty(){return l > r;}
}lay[55];
int h, q;
set <NODE> t;
typedef set <NODE> :: iterator IT;
inline IT split(LL x){
    if(x > lay[h].r) return t.end();
    IT it = t.lower_bound(NODE(x, 0, 0));
    if(it != t.end() && it -> l == x) return it;
    -- it;
    LL l = it -> l, r = it -> r;int val = it -> val;
    t.erase(it);t.emplace(NODE(l, x - 1, val));
    return t.emplace(NODE(x, r, val)).first;
}
inline void assign(LL l, LL r){
    IT R = split(r + 1), L = split(l);
    t.erase(L, R);
    t.emplace(NODE(l, r, 0));
}

int main(){
    read(h, q);
    rep(i, 1, h) lay[i] = Inter(1ll << (i - 1), (1ll << i) - 1);
    t.emplace(NODE(1ll << (h - 1), (1ll << h) - 1, 1));
    while(q --){
        LL l, r;int p, x;read(p, l, r, x);
        Inter inv = Inter(l, r);
        inv += lay[p];
        if(inv.empty()){
            if(x) return put("Game cheated!"), 0;
            continue;
        }
        l = inv.l, r = inv.r;
        if(!x) assign(l << (h - p), ((r + 1) << (h - p)) - 1);
        else {
            if(lay[h].l <= (l << (h - p)) - 1) assign(lay[h].l, (l << (h - p)) - 1);
            if(((r + 1) << (h - p)) <= lay[h].r) assign(((r + 1) << (h - p)), lay[h].r);
        }
    }
    LL ans = 0;
    for (auto it : t){
        if(it.val){
            if(it.r ^ it.l) return put("Data not sufficient!"), 0;
            if(ans) return put("Data not sufficient!"), 0;
            ans = it.l;
        }
    }
    if(!ans) put("Game cheated!");
    else print(ans);
}