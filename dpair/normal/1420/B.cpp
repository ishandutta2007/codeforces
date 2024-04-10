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

int cnt[35];

inline int highbit(int x){
    for (register int i = 30;i >= 0;i --){
        if((1 << i) & x) return i;
    }
    return 0;
}
int n;
inline void work(){
    memset(cnt, 0, sizeof(cnt));
    read(n);LL ans = 0;
    for (register int i = 1;i <= n;i ++){
        int x;read(x);
        int num = highbit(x);
        ans += cnt[num] ++;
    }
    fprint(ans, 10);
}

int main(){
    int ___;
    read(___);
    while(___ --) work();
}