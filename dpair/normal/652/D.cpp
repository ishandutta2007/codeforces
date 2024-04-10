/*
    author: DPair
    language: C++11

    description:
    
*/
#include <cstdio>
#include <algorithm>
using std :: sort;
using std :: lower_bound;

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
#define MAXN 200005
int n;
struct inv{
    int u, v, id;
    inline bool operator < (const inv &tmp) const{return u > tmp.u;}
}a[MAXN];
int b[MAXN], ans[MAXN];
int c[MAXN];
inline int lowbit(int x){return x & -x;}
inline void modify(int x){for (;x <= n;x += lowbit(x)) c[x] ++;}
inline int query(int x){int ret = 0;for (;x;x -= lowbit(x)) ret += c[x];return ret;}
int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(a[i].u, a[i].v), b[i] = a[i].v, a[i].id = i;
    sort(a + 1, a + n + 1);sort(b + 1, b + n + 1);
    for (int i = 1;i <= n;++ i){
        a[i].v = lower_bound(b + 1, b + n + 1, a[i].v) - b;
        ans[a[i].id] = query(a[i].v);
        modify(a[i].v);
    }
    for (int i = 1;i <= n;++ i) print(ans[i]);
}