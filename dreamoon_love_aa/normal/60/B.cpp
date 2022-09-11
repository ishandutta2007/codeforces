#include<stdio.h>
char Map[16][16][16];
int k,n,m,an;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
void dfs(int x,int y,int z){
    if(x<0||y<0||z<0||x>=k||y>=n||z>=m)return;
    if(Map[x][y][z]=='#')return;
    Map[x][y][z]='#';
    an++;
    for(int i=0;i<6;i++)dfs(x+dx[i],y+dy[i],z+dz[i]);
}
main(){
    int x,y,i,j;
    scanf("%d%d%d",&k,&n,&m);
    for(i=0;i<k;i++){
        for(j=0;j<n;j++)
        scanf("%s",Map[i][j]);
    }
    scanf("%d%d",&x,&y);
    dfs(0,x-1,y-1);
    printf("%d\n",an);
}