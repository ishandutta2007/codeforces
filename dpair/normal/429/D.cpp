#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int, int> pi;

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

inline LL dis(pi x, pi y){return 1ll * (x.first - y.first) * (x.first - y.first) + 1ll * (x.second - y.second) * (x.second - y.second);}
int n, sig[100005];
pi a[100005];
inline bool cmp(pi x, pi y){return x.second < y.second || (x.second == y.second && x.first < y.first);}
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(sig[i]), sig[i] += sig[i - 1], a[i] = make_pair(i, sig[i]);
    LL ans = 0x3f3f3f3f3f3f3f3f;
    sort(a + 1, a + n + 1);
    for (register int i = 1;i <= n;i ++){
        for (register int j = i + 1;j <= min(i + 30, n);j ++){
            ans = min(ans, dis(a[i], a[j]));
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for (register int i = 1;i <= n;i ++){
        for (register int j = i + 1;j <= min(i + 30, n);j ++){
            ans = min(ans, dis(a[i], a[j]));
        }
    }
    fprint(ans, 10);
}