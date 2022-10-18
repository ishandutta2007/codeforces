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

map <pi, LL> h;
int n, a[200005], cnt[200005];
LL ans;
int main(){
    read(n);
    for (int i = 1;i <= n;++ i) read(a[i]), ans += a[i];
    int q;read(q);a[0] = -0x3f3f3f3f;
    while(q --){
        int x, y, z;read(x);read(y);read(z);
        int tmp = h[make_pair(x, y)];
        ans -= max(a[tmp] - cnt[tmp], 0);
        cnt[tmp] --;
        ans += max(a[tmp] - cnt[tmp], 0);
        ans -= max(a[z] - cnt[z], 0);
        h[make_pair(x, y)] = z;
        cnt[z] ++;
        ans += max(a[z] - cnt[z], 0);
        fprint(ans, 10);
    }
    return 0;
}