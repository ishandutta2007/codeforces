/*
    author: DPair
    language: C++11

    description:
    ,
*/
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
int n;
#define MAXN 100005
namespace BIT{
    LL c[MAXN];
    inline int lowbit(int x){return x & -x;}
    inline void modify(int x, int y){for (;x <= n;x += lowbit(x)) c[x] += y;}
    inline void resume(int x){for (;x <= n;x += lowbit(x)) {if(!c[x]) break;c[x] = 0;}}
    inline LL query(int x){LL ret = 0;for (;x;x -= lowbit(x)) ret += c[x];return ret;}
}
int tot, m;
struct NODE{
    int x, y, val;
    bool opt;
    NODE(){}
    NODE(int x, int y, int val, bool opt) : x(x), y(y), val(val), opt(opt){}
}e[MAXN << 3], g[MAXN << 3];
set <int> s[MAXN];
int a[MAXN], p[MAXN];
LL ans[MAXN];
bool vis[MAXN];
inline void ins(int i){
    auto it = s[a[i]].lower_bound(i);
    if(it != s[a[i]].begin()) p[i] = *(-- it);
    else p[i] = 0;
    e[++ tot] = NODE(p[i], i, i - p[i], 0);
}
void CDQ(int l, int r){
    if(l == r) return ;
    int mid = (l + r) >> 1;
    CDQ(l, mid);CDQ(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(e[i].x <= e[j].x){
            if(!e[i].opt) BIT :: modify(e[i].y, e[i].val);
            g[k ++] = e[i ++];
        }
        else{
            if(e[j].opt) {
                if(e[j].val > 0) ans[e[j].val] += BIT :: query(e[j].y);
                else ans[-e[j].val] -= BIT :: query(e[j].y);
            }
            g[k ++] = e[j ++];
        }
    }
    while(j <= r){
        if(e[j].opt) {
            if(e[j].val > 0) ans[e[j].val] += BIT :: query(e[j].y);
            else ans[-e[j].val] -= BIT :: query(e[j].y);
        }
        g[k ++] = e[j ++];
    }
    for (int t = l;t < i;++ t) if(!e[t].opt) BIT :: resume(e[t].y);
    while(i <= mid) g[k ++] = e[i ++];
    for (int t = l;t <= r;++ t) e[t] = g[t];
}
int main(){
    read(n, m);
    for (int i = 1;i <= n;++ i){read(a[i]);s[a[i]].emplace(i);}
    for (int i = 1;i <= n;++ i) ins(i);
    for (int i = 1;i <= m;++ i){
        int opt, l, r;read(opt, l, r);
        if(opt == 1){
            if(a[l] == r) continue;
            e[++ tot] = NODE(p[l], l, p[l] - l, 0);
            auto it = s[a[l]].upper_bound(l);
            int pos = -1;
            if(it != s[a[l]].end()) pos = *it;
            s[a[l]].erase(l);a[l] = r;
            s[r].emplace(l);ins(l);
            if(~pos){
                e[++ tot] = NODE(p[pos], pos, p[pos] - pos, 0);
                ins(pos);
            }
            it = s[r].upper_bound(l);
            if(it != s[r].end()){
                e[++ tot] = NODE(p[*it], *it, p[*it] - *it, 0);
                ins(*it);
            }
        }
        else{
            vis[i] = 1;
            e[++ tot] = NODE(l - 1, l - 1, i, 1);
            e[++ tot] = NODE(l - 1, r, -i, 1);
            e[++ tot] = NODE(r, l - 1, -i, 1);
            e[++ tot] = NODE(r, r, i, 1);
        }
    }
    CDQ(1, tot);
    for (int i = 1;i <= m;++ i){
        if(vis[i]) print(ans[i]);
    }
}