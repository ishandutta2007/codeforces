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
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
#define MAXN 1000005

int n;
char a[MAXN];

struct Dat{
    int L, R;
    inline Dat operator + (const Dat &b) const{
        Dat ret;
        ret.L = L + b.L - mn(R, b.L);
        ret.R = R + b.R - mn(R, b.L);
        return ret;
    }
}t[MAXN << 2]; 


inline void pushup(int rt){t[rt] = t[rt << 1] + t[rt << 1 | 1];}

#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r

void build(int rt, int l, int r){
    if(l == r){
        t[rt].L = (a[l] == ')' ? 1 : 0);
        t[rt].R = (a[l] == '(' ? 1 : 0);
        return ;
    }
    int mid = (l + r) >> 1;
    build(LSON);build(RSON);
    pushup(rt);
}

Dat query(int rt, int l, int r, int x, int y){
    if(x <= l && r <= y) return t[rt];
    int mid = (l + r) >> 1;
    if(x <= mid && y > mid) return query(LSON, x, y) + query(RSON, x, y);
    if(x <= mid) return query(LSON, x, y);
    else return query(RSON, x, y);
}

int main(){
    scanf("%s", a + 1);
    n = strlen(a + 1);
    build(1, 1, n);
    int q;read(q);
    while(q --){
        int l, r;read(l);read(r);
        Dat ret = query(1, 1, n, l, r);
        fprint(r - l + 1 - ret.L - ret.R, 10);
    }
}