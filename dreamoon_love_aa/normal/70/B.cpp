#include<stdio.h>
#define SIZE 10010
char s[SIZE];
int d[SIZE],m;
main(){
    int n,i,j,an=0,now;
    scanf("%d",&n);
    gets(s);
    gets(s);
    for(i=0;s[i];i=j+1){
        while(s[i]==' ')i++;
        for(j=i;s[j]!='.'&&s[j]!='?'&&s[j]!='!';j++);
        d[m++]=j-i+1;
    }
    for(i=0;i<m;i=j){
        if(d[i]>n)break;
        an++;
        now=d[i];
        for(j=i+1;j<m&&now+d[j]+1<=n;j++)now+=d[j]+1;
    }
    if(i<m)puts("Impossible");
    else printf("%d\n",an);
}