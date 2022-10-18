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


#define MOD 1000000007
int sig[10005], h, r, g;
typedef pair <int, int> pi;
int dp[200005];

int main(){
    read(r);read(g);
    for (register int i = 1;i;i ++){
        sig[i] = sig[i - 1] + i;
        if(sig[i] > r + g) break;
        h = i;
    }
    dp[0] = 1;
    for (register int i = 1;i <= h;i ++){
        for (register int j = r;j >= i;j --){
            dp[j] = dp[j - i] + dp[j];
            (dp[j] >= MOD) && (dp[j] -= MOD);
        }
    }
    int ans = 0;
    for (register int i = r;i >= 0;i --){
        if((h * (h + 1) >> 1) - i > g) break;
        ans = ans + dp[i];
        (ans >= MOD) && (ans -= MOD);
    }
    fprint(ans, 10);
}