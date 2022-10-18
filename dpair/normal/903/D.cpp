#include <bits/stdc++.h>
using namespace std;
typedef __int128 LL;

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
LL sig = 0, ans = 0;
LL a[200005];
unordered_map <int, int> h;
int main(){
    read(n);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);LL num = a[i] * (i - 1);
        ans += num - sig;
        sig += a[i];
        ans -= h[a[i] - 1];ans += h[a[i] + 1];
        h[a[i]] ++;
    }
    fprint(ans, 10);
    return 0;
}