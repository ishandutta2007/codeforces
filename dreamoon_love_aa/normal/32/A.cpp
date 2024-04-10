#include<stdio.h>
int abs(int x){return x<0?-x:x;}
main(){
    int d[1010],i,n,j,y,an=0;
    scanf("%d%d",&n,&y);
    for(i=0;i<n;i++)scanf("%d",&d[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(abs(d[i]-d[j])<=y)an++;
        }
    printf("%d\n",an);
}