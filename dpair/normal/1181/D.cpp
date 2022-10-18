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
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}

int n, m, q;
LL cnt[500005], a[500005], k;
int main(){
    read(n);read(m);read(q);
    for (int i = 1;i <= n;i ++) {
        int x;read(x);
        a[i] = (cnt[x] ++) * m + x;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;i ++) a[i] -= i;
    while(q --){
        read(k);
        k -= n - (lower_bound(a + 1, a + n + 1, k - n) - a - 1);
        fprint((k - 1) % m + 1, 10);
    }
    return 0;
}