#include<stdio.h>
int main(){
    long long int n,m,a=0,p=1,t;
    scanf("%I64d %I64d",&n,&m);
    while(m-->0){
        scanf("%I64d",&t);
        a+=t-p+(t<p)*n;
        p=t;
    }
    printf("%I64d",a);
}