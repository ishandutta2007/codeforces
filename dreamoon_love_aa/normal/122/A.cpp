#include<stdio.h>
int a[16]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<14;i++)
        if(n%a[i]==0)break;
    if(i<14)puts("YES");
    else puts("NO");
}