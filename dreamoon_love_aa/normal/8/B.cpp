#include<stdio.h>
bool a[138][128];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
main(){
    int i,j,x=64,y=64,lx,ly;
    char s[111];
    scanf("%s",s);
    lx=ly=0;
    for(i=0;s[i];i++){
        a[x][y]=1;
        lx=x;
        ly=y;
        if(s[i]=='L')x--;
        else if(s[i]=='R')x++;
        else if(s[i]=='U')y++;
        else y--;
        if(a[x][y])break;
        for(j=0;j<4;j++)
            if(a[x+dx[j]][y+dy[j]]&&(x+dx[j]!=lx||y+dy[j]!=ly))break;
        if(j<4)break;
    }
    if(s[i])puts("BUG");
    else puts("OK");
}