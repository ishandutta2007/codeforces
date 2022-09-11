#include<stdio.h>
int a[100010],d[100010];
main(){
    int n,ma=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        d[a[i]]++;
        if(a[i]>ma)ma=a[i];
    }
    for(i=1;i<ma;i++)
        if(d[i]<d[i+1])break;
    if(i<ma)puts("-1");
    else{
        printf("%d\n",d[1]);
        for(i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%d",d[a[i]]--);
        }
        puts("");
    }
}