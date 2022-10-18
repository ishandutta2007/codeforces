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

int n;
struct Quest{
    int x, t, opt, id;
    inline bool operator < (const Quest &tmp) const{
        return x < tmp.x || (x == tmp.x && id < tmp.id);
    }
}q[MAXN];
int c[MAXN];
inline int lowbit(int x){return x & -x;}
inline int query(int x){int ret = 0;for (;x;x -= lowbit(x)) ret += c[x];return ret;}
inline void modify(int x, int y){for (;x <= n;x += lowbit(x)) c[x] += y;}
int ans[MAXN], b[MAXN];
int main(){
    read(n);
    memset(ans, -1, sizeof(ans));
    for (register int i = 1;i <= n;i ++){
        read(q[i].opt);read(q[i].t);read(q[i].x);
        b[i] = q[i].t;
        q[i].id = i;
    }
    sort(b + 1, b + n + 1);
    int tot = unique(b + 1, b + n + 1) - b - 1;
    for (register int i = 1;i <= n;i ++) q[i].t = lower_bound(b + 1, b + tot + 1, q[i].t) - b;
    sort(q + 1, q + n + 1);
    int it = 1;
    while(it <= n){
        int mem = it;
        while(q[it].x == q[mem].x){
            if(q[it].opt == 1) modify(q[it].t, 1);
            if(q[it].opt == 2) modify(q[it].t, -1);
            if(q[it].opt == 3) ans[q[it].id] = query(q[it].t);
            it ++;
        }
        it = mem;
        while(q[it].x == q[mem].x){
            if(q[it].opt == 1) modify(q[it].t, -1);
            if(q[it].opt == 2) modify(q[it].t, 1);
            it ++;
        }
    }
    for (register int i = 1;i <= n;i ++){
        if(~ans[i]) fprint(ans[i], 10);
    }
}