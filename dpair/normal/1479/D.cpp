/*
    author: DPair
    language: C++11

    description:
    
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using std :: sort;
using std :: unique;
using std :: lower_bound;
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
int n, m;
#define N 300005
const int bv = 547;//
const int BV = N / bv + 5;
const int bs = 1050;//
const int BS = (N << 1) / bs + 5;

int bel[N << 1];

struct Quest{
    int l, r, lca, id, L, R;
    inline bool operator < (const Quest &tmp) const{return (bel[tmp.l] == bel[l])? ((bel[l] & 1)? (r < tmp.r) : (r > tmp.r)) : bel[l] < bel[tmp.l];}
}q[N];
bool b[N];
int Bel[N], Cnt[BV], Fst[BV], Lst[BV];
inline void work(int x){
    if(b[x]) -- Cnt[Bel[x]], b[x] = 0;
    else ++ Cnt[Bel[x]], b[x] = 1;
}
int c[N];
int a[N << 1];

int head[N], nxt[N << 1], e[N << 1], CNT;
inline void add(int u, int v){
    nxt[++ CNT] = head[u];
    head[u] = CNT;
    e[CNT] = v;
}
int dep[N], tp[N], tot, fa[N], sz[N], son[N], dfn[N], low[N];
void dfs1(int x, int pre){
    a[++ tot] = c[x];dep[x] = dep[pre] + 1;fa[x] = pre;sz[x] = 1;dfn[x] = tot;
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs1(e[i], x);
        sz[x] += sz[e[i]];
        if(sz[son[x]] < sz[e[i]]) son[x] = e[i];
    }
    a[++ tot] = c[x];low[x] = tot;
}
void dfs2(int x, int tt){
    tp[x] = tt;
    if(son[x]) dfs2(son[x], tt);
    for (int i = head[x];i;i = nxt[i]){
        if(e[i] == fa[x] || e[i] == son[x]) continue;
        dfs2(e[i], e[i]);
    }
}
inline int LCA(int x, int y){
    while(tp[x] ^ tp[y]){
        if(dep[tp[x]] > dep[tp[y]]) x = fa[tp[x]];
        else y = fa[tp[y]];
    }
    if(dep[x] > dep[y]) return y;
    else return x;
}
inline int query(int x){
    for (int i = x;i <= Lst[Bel[x]];++ i) 
        if(b[i]) return i;
    for (int i = Bel[x] + 1;i <= Bel[n];++ i)
        if(Cnt[i])
            for (int j = Fst[i];j <= Lst[i];++ j)
                if(b[j]) return j;
    return -1;
}
int ans[N];
int main(){
    read(n, m);
    for (int i = 1;i <= n;++ i) read(c[i]), Bel[i] = (i - 1) / bv + 1;
    for (int i = 1;i <= Bel[n];++ i){Fst[i] = Lst[i - 1] + 1;Lst[i] = mn(i * bv, n);}
    for (int i = 1;i < n;++ i){
        int u, v;read(u, v);
        add(u, v);add(v, u);
    }
    dfs1(1, 0);dfs2(1, 1);
    for (int i = 1;i <= (n << 1);++ i) bel[i] = (i - 1) / bs + 1;
    for (int i = 1;i <= m;++ i){
        int u, v;read(u, v, q[i].L, q[i].R);
        int lca = LCA(u, v);
        if(dfn[u] > dfn[v]) std :: swap(u, v);
        if(lca == u) q[i].l = dfn[u], q[i].r = dfn[v], q[i].lca = -1;
        else q[i].l = low[u], q[i].r = dfn[v], q[i].lca = lca;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int l = q[1].l, r = l - 1;
    for (int i = 1;i <= m;++ i){
        while(r > q[i].r) work(a[r --]);
        while(r < q[i].r) work(a[++ r]);
        while(l > q[i].l) work(a[-- l]);
        while(l < q[i].l) work(a[l ++]);
        if(~q[i].lca) work(c[q[i].lca]);
        int res = query(q[i].L);
        ans[q[i].id] = res > q[i].R? -1 : res;
        if(~q[i].lca) work(c[q[i].lca]);
    }
    for (int i = 1;i <= m;++ i) print(ans[i]);
}