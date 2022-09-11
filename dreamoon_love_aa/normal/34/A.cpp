#include<stdio.h>
int a[110],n,mi,an1,an2,i;
int abs(int x){return x<0?-x:x;}
main(){
    mi=100000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    a[n]=a[0];
    for(i=0;i<n;i++){
        if(mi>abs(a[i]-a[i+1])){
            mi=abs(a[i]-a[i+1]);
            an1=i+1;
            if(i+1==n)an2=1;
            else an2=i+2;
        }
    }
    printf("%d %d\n",an1,an2);
}