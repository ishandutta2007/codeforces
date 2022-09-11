#include<stdio.h>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
char Map[128][128];
bool Out(int x,int y){return x<0||x>=n||y<0||y>=m;}
bool used[128];
main(){
    int i,j,k,an=0;
    char c[8];
    scanf("%d%d%s",&n,&m,c);
    for(i=0;i<n;i++)scanf("%s",Map[i]);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(Map[i][j]==c[0]){
                for(k=0;k<4;k++){
                    if(Out(i+dx[k],j+dy[k]))continue;
                    if(Map[i+dx[k]][j+dy[k]]!='.'&&Map[i+dx[k]][j+dy[k]]!=c[0]){
                        if(!used[Map[i+dx[k]][j+dy[k]]]){
                            used[Map[i+dx[k]][j+dy[k]]]=1;
                            an++;
                        }
                    }
                }
            }
    printf("%d\n",an);
}