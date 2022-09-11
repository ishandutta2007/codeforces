#include<stdio.h>
int a[100000];
main(){
    int n,sum=0,an=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int now=a[0];
    for(i=1;i<n;i++){
        if(now+now==sum)an++;
        now+=a[i];
    }
    printf("%d\n",an);
}