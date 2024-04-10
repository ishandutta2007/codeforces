/*
    author: DPair
    language: C++

    description:
    
    
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
    
    m
*/
#include <cstdio>
#include <cstring>
#include <bitset>
using std :: bitset;
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
    template <typename T>
    inline void readp(T &x){
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
        if(c == 46) {
            double y = 1;c = getcha();
            while(c <= 57 && c >= 48){
                x = x + (y *= 0.1) * (c - 48);
                c = getcha();
            }
        }
        x *= fu;
    }
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){
        read(x);read(args...);
    }
    template <typename T, typename ...Args>
    inline void readp(T &x, Args &...args){
        readp(x);readp(args...);
    }
    inline void readc(char &x){
        char c = getcha();
        while(c == ' ' || c == '\n' || c == '\r') c = getcha();
        x = c;
    }
    inline void reads(char x[], int pos = 0){
        char c = getcha();
        while(c == ' ' || c == '\n' || c == '\r') c = getcha();
        while(c ^ ' ' && c ^ '\n' && c ^ '\r') x[pos ++] = c, c = getcha();
        x[pos] = '\0';
    }
    inline void readl(char x[], int pos = 0){
        char c = getcha();
        while(c == '\n' || c == '\r') c = getcha();
        while(c ^ '\n' && c ^ '\r') x[pos ++] = c, c = getcha();
        x[pos] = '\0';
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
    inline void fprint(T x, char ch){
        fprint(x);putcha(ch);
    }
    inline void prints(char c[]){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
    }
    inline void prints(char c[], char ch){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
        putcha(ch);
    }
    inline void prints(const char c[]){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
    }
    inline void prints(const char c[], char ch){
        int pos = 0;
        while(c[pos] != '\0') putcha(c[pos ++]);
        putcha(ch);
    }
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;

typedef bitset <1005> bs;
bs mod, p;
int prime[1005], tot;
int n, m;
inline void init(){
    for (register int i = 0;i < m;++ i) mod[i] = p[i] = 1;
    p[0] = p[1] = 0;
    for (register int i = 2;i < m;++ i){
        if(p[i]) prime[++ tot] = i;
        for (register int j = 1;j <= tot && i * prime[j] < m;++ j){
            p[i * prime[j]] = 0;
            if(i % prime[j] == 0) break;
        } 
    }
}

#define MAXN 100005
bs t[MAXN << 2];
int a[MAXN];
int dfn[MAXN], low[MAXN], val[MAXN];
int tag[MAXN << 2];

#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
void build(int rt, int l, int r){
    if(l == r){
        t[rt][val[l]] = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    t[rt] = t[rt << 1] | t[rt << 1 | 1];
}
inline void update(int rt, int z){
    bs tmp = (t[rt] << z);
    t[rt] = ((tmp & mod) | (t[rt] >> (m - z)));
    tag[rt] = (tag[rt] + z) % m;
}
inline void pushdown(int rt){
    if(tag[rt]){
        update(rt << 1, tag[rt]);
        update(rt << 1 | 1, tag[rt]);
        tag[rt] = 0;
    }
}
void modify(int rt, int l, int r, int x, int y, int z){
    if(x <= l && r <= y) return update(rt, z);
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(LSON, x, y, z);
    if(y > mid) modify(RSON, x, y, z);
    t[rt] = t[rt << 1] | t[rt << 1 | 1];
}
bs query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return query(LSON, x, y) | query(RSON, x, y);
    if(x <= mid) return query(LSON, x, y);
    else return query(RSON, x, y);
}
int head[MAXN], e[MAXN << 1], nxt[MAXN << 1], cnt;
inline void add(int u, int v){
    nxt[++ cnt] = head[u];
    head[u] = cnt;
    e[cnt] = v;
}
inline void link(int u, int v){add(u, v);add(v, u);}
void dfs(int x, int pre){
    dfn[x] = ++ tot;val[tot] = a[x];
    for (register int i = head[x];i;i = nxt[i]){
        if(e[i] == pre) continue;
        dfs(e[i], x);
    }
    low[x] = tot;
}
inline void input(){
    for (register int i = 1;i <= n;++ i) read(a[i]), a[i] %= m;
    for (register int i = 1;i < n;++ i){
        int u, v;read(u, v);
        link(u, v);
    }
    tot = 0;
    dfs(1, 0);
}
inline void solve(){
    build(1, 1, n);
    int Q;read(Q);
    while(Q --){
        int opt, x, y;read(opt);
        if(opt == 1){
            read(x, y);
            y %= m;modify(1, 1, n, dfn[x], low[x], y);
        }
        else read(x), fprint((query(1, 1, n, dfn[x], low[x]) & p).count(), 10);
    }
}
int main(){
    read(n, m);
    init();input();solve();
}