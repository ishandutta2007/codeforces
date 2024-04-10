/*
    author: DPair
    language: C++11

    description:
    It's raining somewhere else.
*/

#include <cstdio>
#include <vector>
using std :: vector;
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

int n;
int a[200005];
typedef long long LL;
LL ans = 0;
int c[200005];

inline int lowbit(int x){return x & (-x);}
inline void modify(int x){for (;x <= n;x += lowbit(x)) c[x] ++;}
inline int query(int x){int ret = 0;for (;x;x -= lowbit(x)) ret += c[x];return ret;}

vector <int> v[200005];

int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(a[i]), chmin(a[i], n);
    for (int i = 1;i <= n;++ i){
        if(i + 1 > a[i]) continue;
        v[i].push_back(-i);v[a[i]].push_back(i);
    }
    for (int i = 1;i <= n;++ i){
        modify(a[i]);
        while(!v[i].empty()){
            int x = v[i].back();v[i].pop_back();
            if(x < 0) x = -x, ans -= i - query(x - 1);
            else ans += i - query(x - 1);
        }
    }
    print(ans);
}