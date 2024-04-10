/*
    author: DPair
    language: C++

    description:
    a[i] != a[i - 1] && a[i] != a[i - 2]
*/
#include <algorithm>
using std :: sort;
#include <cstring>
#include <cstdio>
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
namespace MyMinMax{
    template <typename T>
    inline T mn(T x, T y) {return x < y ? x : y;}
    template <typename T>
    inline T mx(T x, T y) {return x > y ? x : y;}
    template <typename T>
    inline void chmin(T &x, T y) {(x > y) && (x = y);}
    template <typename T>
    inline void chmax(T &x, T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
char a[100005];
int n;
int dp[100005][2][2];
#define INF 0x3f3f3f3f
// for all j <= i is legal
inline void solve(){
    scanf("%s", a + 1);n = strlen(a + 1);
    dp[1][0][0] = 0;
    dp[1][1][0] = 0;
    dp[1][1][1] = 1;
    dp[1][0][1] = 1;
    for (register int i = 2;i <= n;i ++){
        if(a[i] == a[i - 1] && a[i] == a[i - 2]){
            dp[i][0][0] = INF;
            dp[i][0][1] = dp[i - 1][1][0] + 1;
            dp[i][1][0] = dp[i - 1][1][1];
            dp[i][1][1] = mn(dp[i - 1][0][1], dp[i - 1][1][1]) + 1;
        }
        else if(a[i] == a[i - 1]){
            dp[i][0][0] = INF;
            dp[i][0][1] = mn(dp[i - 1][1][0], dp[i - 1][0][0]) + 1;
            dp[i][1][0] = mn(dp[i - 1][1][1], dp[i - 1][0][1]);
            dp[i][1][1] = mn(dp[i - 1][0][1], dp[i - 1][1][1]) + 1;
        }
        else if(a[i] == a[i - 2]){
            dp[i][0][0] = dp[i - 1][1][0];
            dp[i][0][1] = mn(dp[i - 1][1][0], dp[i - 1][0][0]) + 1;
            dp[i][1][0] = dp[i - 1][1][1];
            dp[i][1][1] = mn(dp[i - 1][0][1], dp[i - 1][1][1]) + 1;
        }
        else {
            dp[i][0][0] = mn(dp[i - 1][0][0], dp[i - 1][1][0]);
            dp[i][0][1] = mn(dp[i - 1][1][0], dp[i - 1][0][0]) + 1;
            dp[i][1][0] = mn(dp[i - 1][1][1], dp[i - 1][0][1]);
            dp[i][1][1] = mn(dp[i - 1][0][1], dp[i - 1][1][1]) + 1;
        }
    }
    fprint(mn(mn(dp[n][0][0], dp[n][0][1]), mn(dp[n][1][0], dp[n][1][1])), 10);
}
int main(){
    memset(dp, 31, sizeof(dp));
    int T;
    read(T);
    while(T --) solve();
}