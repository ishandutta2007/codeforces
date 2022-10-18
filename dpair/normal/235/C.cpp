//
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,l,r) for(int i=(l);i<(r);++i)
#define PER(i,l,r) for(int i=(l);i>(r);--i)
#define elif else if
#define gup(x) return puts(#x), 0
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
    #define DPAIRSIZ 1 << 18
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS++)
    char BB[DPAIRSIZ], *SS = BB, *TT = BB;
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
    inline void printl(T x, Args ...args){fprint(x);putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
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
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
//
#define MAXN 1000005
int n, m;
char p[MAXN], s[MAXN];
struct SAM{
    int len[MAXN << 1], link[MAXN << 1];
    int nxt[MAXN << 1][26];
    int sz, lst;
    SAM(){
        len[0] = 0;link[0] = -1;
        ++ sz;lst = 0;
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
        lst = x;
    }
    int vis[MAXN << 1], f[MAXN << 1], c[MAXN], a[MAXN << 1];
    inline void init(){
        int it = 0;
        rep(i, 1, n){
            it = nxt[it][s[i] - 97];
            ++ f[it];
        }

        rep(i, 0, sz - 1) ++ c[len[i]];
        rep(i, 1, n) c[i] += c[i - 1];
        rep(i, 0, sz - 1) a[-- c[len[i]]] = i;

        per(i, sz - 1, 1){
            int x = a[i];
            f[link[x]] += f[x];
        }
    }
    int tl, ml, cur, ans;
    inline void add(int x){
        while(cur && !nxt[cur][x]) cur = link[cur], tl = len[cur];
        if(nxt[cur][x]) cur = nxt[cur][x], ++ tl;
    }
    inline void del(){if(tl > ml && -- tl == len[link[cur]]) cur = link[cur];}
    inline void solve(){
        init();
        read(m);
        rep(k, 1, m){
            read(p + 1);ml = strlen(p + 1);ans = cur = tl = 0;
            for (char *it = p + 1;*it != '\0';++ it) add(*it - 97);
            for (char *it = p + 1;*it != '\0';++ it){
                add(*it - 97);del();
                if(tl == ml && vis[cur] < k){
                    ans += f[cur];
                    vis[cur] = k;
                }
            }
            print(ans);
        }
    }
}t;
int main(){
    read(s + 1);n = strlen(s + 1);
    rep(i, 1, n) t.extend(s[i] - 97);
    t.solve();
}