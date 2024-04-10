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
// #define int long long
#define MAXN 100005
int n, m, N, Len[MAXN]; char buff[MAXN << 1], *s[MAXN];
LL ans[MAXN];
const int lim = 400;
struct CASE{
    int l, r, k, id, len;
    inline bool operator< (const CASE &tmp) const{return (len < tmp.len || (len == tmp.len && k < tmp.k));}
}q[MAXN];

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
const int block = 400;
struct EXSAM : virtual public Trie{
    int len[MAXN << 1], link[MAXN << 1];
    int nxt[MAXN << 1][26];
    int sz, lst[MAXN << 1];
    EXSAM(){len[0] = 0;link[0] = -1;++ sz;}
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
    int head[MAXN << 1], e[MAXN << 1], cnt, nt[MAXN << 1], dfn[MAXN << 1], low[MAXN << 1], total;
    inline void add(int u, int v){
        nt[++ cnt] = head[u];
        head[u] = cnt;
        e[cnt] = v;
    }
    void dfs(int x) {
        dfn[x] = ++ total;
        for (int i = head[x];i;i = nt[i]) dfs(e[i]);
        low[x] = total;
    }
    inline void init() { layer(); 
        REP(i, 0, sz) ++ c[len[i]];
        rep(i, 1, N) c[i] += c[i - 1];
        REP(i, 0, sz) a[-- c[len[i]]] = i;
        REP(i, 1, sz) add(link[i], i);
        dfs(0); rep(i, 1, n) {
            int rt = 0; for (char *it = s[i];*it != '\0';++ it) rt = nxt[rt][*it - 97];
            pos[i] = rt;
        }
    }
    int TOT;
    struct Quest{
        int id, r, pos;
        inline bool operator< (const Quest &tmp) const{return r < tmp.r;}
    }w[MAXN << 1];
    
    int val[MAXN << 1], tag[MAXN << 1], bel[MAXN << 1], P[(MAXN << 1) / block + 5];
    inline void prework() {
        rep(i, 1, total) bel[i] = (i - 1) / block + 1;
        rep(i, 1, bel[total]) P[i] = mn(i * block, total);
    }
    inline void update(int l, int r) {
        const int L = bel[l], R = bel[r];
        if(L == R) {rep(i, l, r) ++ val[i];}
        else {
            rep(i, l, P[L]) ++ val[i];
            rep(i, P[R - 1] + 1, r) ++ val[i];
            rep(i, L + 1, R - 1) ++ tag[i];
        }
    }
    inline int solve() { init();
        int st = m + 1; rep(i, 1, m) {
            if(q[i].len > lim) {st = i; break;}
            w[++ TOT].id = q[i].id; w[TOT].pos = q[i].k; w[TOT].r = q[i].r;
            if(q[i].l != 1) {w[++ TOT].id = -q[i].id; w[TOT].pos = q[i].k; w[TOT].r = q[i].l - 1; }
        } std :: sort(w + 1, w + TOT + 1); prework();
        int it = 0; rep(i, 1, TOT) {
            while(it < w[i].r) { ++ it; update(dfn[pos[it]], low[pos[it]]);}
            const int fu = w[i].id < 0? -1 : 1, id = w[i].id * fu;
            int rt = 0; for (char *it = s[w[i].pos];*it != '\0';++ it) {
                rt = nxt[rt][*it - 97];
                ans[id] += fu * (tag[bel[dfn[rt]]] + val[dfn[rt]]);
            }
        } return st;
    }
}sam;


LL b[MAXN];

struct SAM{
    int len[MAXN << 1], link[MAXN << 1];
    int nxt[MAXN << 1][26];
    int sz, lst, f[MAXN << 1];
    SAM(){
        len[0] = 0;link[0] = -1;
        ++ sz;lst = 0;
    }
    inline void clear() {
        memset(nxt, 0, 26 * sz * sizeof(int));
        memset(f, 0, sz * sizeof(int));
        sz = 1; lst = 0;
    }
    inline void extend(int c){
        int x = sz ++;
        len[x] = len[lst] + 1;
        int it = lst;
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
        f[lst = x] = 1;
    }
    int a[MAXN << 1], c[MAXN];
    inline void init(const int nn) {
        memset(c, 0, (nn + 1) * sizeof(int));
        // debug("memset!\n");
        REP(i, 0, sz) ++ c[len[i]];
        rep(i, 1, nn) c[i] += c[i - 1];
        REP(i, 0, sz) a[-- c[len[i]]] = i;
        // debug("sort!\n");
        per(i, sz - 1, 1) {
            const int x = a[i];
            f[link[x]] += f[x];
        }
    }
    inline int match(char *const str) {
        int rt = 0; for (char *it = str;*it !='\0';++ it) {
            rt = nxt[rt][*it - 97];
            if(!rt) return 0;
        } return f[rt];
    }
}Sam;


signed main(){
    read(n, m); char *it = buff;
    rep(i, 1, n) {s[i] = ++ it; pread(it); chmax(N, Len[i] = (int)strlen(s[i]));}
    rep(i, 1, n) sam.ins(s[i]);
    rep(i, 1, m) {
        read(q[i].l, q[i].r, q[i].k);
        q[i].id = i; q[i].len = Len[q[i].k];
    }
    std :: sort(q + 1, q + m + 1);
    const int st = sam.solve();
    // debug("m = %d\n", m);
    rep(i, st, m) {
    // debug("So far i = %d\n", i);
        if(q[i].k ^ q[i - 1].k) {
            Sam.clear();
            // debug("clear!\n");
            for (char *it = s[q[i].k];*it != '\0';++ it) Sam.extend(*it - 97);
            // debug("extend!\n");
            Sam.init(q[i].len);
            // debug("init!\n");
            rep(j, 1, n) b[j] = b[j - 1] + Sam.match(s[j]);
            // debug("match!\n");
        }
        ans[q[i].id] = b[q[i].r] - b[q[i].l - 1];
    } printl(ans + 1, ans + m + 1);
}