/*
    author: DPair
    language: C++11

    description:
    
*/
#pragma GCC optimize(2, 3, "Ofast")
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
typedef __int128_t LL;
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
LL p, a, b, c;
inline void solve(){
    read(p, a, b, c);
    LL l = 0, r = 1e18, ans = (LL)1e30;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(p <= mid * a) chmin(ans, mid * a - p), r = mid - 1;
        else l = mid + 1;
    }
    l = 0, r = 1e18;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(p <= mid * b) chmin(ans, mid * b - p), r = mid - 1;
        else l = mid + 1;
    }
    l = 0, r = 1e18;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(p <= mid * c) chmin(ans, mid * c - p), r = mid - 1;
        else l = mid + 1;
    }
    print(ans);
}


int main(){
    int T;read(T);
    while(T --)
        solve();
    
}