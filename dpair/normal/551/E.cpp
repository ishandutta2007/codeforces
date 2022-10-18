/*
    author: DPair
    language: C++11

    description:
    
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
const int block = 1000;
#define INF 0x3f3f3f3f
#define MAXN 500005
const int B = MAXN / block + 5;

set <int> mp[B];
int fst[B], lst[B], n, m, tag[B];
int a[MAXN], bel[MAXN];
inline void rebuild(int x){
    if(tag[x] > 1e9) return ;
    mp[x].clear();
    for (int i = fst[x];i <= lst[x];++ i){
        if(tag[x] + a[i] > 1e9) a[i] = INF;
        else a[i] = tag[x] + a[i], mp[x].insert(a[i]);
    }
    tag[x] = 0;
}
inline int query(int x){
    int l = -1;
    for (int i = 1;i <= bel[n];++ i){
        if(tag[i] > 1e9) continue;
        if(mp[i].find(x - tag[i]) != mp[i].end()){
            for (int j = fst[i];j <= lst[i];++ j){
                if(a[j] + tag[i] == x){
                    l = j;
                    break;
                }
            }
            break;
        }
    }
    if(l == -1) return -1;
    for (int i = bel[n];i >= 1;-- i){
        if(tag[i] > 1e9) continue;
        if(mp[i].find(x - tag[i]) != mp[i].end()){
            for (int j = lst[i];j >= fst[i];-- j){
                if(a[j] + tag[i] == x){
                    return j - l;
                }
            }
        }
    }
}
int main(){
    read(n, m);
    for (int i = 1;i <= n;++ i){
        read(a[i]);bel[i] = (i - 1) / block + 1;
    }
    for (int i = 1;i <= bel[n];++ i){
        fst[i] = lst[i - 1] + 1;
        lst[i] = mn(n, i * block);
        rebuild(i);
    }
    while(m --){
        int opt, l, r, x;read(opt);
        if(opt == 1){
            read(l, r, x);
            int L = bel[l], R = bel[r];
            if(L == R){
                for (int i = l;i <= r;++ i) a[i] = (a[i] + x) > 1e9? INF : a[i] + x;
                rebuild(L);
            }
            else{
                for (int i = l;i <= lst[L];++ i) a[i] = (a[i] + x) > 1e9? INF : a[i] + x;
                for (int i = fst[R];i <= r;++ i) a[i] = (a[i] + x) > 1e9? INF : a[i] + x;
                rebuild(L);rebuild(R);
                for (int i = L + 1;i < R;++ i) tag[i] = (tag[i] + x) > 1e9? INF : tag[i] + x;
            }
        }
        else read(x), print(query(x));
    }
}