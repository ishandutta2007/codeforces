#pragma GCC optimize(2, 3, "Ofast")
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
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int dp[5005][5005];
vector <int> v[5005];
int lst[5005], c[5005], a[5005], b[5005];
int n, m, k;

int main(){
    read(n);read(m);read(k);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);read(b[i]);read(c[i]);
        for (register int j = 0;j <= 5000;j ++){
            dp[i][j] = -0x3f3f3f3f;
        }
        lst[i] = i;
    }
    while(m --){
        int x, y;read(x);read(y);
        chmax(lst[y], x);
    }
    for (register int i = 1;i <= n;i ++) v[lst[i]].push_back(c[i]);
    for (register int i = 1;i <= n;i ++) sort(v[i].begin(), v[i].end());
    for (register int i = 1;i <= n;i ++){
        if(k < a[i]){
            fprint(-1, 10);
            return 0;
        }
        for (register int j = a[i];j <= k;j ++){
            dp[i][j + b[i]] = dp[i - 1][j];
        }
        int cnt = 0;
        k += b[i];
        while(!v[i].empty()){
            cnt ++;
            for (register int j = mx(0, a[i] + b[i] - cnt);j + cnt <= k;j ++){
                chmax(dp[i][j], dp[i][j + 1] + v[i].back());
                // printf("i = %d, j = %d, dp[i][j] = %d, v[i].back() = %d\n", i, j, dp[i][j], v[i].back());
            }
            v[i].pop_back();
        }
        
    }
    int ans = -0x3f3f3f3f;
    for (register int i = 0;i <= k;i ++) chmax(ans, dp[n][i]);
    fprint(ans, 10);
    return 0;
}