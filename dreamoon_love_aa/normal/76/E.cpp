#include<stdio.h>
main(){
    int n,i,x,y;
    long long a,b,c,d;
    a=b=c=d=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a+=x*x;
        b+=x;
        c+=y*y;
        d+=y;
    }
    printf("%I64d\n",n*(a+c)-b*b-d*d);
}