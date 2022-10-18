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
int n;
typedef long long LL;
inline int lowbit(int x){return x & -x;}
LL c1[1000005], c2[1000005];
inline void modify(LL c[], int x, LL val){for (register int i = x;i <= n;i += lowbit(i)) c[i] += val;}
inline LL query(LL c[], int x){LL ret = 0;for (register int i = x;i;i -= lowbit(i)) ret += c[i];return ret;}
struct NUM{
    int id;int val;
}a[1000005];
inline bool cmp1(NUM x, NUM y){return x.val < y.val;}
inline bool cmp2(NUM x, NUM y){return x.id < y.id;}

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(a[i].val);a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp1);
    for (register int i = 1;i <= n;i ++) a[i].val = i;
    sort(a + 1, a + n + 1, cmp2);
    LL ans = 0, tot = 0;
    for (register int i = 1;i <= n;i ++){
        modify(c1, a[i].val, 1);
        LL num = i - query(c1, a[i].val);
        modify(c2, a[i].val, num);tot += num;
        ans = ans + tot - query(c2, a[i].val);
    }
    fprint(ans, 10);
    return 0;
}