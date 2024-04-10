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

int n, m;
const int zero = 1015;
int pre[1005][2505];
/*
0 -> no answer
1 -> it choose L
2 -> it choose D
3 -> it choose W 
*/
char s[1005];

void dfs(int x, int k){//predfsdfs i  k pre i  k
    // printf("x = %d, k = %d, pre[x][k] = %d, s[x] = %c\n", x, k - zero, pre[x][k], s[x]);
    if(x > n) return ;
    if(s[x] == 'D'){
        if(pre[x][k]) return ;
        if((x ^ n) && (k >= zero + m || k <= zero - m)) return ;
        pre[x][k] = 2;
        dfs(x + 1, k);
        return ;
    }
    if(s[x] == 'W'){
        k ++;
        if(pre[x][k]) return ;
        if((x ^ n) && (k >= zero + m || k <= zero - m)) return ;
        pre[x][k] = 3;
        dfs(x + 1, k);
        return ;
    }
    if(s[x] == 'L'){
        k --;
        if(pre[x][k]) return ;
        if((x ^ n) && (k >= zero + m || k <= zero - m)) return ;
        pre[x][k] = 1;
        dfs(x + 1, k);
        return;
    }
    s[x] = 'D';dfs(x, k);
    s[x] = 'W';dfs(x, k);
    s[x] = 'L';dfs(x, k);
    s[x] = '?';
}

void output(int x, int k){
    if(x < 1) return ;
    if(pre[x][k] == 1){
        output(x - 1, k + 1);
        putchar('L');
    }
    if(pre[x][k] == 2){
        output(x - 1, k);
        putchar('D');
    }
    if(pre[x][k] == 3){
        output(x - 1, k - 1);
        putchar('W');
    }
}


int main(){
    read(n);read(m);
    scanf("%s", s + 1);
    dfs(1, zero);
    if(pre[n][zero - m]) {output(n, zero - m);return 0;}
    if(pre[n][zero + m]) {output(n, zero + m);return 0;} 
    printf("NO\n");
    return 0;
};