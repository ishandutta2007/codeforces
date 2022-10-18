/*
    author: DPair
    language: C++11

    hitokoto:
    
*/
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
// #pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
#include <cstring>
#include <iostream>
using std :: swap;
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
    #define BUFSIZ 1 << 18
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, BUFSIZ, stdin), SS == TT) ? EOF : *SS++)
    char BB[BUFSIZ], *SS = BB, *TT = BB;
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
    char out[BUFSIZ], *Out = out;
    #define flush() fwrite(out, 1, Out - out, stdout)
    inline void putcha(char x) {*Out++ = x;if(Out - out >= (BUFSIZ)) flush(), Out = out;}
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
#define MAXN 100005
const int block = 320;
const int B = MAXN / block + 5;
int n, m;
int a[MAXN];//
int bel[MAXN], fst[B], lst[B], tag[B];//tag 
bool sk[B];//
int fa[MAXN];
//
inline void rebuild(int x){
    //rebuild
    //
    //
    sk[x] = 1;
    rep(i, fst[x], lst[x]){
        if(bel[a[i]] ^ x) fa[i] = i;
        else fa[i] = fa[a[i]], sk[x] = 0;
    }
}
inline void modify(int l, int r, int x){
    int L = bel[l], R = bel[r];
    if(L == R){
        rep(i, l, r) a[i] = mx(a[i] - x, 1);
        if(!sk[L]) rebuild(L);
    }
    else{
        rep(i, l, lst[L]) a[i] = mx(a[i] - x, 1);
        if(!sk[L]) rebuild(L);
        rep(i, fst[R], r) a[i] = mx(a[i] - x, 1);
        if(!sk[R]) rebuild(R);
        rep(i, L + 1, R - 1){
            if(!sk[i]){
                rep(j, fst[i], lst[i]) a[j] = mx(a[j] - x, 1);
                rebuild(i);
            }
            else tag[i] = (tag[i] + x >= n? n : tag[i] + x);
        }
    }
}
inline void swap(int &x, int &y){int tmp = x;x = y;y = tmp;}
inline int query(int x, int y){
    while((bel[x] ^ bel[y]) || (bel[x] == bel[y] && ((!sk[bel[x]] && (fa[x] ^ fa[y])) || (sk[bel[x]] && (a[x] ^ a[y]))))){
        if(bel[x] == bel[y]){
            if(sk[bel[x]]) x = mx(a[x] - tag[bel[x]], 1), y = mx(a[y] - tag[bel[y]], 1);
            else x = a[fa[x]], y = a[fa[y]];
        }
        else {
            if(bel[x] < bel[y]) swap(x, y);
            if(!sk[bel[x]]) x = a[fa[x]];
            else x = mx(a[x] - tag[bel[x]], 1);
        }
    }
    while(x ^ y){
        if(x > y) x = mx(a[x] - tag[bel[x]], 1);
        else y = mx(a[y] - tag[bel[y]], 1);
    }
    return x;
}
inline void init(){
    rep(i, 1, n) bel[i] = (i - 1) / block + 1;
    rep(i, 1, bel[n]){
        fst[i] = lst[i - 1] + 1;
        lst[i] = mn(n, i * block);
    }
    bel[1] = 0;fst[1] = 2;
    rep(i, 1, bel[n]) rebuild(i);
}
int main(){
    read(n, m);read(a + 2, a + n + 1);
    init();
    while(m --){
        int opt, l, r, x;read(opt, l, r);
        if(opt == 1) read(x), modify(l, r, x);
        else print(query(l, r));
    }
}