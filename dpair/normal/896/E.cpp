#include <cstdio>
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}
const int MAXN = 1000005;
const int MAXM = 500005;
const int V = 100007;
const int block = 1000;
int n, m, a[MAXN];
int ans[MAXM], bel[MAXN];
int fa[MAXN], sz[V], rt[V], val[MAXN];
int fst, lst;
int opt[MAXM], l[MAXM], r[MAXM], x[MAXM];
int tag, R;
inline int anc(int x){
    if(fa[x] == x) return x;
    return fa[x] = anc(fa[x]);
}
inline void merge(int x, int y){
    if(rt[y]) fa[rt[x]] = rt[y];
    else rt[y] = rt[x], val[rt[y]] = y;
    sz[y] += sz[x];
    sz[x] = rt[x] = 0;
}
inline void rebuild(){
    for (register int i = fst;i <= lst;++ i) a[i] = val[anc(i)], sz[a[i]] = rt[a[i]] = 0, a[i] -= tag;
    for (register int i = fst;i <= lst;++ i) fa[i] = 0;
}
inline void build(){
    tag = 0;R = -0x3f3f3f3f;
    for (register int i = fst;i <= lst;++ i) {
        chmax(R, a[i]);
        if(!rt[a[i]]) rt[a[i]] = i, val[i] = a[i];
        fa[i] = rt[a[i]];
        sz[a[i]] ++;
    }
}
inline void modify_bruh(int ll, int rr, int xx){
    if(ll > rr) return ;
    rebuild();
    for (register int k = ll;k <= rr;++ k)
        if(a[k] > xx) a[k] -= xx;
    build();
}
inline void modify(int xx){
    if((xx << 1) <= R - tag){
        for (register int k = tag + xx;k > tag;k --)
            if(rt[k]) merge(k, k + xx);
        tag += xx;
    }
    else{
        for (register int k = R;k > xx + tag;k --)
            if(rt[k]) merge(k, k - xx);
        R = mn(R, tag + xx);
    }
}
inline int query_bruh(int ll, int rr, int xx){
    int res = 0;
    for (register int k = ll;k <= rr;++ k)
        if(val[anc(k)] - tag == xx) res ++;
    return res;
}
int main(){
    read(n);read(m);
    const int tot = 1e5 + 1;
    for (register int i = 1;i <= n;++ i){
        read(a[i]);bel[i] = (i - 1) / block + 1;
    }
    for (register int i = 1;i <= m;++ i) read(opt[i]), read(l[i]), read(r[i]), read(x[i]);
    for (register int i = 1;i <= bel[n];++ i){
        fst = (i - 1) * block + 1;lst = mn(n, i * block);
        build();
        for (register int j = 1;j <= m;++ j){
            if(opt[j] == 1){
                if(l[j] <= fst && lst <= r[j]) modify(x[j]);
                else modify_bruh(mx(l[j], fst), mn(r[j], lst), x[j]);
            }
            else{
                if(l[j] <= fst && lst <= r[j]){
                    if(x[j] + tag > tot) continue;
                    ans[j] += sz[x[j] + tag];
                }
                else ans[j] += query_bruh(mx(l[j], fst), mn(r[j], lst), x[j]);
            }
        }
        rebuild();
    }
    for (register int j = 1;j <= m;++ j)
        if(opt[j] == 2) fprint(ans[j], 10);
}