#include<stdio.h>
int a[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int an[50];
main(){
    int i;
    for(i=0;i<15;i++)
        an[a[i]]=a[i+1];
    int n,m;
    scanf("%d%d",&n,&m);
    if(an[n]==m)puts("YES");
    else puts("NO");
}