#include<stdio.h>
int d[6][6];
int main(){
    int m,i,j,k,x,y;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        d[x][y]=d[y][x]=1;
    }
    for(i=1;i<=5;i++)
        for(j=i+1;j<=5;j++)
            for(k=j+1;k<=5;k++){
                if(d[i][j]==d[i][k]&&d[i][j]==d[j][k]){
                    puts("WIN");
                    return 0;
                }
            }
    puts("FAIL");
    return 0;
}