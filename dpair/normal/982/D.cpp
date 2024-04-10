/*
    author: DPair
    language: C++11

    description:
    
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using std :: map;
using std :: sort;
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
#define INF 0x3f3f3f3f
#define MAXN 100005
int n;
struct DPair{
    int val, pos;
    inline bool operator < (const DPair &tmp) const{return val < tmp.val;}
}a[MAXN];

map <int, int> s;
int ans, num;
int fa[MAXN], sz[MAXN];
int find(int x){return fa[x] == x? x : fa[x] = find(fa[x]);}
int tot;
inline void del(int x){-- tot;if(!(-- s[x])) s.erase(x); }
inline void ins(int x){++ tot;++ s[x];}
inline void unin(int x, int y){
    int xx = find(x), yy = find(y);
    del(sz[xx]);del(sz[yy]);
    fa[xx] = yy;sz[yy] += sz[xx];
    ins(sz[yy]);
}
bool vis[MAXN];
int main(){
    read(n);
    for (int i = 1;i <= n;++ i){
        read(a[i].val);
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;++ i){
        int p = a[i].pos;
        vis[p] = 1;sz[p] = 1;fa[p] = p;
        ins(1);
        if(vis[p - 1]) unin(p, p - 1);
        if(vis[p + 1]) unin(p, p + 1);
        if(s[sz[find(p)]] != tot) continue;
        if(tot > num) num = tot, ans = i;
    }
    print(a[ans].val + 1);
}