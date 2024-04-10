#include <bits/stdc++.h>
using namespace std;
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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
#define MAXN 100005
#define block 1302
const int B = MAXN / block + 5;
int bel[MAXN], a[MAXN];
struct Quest{
    int l, r, t, id;
    inline bool operator < (const Quest &tmp) const{
        return (bel[l] ^ bel[tmp.l])? l < tmp.l : ((bel[r] ^ bel[tmp.r])? ((bel[l] & 1)? r < tmp.r : r > tmp.r) : t < tmp.t);
    }
}q[MAXN];
typedef pair <int, int> pi;
pi c[MAXN];
int n, m, m1, m2;
int cnt1[MAXN], cnt2[MAXN << 1];
int b[MAXN << 1], cnt, tot;
int ans[MAXN];

inline void add(int x){
    cnt1[cnt2[x]] --; 
    cnt1[++ cnt2[x]] ++;
}

inline void del(int x){
    cnt1[cnt2[x]] --;
    cnt1[-- cnt2[x]] ++;
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);b[++ cnt] = a[i];
        bel[i] = (i - 1) / block + 1;
    }
    for (register int i = 1;i <= m;i ++){
        int opt;read(opt);
        if(opt == 1){
            read(q[++ m1].l);
            read(q[m1].r);
            q[m1].id = m1;
            q[m1].t = m2;
        }
        else{
            read(c[++ m2].first);
            read(c[m2].second);
            b[++ cnt] = c[m2].second;
        }
    }
    sort(b + 1, b + cnt + 1);
    tot = unique(b + 1, b + cnt + 1) - b - 1;
    for (register int i = 1;i <= n;i ++) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    for (register int i = 1;i <= m2;i ++) c[i].second = lower_bound(b + 1, b + tot + 1, c[i].second) - b;
    sort(q + 1, q + m1 + 1);
    int t = 0, l = q[1].l, r = l - 1;
    for (register int i = 1;i <= m1;i ++){
        while(l > q[i].l) add(a[-- l]);
        while(r < q[i].r) add(a[++ r]);
        while(l < q[i].l) del(a[l ++]);
        while(r > q[i].r) del(a[r --]);
        while(t < q[i].t){
            t ++;
            if(c[t].first >= l && c[t].first <= r){
                del(a[c[t].first]);
                add(c[t].second);
            }
            swap(a[c[t].first], c[t].second);
        }
        while(t > q[i].t){
            if(c[t].first >= l && c[t].first <= r){
                del(a[c[t].first]);
                add(c[t].second);
            }
            swap(a[c[t].first], c[t].second);
            t --;
        }
        int res = 1;
        while(cnt1[res]) res ++;
        ans[q[i].id] = res;
    }
    for (register int i = 1;i <= m1;i ++) fprint(ans[i], 10);
}