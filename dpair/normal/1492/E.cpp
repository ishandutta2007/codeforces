/*
    author: DPair
    language: C++11

    description:
    
*/
#pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
#include <vector>
using std :: vector;
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
#define MAXN 250005
int n, m;
#include <cstdlib>
inline void swap(int &x, int &y){int tmp = x;x = y;y = tmp;}
int stk[MAXN], tp;
vector <int> a[MAXN];

inline int diff(int x, int y){
    tp = 0;
    for (int i = 1;i <= m;++ i)
        if(a[x][i] ^ a[y][i]) 
            stk[++ tp] = i;
    return tp;
}
int cnt[MAXN];
inline void judge(int p2, int p3, int pp){// p1  1 p2  2 
    for (int i = 1;i <= n;++ i) cnt[i] = 0;
    for (int j = 1;j <= m;++ j){
        if(j == p3) continue;
        int p = a[1][j];
        if(j == p2) p = a[pp][j];
        for (int i = 1;i <= n;++ i){
            if(p ^ a[i][j]) cnt[i] ++;
        }
    }
    int p = -1;
    for (int i = 1;i <= n;++ i) {
        if(cnt[i] > 2) return ;
        if(cnt[i] == 2){
            if(p == -1) p = a[i][p3];
            else if(p ^ a[i][p3]) return ;
        }
    }
    print("Yes\n");
    for (int i = 1;i <= m;++ i) {
        if(i == p2) sprint(a[pp][i]);
        else if(i == p3) sprint(p == -1? a[1][i] : p);
        else sprint(a[1][i]);
    }
    putcha(10);
    exit(0);
}
inline void check(int p1, int p2, int pp){
    for (int i = 1;i <= n;++ i) cnt[i] = 0;
    for (int j = 1;j <= m;++ j){
        int p = a[1][j];
        if(j == p1 || j == p2) p = a[pp][j];
        for (int i = 1;i <= n;++ i){
            if(p ^ a[i][j]) cnt[i] ++;
        }
    }
    for (int i = 1;i <= n;++ i) 
        if(cnt[i] > 2) {
            return ;
        }
    print("Yes\n");
    for (int i = 1;i <= m;++ i) sprint((i == p1 || i == p2)? a[pp][i] : a[1][i]);
    putcha(10);
    exit(0);
}

inline void solve(){
    read(n, m);
    for (int i = 1;i <= n;++ i) a[i].push_back(0);
    for (int i = 1;i <= n;++ i){
        for (int j = 1;j <= m;++ j){
            int x;read(x);
            a[i].push_back(x);
        }
    }
    for (int i = 2;i <= n;++ i){
        int res = diff(1, i);
        if(res > 4) {return print("No\n");}
        if(res == 3){
            judge(stk[2], stk[3], i);
            judge(stk[3], stk[1], i);
            judge(stk[3], stk[2], i);
            judge(stk[1], stk[3], i);
            judge(stk[2], stk[1], i);
            judge(stk[1], stk[2], i);
            return print("No\n");
        }
        if(res == 4){
            check(stk[1], stk[2], i);
            check(stk[2], stk[3], i);
            check(stk[1], stk[3], i);
            check(stk[1], stk[4], i);
            check(stk[2], stk[4], i);
            check(stk[3], stk[4], i);
            return print("No\n");
        }
    }
    print("Yes\n");
    for (int i = 1;i <= m;++ i) sprint(a[1][i]);
    putcha(10);
}


int main(){
    // int T;read(T);
    // while(T --)
    solve();
}