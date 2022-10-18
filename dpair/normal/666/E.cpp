//
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
#define gup(x) return puts(#x), 0
namespace MyMinMax{
    template <typename T>
    inline T mn(const T x, const T y) {return x < y ? x : y;}
    template <typename T>
    inline T mx(const T x, const T y) {return x > y ? x : y;}
    template <typename T>
    inline void chmin(T &x, const T y) {(x > y) && (x = y);}
    template <typename T>
    inline void chmax(T &x, const T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
namespace IO{
    const int DPAIRSIZ = 1 << 18;
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
//DPair
#define MAXM 500005
#define MAXN 50005

char s[MAXM], buff[MAXN << 1], *p[MAXN];
int n, m, N;

struct Trie{
    int t[MAXN][26], tot;
    void ins(char *p){
        int rt = 0;
        for (char *it = p;*it != '\0';++ it){
            if(!t[rt][*it - 97]) t[rt][*it - 97] = ++ tot;
            rt = t[rt][*it - 97];
        }
    }
};

struct SegTree{
    int root[MAXN << 1], lc[MAXN << 6], rc[MAXN << 6], total;
    #define lson lc[rt], l, mid
    #define rson rc[rt], mid + 1, r
    struct DPair{
        int x, y;
        DPair(int x = 0, int y = 0) : x(x), y(y){}
        inline DPair operator + (const DPair &tmp) const{return (x ^ tmp.x? x < tmp.x : y > tmp.y) ? tmp : *this;}
    }tr[MAXN << 6];
    inline void pushup(int rt){tr[rt] = tr[lc[rt]] + tr[rc[rt]];}
    void insert(int &rt, int l, int r, int x){
        if(!rt) rt = ++ total;
        if(l == r) return tr[rt].y = x, ++ tr[rt].x, void();
        int mid = (l + r) >> 1;
        if(x <= mid) insert(lson, x);
        else insert(rson, x);
        pushup(rt);
    }
    DPair query(int rt, int l, int r, int x, int y){
        if(!rt) return DPair();
        if(x <= l && r <= y) return tr[rt];
        int mid = (l + r) >> 1;
        if(x <= mid && y > mid) return query(lson, x, y) + query(rson, x, y);
        if(x <= mid) return query(lson, x, y);
        else return query(rson, x, y);
    }
    int merge(int rt, int l, int r, int RT){
        if(!rt || !RT) return rt | RT;
        int o = ++ total;
        if(l == r){tr[o] = tr[rt];tr[o].x += tr[RT].x;return o;}
        int mid = (l + r) >> 1;
        lc[o] = merge(lson, lc[RT]);
        rc[o] = merge(rson, rc[RT]);
        pushup(o);return o;
    }
};


struct SAM : virtual public Trie, virtual public SegTree{
    int len[MAXN << 1], link[MAXN << 1];
    int nxt[MAXN << 1][26];
    int sz, lst[MAXN << 1];
    SAM(){len[0] = 0;link[0] = -1;++ sz;}
    int extend(int c, int pre){
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
    void layer(){
        int *hd = buf, *ed = buf + 1;
        while(hd != ed){
            int x = *hd ++;
            rep(i, 0, 25) if(t[x][i]){
                *ed ++ = t[x][i];
                lst[t[x][i]] = extend(i, lst[x]);
            }
        }
    }
    int c[MAXN], a[MAXN << 1], fa[MAXN << 1][17];
    int pos[MAXM], Len[MAXM];
    inline void init(){
        rep(i, 0, sz - 1) ++ c[len[i]];
        rep(i, 1, N) c[i] += c[i - 1];
        rep(i, 0, sz - 1) a[-- c[len[i]]] = i;
        
        rep(i, 1, n) {
            int rt = 0;
            for (char *it = p[i];*it != '\0';++ it){
                rt = nxt[rt][*it - 97];
                insert(root[rt], 1, n, i);
            }
        }
        per(i, sz - 1, 1){
            int x = a[i];
            root[link[x]] = merge(root[link[x]], 1, n, root[x]);
        }
        rep(i, 1, sz - 1){
            int x = a[i];fa[x][0] = link[x];
            rep(j, 1, 16) fa[x][j] = fa[fa[x][j - 1]][j - 1];
        }
        int rt = 0, cl = 0;
        for (char *it = s + 1;*it != '\0';++ it){
            if(nxt[rt][*it - 97]) rt = nxt[rt][*it - 97], ++ cl;
            else{
                while(~rt && !nxt[rt][*it - 97]) rt = link[rt];
                if(~rt) cl = len[rt] + 1, rt = nxt[rt][*it - 97];
                else rt = cl = 0;
            }
            pos[it - s] = rt;Len[it - s] = cl;
        }

    }
    inline void input(){
        read(s + 1);m = strlen(s + 1);
        read(n);char *it = buff;
        rep(i, 1, n){
            p[i] = ++ it;pread(it);
            ins(p[i]);chmax(N, (int)strlen(p[i]));
        }
    }
    inline void solve(){
        input();layer();init();
        int q;read(q);
        while(q --){
            int l, r, L, R;read(l, r, L, R);
            int le = R - L + 1;
            if(le > Len[R]) {
                print(l, 0);
                continue;
            }
            int x = pos[R];
            per(i, 16, 0) if(len[fa[x][i]] >= le) x = fa[x][i];
            DPair ans = query(root[x], 1, n, l, r);
            if(ans.x == 0) print(l, 0);
            else print(ans.y, ans.x);
        }
    }
}t;

int main(){t.solve();}