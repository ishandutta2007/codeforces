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
int k[2], a[2][7005], cnt[2][7005];
bitset <7005> vis[2], win[2];

void dfs(int x, int t){
    if(vis[t][x]) return ;
    vis[t][x] = 1;
    for (register int i = 1;i <= k[t ^ 1];i ++){
        int tar = (x - a[t ^ 1][i] - 1 + n) % n + 1;
        if(tar == 1) continue;
        if(!win[t][x]){
            win[t ^ 1][tar] = 1;
            dfs(tar, t ^ 1);
        }
        else{
            if(k[t ^ 1] == ++ cnt[t ^ 1][tar]){
                dfs(tar, t ^ 1);
            }
        }
    }
}

int main(){
    read(n);
    for (register int i = 0;i <= 1;i ++){
        read(k[i]);
        for (register int j = 1;j <= k[i];j ++) read(a[i][j]);
    }
    dfs(1, 0);dfs(1, 1);
    for (register int i = 0;i <= 1;i ++){
        for (register int j = 2;j <= n;j ++){
            printf("%s ", vis[i][j]? (win[i][j]? "Win" : "Lose") : "Loop");
        }
        putchar(10);
    }
}