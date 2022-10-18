//
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
const double pi = 3.141592653589793238462643383279;
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

#define MAXN 200005


int n, q, N; char buff[MAXN << 1], *s[MAXN];

int t[MAXN << 6], lc[MAXN << 6], rc[MAXN << 6], tot;
void modify(int &rt, int l, int r, const int x) {
    if(!rt) rt = ++ tot;
    ++ t[rt]; if(l == r) return ;
    int mid = (l + r) >> 1; x <= mid? modify(lc[rt], l, mid, x) : modify(rc[rt], mid + 1, r, x);
}
int query(int rt, int l, int r, int x, int y) {
    if(!rt) return 0;
    if(x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1;
    if(x > mid) return query(rc[rt], mid + 1, r, x, y);
    if(y <= mid) return query(lc[rt], l, mid, x, y);
    return query(lc[rt], l, mid, x, y) + query(rc[rt], mid + 1, r, x, y);
}

int merge(int rt, int RT) {
    if(!rt || !RT) return rt | RT;
    int o = ++ tot; t[o] = t[rt] + t[RT];
    lc[o] = merge(lc[rt], lc[RT]);
    rc[o] = merge(rc[rt], rc[RT]);
    return o;
}

struct Trie{
    int t[MAXN][26], tot;
    inline void ins(char *p){
        int rt = 0;
        for (char *it = p;*it != '\0';++ it){
            if(!t[rt][*it - 97]) t[rt][*it - 97] = ++ tot;
            rt = t[rt][*it - 97];
        }
    }
};
struct SAM : virtual public Trie{
    int len[MAXN << 1], link[MAXN << 1];
    int nxt[MAXN << 1][26];
    int sz, lst[MAXN << 1];
    SAM(){len[0] = 0;link[0] = -1;++ sz;}
    inline int extend(int c, int pre){
        int x = sz ++;
        len[x] = len[pre] + 1;
        int it = pre;
        while(~it && !nxt[it][c]){
            nxt[it][c] = x;
            it = link[it];
        }
        if(!~it) link[x] = 0;
        else{
            int t = nxt[it][c];
            if(len[it] + 1 == len[t]) link[x] = t;
            else{
                int y = sz ++;
                len[y] = len[it] + 1;
                memcpy(nxt[y], nxt[t], sizeof(nxt[y]));
                link[y] = link[t];
                while(~it && nxt[it][c] == t){
                    nxt[it][c] = y;
                    it = link[it];
                }
                link[t] = link[x] = y;
            }
        }
        return x;
    }
    int buf[MAXN];
    inline void layer(){
        int *hd = buf, *ed = buf + 1;
        while(hd != ed){
            int x = *hd ++;
            rep(i, 0, 25) if(t[x][i]){
                *ed ++ = t[x][i];
                lst[t[x][i]] = extend(i, lst[x]);
            }
        }
    }
    int a[MAXN << 1], c[MAXN], root[MAXN << 1], pos[MAXN];
    inline void init() { layer(); 
        REP(i, 0, sz) ++ c[len[i]];
        rep(i, 1, N) c[i] += c[i - 1];
        REP(i, 0, sz) a[-- c[len[i]]] = i;

        rep(i, 1, n) {
            int rt = 0; for (char *it = s[i];*it != '\0';++ it) {
                rt = nxt[rt][*it - 97];
                modify(root[rt], 1, n, i);
            } pos[i] = rt;
        }

        per(i, sz - 1, 1) {
            const int x = a[i];
            root[link[x]] = merge(root[link[x]], root[x]);
        }
    }
    inline void solve() { init();
        while(q --) {
            int l, r, x; read(l, r, x);
            print(query(root[pos[x]], 1, n, l, r));
        }
    }
}sam;

signed main(){
    read(n, q); char *it = buff;
    rep(i, 1, n) {s[i] = ++ it; pread(it); chmax(N, (int)strlen(s[i]));}
    rep(i, 1, n) sam.ins(s[i]);
    sam.solve();
}