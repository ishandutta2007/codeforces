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

LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x = 1;y = 0;
        return a;
    }
    LL ret = exgcd(b, a % b, x, y);
    LL t = x;x = y;y = t - (a / b) * y;
    return ret;
}

LL n, m, vx, vy, x, y;
inline void solve(){
    bool ck1 = 0, ck2 = 0;
    LL p, q;
    if(vx < 0) ck1 = 1, x = n - x;
    if(vy < 0) ck2 = 1, y = m - y;
    x -= y;
    LL g = exgcd(n, m, p, q);
    if(x % g){
        print("-1\n");
        return ;
    }
    p *= x / g;q *= x / g;
    LL N = n, M = m;m /= g;n /= g;
    LL t1 = (p % m + m - 1) % m + 1;
    LL t2 = q - ((p - t1) / m * n);
    p = t1;q = t2;
    LL ansx = N, ansy = M;
    if(!(p & 1)) ansx = 0;
    if(!(q & 1)) ansy = 0;
    if(ck1) ansx = N - ansx;
    if(ck2) ansy = M - ansy;
    print(ansx, ansy);
}

int main(){
    read(n, m, x, y, vx, vy);
    if(!vx){
        if(x == 0 || x == n){
            if(vy > 0) print(x, m);
            else print(x, 0);
        }
        else print("-1\n");
        return 0;
    }
    if(!vy){
        if(y == 0 || y == m){
            if(vx > 0) print(n, y);
            else print(0, y);
        }
        else print("-1\n");
        return 0;
    }
    solve();
}