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
int ans[1005][1005];

void work(int x){
    if(x == 1) {ans[1][1] = 0;return ;}
    if(x == 3) {
        ans[1][2] = ans[2][3] = ans[3][1] = 1;
        return ;
    }
    for (register int i = 1;i <= x - 2;i ++){
        ans[i][x] = 1;
        ans[x - 1][i] = 1;
    }
    ans[x][x - 1] = 1;
    work(x - 2);
}

void solve(int x){
    if(x == 6){
        ans[1][2] = ans[1][3] = ans[1][4] = ans[2][3] = ans[2][4] = ans[2][5] = ans[3][4] = ans[3][6] = ans[4][5] = ans[4][6] = ans[5][1] = ans[5][3] = ans[5][6] = ans[6][1] = ans[6][2] = 1;
        return ;
    }
    for (register int i = 1;i <= x - 2;i ++){
        ans[i][x] = 1;
        ans[x - 1][i] = 1;
    }
    ans[x][x - 1] = 1;
    solve(x - 2);
}

int main(){
    read(n);
    if(n <= 4 && !(n & 1)) return printf("-1\n"), 0;
    if(n == 1) return printf("0\n"), 0;
    if(n == 3) return printf("0 1 0\n0 0 1\n1 0 0\n"), 0;
    if(n & 1) work(n);
    else solve(n);
    for (register int i = 1;i <= n;i ++){
        for (register int j = 1;j <= n;j ++){
            fprint(ans[i][j], 32);
        }
        putchar(10);
    }
    return 0;
}