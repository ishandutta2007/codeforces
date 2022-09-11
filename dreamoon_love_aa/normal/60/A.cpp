#include<stdio.h>
#include<stdlib.h>
char s[99];
bool used[1010];
main(){
    int n,m,i,j,x;
    gets(s);
    sscanf(s,"%d%d",&n,&m);
    for(i=0;i<m;i++){
        gets(s);
        if(s[7]=='l'){
            x=atoi(s+15);
            for(j=x;j<=n;j++)used[j]=1;
        }
        else{
            x=atoi(s+16);
            for(j=1;j<=x;j++)used[j]=1;
        }
    }
    x=0;
    for(i=1;i<=n;i++)
        if(!used[i])x++;
    if(x==0)puts("-1");
    else printf("%d\n",x);
}