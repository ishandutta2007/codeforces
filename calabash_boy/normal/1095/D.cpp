#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int nxt[maxn][2];
int n;
int p[maxn];
bool check(int x,int y){
    return nxt[x][0] == y || nxt[x][1] == y;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%d%d",&nxt[i][0],&nxt[i][1]);
    }
    if (n == 3){
        puts("1 2 3");
        return 0;
    }
    for (int i=1;i<=n;i++){
        int x = nxt[i][0];
        int y = nxt[i][1];
        if (check(x,y))p[i] = x;
        else p[i] = y;
    }
    int now = 1;
    for (int i=1;i<=n;i++){
        printf("%d ",p[now]);
        now = p[now];
    }
    puts("");
    return  0;
}