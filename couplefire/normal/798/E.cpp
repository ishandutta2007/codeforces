#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
#define lc x<<1
#define rc x<<1|1
#define lson lc, l, mid
#define rson rc, mid+1, r
#define pii pair<int, int>
#define fir first
#define sec second
const int N = 5e5+5;
inline int read(){
    char c=getchar(); int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}
 
int n, a[N], b[N], vis[N];
 
namespace S {
    pair<int, int> t[N<<2];
    void build(int x, int l, int r) {
        if(l == r) t[x] = make_pair(b[l], l);
        else {
            build(lson);
            build(rson);
            t[x] = max(t[lc], t[rc]);
        }
    }
    pii que(int x, int l, int r, int ql, int qr) {
        if(ql<=l && r<=qr) return t[x];
        else {
            if(qr <= mid) return que(lson, ql, qr);
            if(mid < ql)  return que(rson, ql, qr);
            return max(que(lson, ql, qr), que(rson, ql, qr));
        }
    }
    void del(int x, int l, int r, int p) {
        if(l == r) t[x] = make_pair(0, l);
        else {
            if(p <= mid) del(lson, p);
            else del(rson, p);
            t[x] = max(t[lc], t[rc]);
        }
    }
}
 
int q[N], m, p[N];
void dfs(int u) { 
    vis[u] = 1;
    S::del(1, 1, n, u);
    if(b[u] != n+1 && !vis[b[u]]) dfs(b[u]);
    if(a[u] > 1) while(true) {
        pii v = S::que(1, 1, n, 1, a[u]-1);
        if(v.fir > u) dfs(v.sec);
        else break;
    }
    q[++m] = u;
}
int main() {
    //freopen("in", "r", stdin);
    n = read();
    for(int i=1; i<=n; i++) {
        a[i] = read();
        if(a[i] != -1) b[a[i]] = i;
        else a[i] = n+1;
    }
    for(int i=1; i<=n; i++) if(!b[i]) b[i] = n+1;
    S::build(1, 1, n);
    for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
    m = 0;
    for(int i=1; i<=n; i++) p[q[i]] = ++m;
    for(int i=1; i<=n; i++) printf("%d ", p[i]);
}