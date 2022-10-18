/*
    author: DPair
    language: C++11

    hitokoto:
    wryyyyyyyyyyyy!
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
    #define DPAIRSIZ 1 << 18
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS++)
    char BB[DPAIRSIZ], *SS = BB, *TT = BB;
    template <typename T>
    inline void nread(T &x){
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
    inline void nread(T *bg, T *ed){while(bg != ed) nread(*(bg ++));}
    template <typename T, typename ...Args>
    inline void nread(T &x, Args &...args){nread(x);nread(args...);}
    template <typename T>
    inline void read(T &x){
        x = 0;
        char c = getcha();
        while(c > 57 || c < 48) c = getcha();
        while(c <= 57 && c >= 48){
            x = x * 10 + c - 48;
            c = getcha();
        }
    }
    template <typename T>
    inline void read(T *bg, T *ed){while(bg != ed) read(*(bg ++));}
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
typedef unsigned ui;
ui t[135];
int n, p;ui q;
ui f[135];
ui gcd(ui x, ui y){return !y? x : gcd(y, x % y);}
inline void init(){
    rep(i, 0, p){
        t[i] = 1;f[i] = n - i + 1;
        ui cur = i;
        rep(j, 1, i){
            ui g = gcd(f[j], cur);
            f[j] /= g;cur /= g;
            t[i] *= f[j];
        }
    }
}

int main(){
    read(n, p, q);chmin(p, n - 1);
    init();
    ui x = 1, ans = 0;
    rep(j, 1, q){
        x = 1;ui res = 0;
        rep(i, 0, p){
            res += x * t[i];
            x *= j;
        }
        ans ^= res * j;
    }
    print(ans);
}