/*
    author: DPair
    language: C++11

    hitokoto:
    
*/
#include <cstdio>
#include <cstring>
#define rep(i,s,t) for(int i=s;i<=t;++i)
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
    inline void read(T &x, Args &...args){read(x);read(args...);}
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
//
int n;LL s;
const LL MOD = 1e9 + 7;
LL f[25], ans;
inline LL ksm(LL x, LL y){
    LL ret = 1;
    while(y){
        if(y & 1) ret = ret * x % MOD;
        x  = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
LL fac = 1, inv;
inline LL C(LL x, LL y){
    LL ret = 1;
    for (LL i = x - y + 1;i <= x;++ i) ret = ret * (i % MOD) % MOD;
    return ret * inv % MOD;
}
LL sig = 0;int opt = 1;
void dfs(int x){
    if(sig > s) return ;
    if(x > n){
        ans = (ans + C(s - sig + n - 1, n - 1) * opt) % MOD;
        return ;
    }
    sig += f[x];opt = -opt;dfs(x + 1);
    sig -= f[x];opt = -opt;dfs(x + 1);
}

int main(){
    read(n, s);read(f + 1, f + n + 1);
    rep(i, 1, n) ++ f[i];
    rep(i, 1, n - 1) fac = fac * i % MOD;
    inv = ksm(fac, MOD - 2);dfs(1);print((ans + MOD) % MOD);
}