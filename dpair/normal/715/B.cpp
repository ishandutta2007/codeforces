// 
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)
#define elif else if
namespace MyMinMax{
template <typename T>
inline T mn(const T x, const T y) {return x < y ? x : y;}
template <typename T>
inline T mx(const T x, const T y) {return x > y ? x : y;}
template <typename T>
inline bool chmin(T &x, const T y) {return (x > y) && ((x = y), 1);}
template <typename T>
inline bool chmax(T &x, const T y) {return (x < y) && ((x = y), 1);}
template <typename T, typename ...Args>
inline T mx(const T x, const Args ...args) {return mx(x, mx(args...));}
template <typename T, typename ...Args>
inline T mn(const T x, const Args ...args) {return mn(x, mn(args...));}
}
using namespace MyMinMax;
namespace IO{
const int DPAIRSIZ = 1 << 18;
char BB[DPAIRSIZ], *SS = BB, *TT = BB;
inline char getcha(){return SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS ++;}
template <typename T = int>
inline T read(){
    T x = 0;int fu = 1;
    char c = getcha();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getcha();
    }
    while(c <= 57 && c >= 48){
        x = x * 10 + c - 48;
        c = getcha();
    }
    x *= fu;return x;
}
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
inline void read(T *bg, T *ed){while(bg != ed) read(*bg ++);}
inline void read(char &ch){
    ch = getcha();
    while(ch <= 32) ch = getcha();
}
inline void read(char *s){
    char ch = getcha();
    while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void sread(char *s){
    char ch = getcha();
    while(ch < 32) ch = getcha();
    while(ch >= 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void pread(char *&s){
    char ch = getcha();
    while(ch <= 32) ch = getcha();
    while(ch > 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
inline void spread(char *&s){
    char ch = getcha();
    while(ch < 32) ch = getcha();
    while(ch >= 32) *s ++ = ch, ch = getcha();
    *s = '\0';
}
template <typename T, typename ...Args>
inline void read(T &x, Args &...args){read(x);read(args...);}
char out[DPAIRSIZ], *Out = out;
#define flush() fwrite(out, 1, Out - out, stdout)
inline void putcha(char x) {*Out++ = x;if(Out - out >= (DPAIRSIZ)) flush(), Out = out;}
template <typename T>
inline void fprint(T x){
    if(x < 0) putcha(45), x = -x;
    if(x > 9) fprint(x / 10);
    putcha(x % 10 + 48);
}
inline void print(){putcha(10);}
template <typename T>
inline void print(T x){fprint(x);putcha(10);}
inline void print(char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
inline void put(char *ch){while(*ch != '\0') putcha(*(ch ++));}
inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
template <typename T, typename ...Args>
inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
template <typename ...Args>
inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
template <typename ...Args>
inline void print(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
template <typename T, typename ...Args>
inline void printl(T x, Args ...args){fprint(x);putcha(10);printl(args...);}
template <typename ...Args>
inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);printl(args...);}
template <typename ...Args>
inline void printl(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);printl(args...);}
template <typename T>
inline void sprint(T x){fprint(x);putcha(32);}
template <typename T, typename ...Args>
inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
template <typename T>
inline void sprint(T *bg, T *ed){while(bg != ed) sprint(*bg ++);}
template <typename T>
inline void print(T *bg, T *ed){while(bg != ed) sprint(*bg ++);putcha(10);}
template <typename T>
inline void printl(T *bg, T *ed){while(bg != ed) print(*bg ++);}
class AutoFlush{
    public:
        ~AutoFlush(){flush();}
}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL INFll = 0x3f3f3f3f3f3f3f3fll;
/* My Code begins here */

const int MAXN = 1e3 + 5;
const int MAXM = 1e4 + 5;

int head[MAXN], e[MAXM << 1], nxt[MAXM << 1], cnt, val[MAXM << 1];
inline void add(int u, int v, int w) {
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
    val[cnt] = w;
}
inline void link(int u, int v, int w) {add(u, v, w); add(v, u, w);}

LL dis[MAXN][2]; bool vis[MAXN]; int s, t, n, m, L, d;

struct DPair{
    int id; LL val;
    DPair (int id, LL val) : id(id), val(val) {}
    inline bool operator < (const DPair &tmp) const{return val > tmp.val;}
};

#include <queue>
std::priority_queue < DPair > q;
inline LL Dij1() {
    memset(dis, 63, sizeof(dis));
    dis[s][0] = 0; q.push(DPair(s, 0));
    while(!q.empty()) {
        const int x = q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x] = 1; for (int i = head[x];~i;i = nxt[i]) {
            const int v = !val[i]? 1 : val[i];
            if(dis[e[i]][0] > dis[x][0] + v) {
                dis[e[i]][0] = dis[x][0] + v;
                q.push(DPair(e[i], dis[e[i]][0]));
            }
        }
    } return dis[t][0];
}
inline LL Dij2() {
    memset(vis, 0, sizeof(vis));
    dis[s][1] = 0; q.push(DPair(s, 1));
    while(!q.empty()) {
        const int x = q.top().id; q.pop();
        if(vis[x]) continue;
        vis[x] = 1; for (int i = head[x];~i;i = nxt[i]) {
            int v = !val[i]? 1 : val[i];
            if(!val[i] && dis[x][1] + v < dis[e[i]][0] + d) {v = val[i] = val[i ^ 1] = dis[e[i]][0] + d - dis[x][1];}
            if(dis[e[i]][1] > dis[x][1] + v) {
                dis[e[i]][1] = dis[x][1] + v;
                q.push(DPair(e[i], dis[e[i]][1]));
            }
        }
    } return dis[t][1];
}

signed main(){
    memset(head, -1, sizeof(head)); cnt = -1;
    read(n, m, L, s, t); while(m --) {
        int u, v, w; read(u, v, w);
        link(u, v, w);
    } const int D = Dij1(); 
    if(D > L) return print("NO"), 0;
    d = L - D;
    if(Dij2() != L) return print("NO"), 0;
    print("YES");
    for (int i = 0;i <= cnt;i += 2) print(e[i + 1], e[i], val[i]? val[i] : 1);
}