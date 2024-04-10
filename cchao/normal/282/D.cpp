#include <cstdio>
#include <cstring>
int f[310][310];

int judge(int x, int y){
    if(f[x][y]>=0) return f[x][y];
    for(int i = 1; i <= x; ++i)
        if(judge(x-i,y)==0) return f[x][y] = 1;
    for(int i = 1; i <= y; ++i)
        if(judge(x,y-i)==0) return f[x][y] = 1;
    int m = x < y ? x : y;
    for(int i = 1; i <= m; ++i)
        if(judge(x-i,y-i)==0) return f[x][y] = 1;
    return f[x][y] = 0;
}
int main(){
    int n, a[3], winner=0, x=0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        x ^= a[i];
    }
    if(n!=2) winner = x?0:1;
    else{
        memset(f, -1, sizeof f);
        winner = judge(a[0], a[1])?0:1;
    }
    puts(winner?"BitAryo" : "BitLGM");
    return 0;
}