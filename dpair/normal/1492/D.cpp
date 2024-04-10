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
#define MAXN 200005
int a, b, k;
int s[MAXN], t[MAXN];
inline void swap(int &x, int &y){int tmp = x;x = y;y = tmp;}
inline void solve(){
    read(a, b, k);
    if(k == 0){
        print("Yes\n");
        int tmp1 = b, tmp2 = a;
        while(tmp1 --) putcha(49);
        while(tmp2 --) putcha(48);
        putcha(10);
        while(b --) putcha(49);
        while(a --) putcha(48);
        putcha(10);
        return ;
    }
    if(a + b - k <= 1) {print("No\n");return ;}
    if((b == 1 || a == 0) && k) {print("No\n");return ;}
    print("Yes\n");
    int tmp1 = a - 1, tmp2 = b - 2, n = a + b;
    for (int i = 1;i <= n;++ i){
        if(i == 1) putcha(49);
        else if(i == n - k) putcha(49);
        else if(i == n) putcha(48);
        else if(tmp1) tmp1 --, putcha(48);
        else tmp2 --, putcha(49);
    }
    putcha(10);
    tmp1 = a - 1, tmp2 = b - 2;
    for (int i = 1;i <= n;++ i){
        if(i == 1) putcha(49);
        else if(i == n - k) putcha(48);
        else if(i == n) putcha(49);
        else if(tmp1) tmp1 --, putcha(48);
        else tmp2 --, putcha(49);
    }
    putcha(10);
}


int main(){
    // int T;read(T);
    // while(T --)
    solve();
}