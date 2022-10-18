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

typedef long long LL;
LL ans = 0x3f3f3f3f3f3f3f3f;
int prime[15] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int n;

void dfs(int x, int res, LL cur = 1){
    if(res == 1) {ans = cur;return ;}
    LL num = prime[x];
    for (register int i = 2;i <= res && i <= 64;i ++){
        if(ans / num <= cur) return ;
        if(res % i == 0){
            dfs(x + 1, res / i, cur * num);
        }
        num *= prime[x];
    }
}

int main(){
    scanf("%d", &n);
    dfs(1, n);
    printf("%lld\n", ans);
}