#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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

int n, m, block;
LL a[200005];

inline int idb(int x){return (x / block);}

struct QUEST{
    int l, r;
    int id;
    inline bool operator <(const QUEST &tmp) const{
        return (idb(l) ^ idb(tmp.l)) ?(l < tmp.l) : ((idb(l) & 1)? r < tmp.r : r > tmp.r);
    }
}q[200005];

LL cnt[1000005], ans, k;
LL ret[200005];
inline void add(LL x){
    ans += (cnt[x] << 1 | 1) * x;
    cnt[x] ++;
}
inline void del(LL x){
    cnt[x] --;
    ans -= (cnt[x] << 1 | 1) * x;
}

int main(){
    read(n);read(m);
    for (register int i = 1;i <= n;++ i) read(a[i]);
    block = sqrt(n);
    for (register int i = 1;i <= m;++ i) {read(q[i].l);read(q[i].r);q[i].id = i;}
    sort(q + 1, q + m + 1);
    int l = q[1].l, r = l - 1;
    for (register int i = 1;i <= m;++ i){
        while(l > q[i].l) add(a[-- l]);
        while(r < q[i].r) add(a[++ r]);
        while(l < q[i].l) del(a[l ++]);
        while(r > q[i].r) del(a[r --]);
        ret[q[i].id] = ans;
    }
    for (register int i = 1;i <= m;++ i) fprint(ret[i], 10);
    return 0;
}