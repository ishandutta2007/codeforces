/*
    author: DPair
    language: C++11

    description:
    JOJO
*/
#pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
#include <cstring>
#include <bitset>
using std :: bitset;
typedef long long LL;
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
#define MAXN 505
int fa[MAXN];
int find(int x){return fa[x] == x? x : fa[x] = find(fa[x]);}

int n, m;

bitset <505> dd[MAXN][75][2];
const LL INF = 1e18 + 114514;
LL dp[MAXN][2];
LL dfs(int x, bool t){
    if(dd[x][60][t].any()) return INF;
    if(~dp[x][t]) return dp[x][t];
    for (int i = 59;i >= 0;-- i){
        if(dd[x][i][t].any()){
            LL ret = -1;
            for (int j = 1;j <= n;++ j)
                if(dd[x][i][t][j])
                    chmax(ret, dfs(j, t ^ 1));
            ret += (1ll << i);
            return dp[x][t] = ret > 1e18? INF : ret;
        }
    }
    return dp[x][t] = 0;
}

int main(){
    read(n, m);memset(dp, -1, sizeof(dp));
    for (int i = 1;i <= n;++ i) fa[i] = i;
    while(m --){
        int u, v, w;read(u, v, w);
        dd[u][0][w].set(v);
    }
    for (int k = 1;k <= 60;++ k)
        for (int i = 1;i <= n;++ i)
            for (int j = 0;j <= 1;++ j)
                for (int p = 1;p <= n;++ p)
                    if(dd[i][k - 1][j][p])
                        dd[i][k][j] |= dd[p][k - 1][j ^ 1];
    LL ans = dfs(1, 0);
    print(ans > 1e18? -1 : ans);
}