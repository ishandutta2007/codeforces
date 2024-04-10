#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N][N],dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={1,-1,2,-2,2,-2,1,-1};
bool can(int x,int y){return x>=1&&x<=n&&y>=1&&y<=n;}
void dfs(int x,int y){
    for(int i=0;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(can(xx,yy)&&!a[xx][yy])a[xx][yy]=3-a[x][y],dfs(xx,yy);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!a[i][j])a[i][j]=1,dfs(i,j);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)putchar(a[i][j]==1?'W':'B');
        puts("");
    }
    return 0;
}