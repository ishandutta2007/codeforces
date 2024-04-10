#include<stdio.h>
long long int c2(long long int n){
    return (n*(n-1))/2;
}
int main(){
    long long int n,m,min,max;
    scanf("%I64d %I64d",&n,&m);
    max=c2(n-m+1);
    min=(m-(n%m))*c2(n/m)+(n%m)*c2(n/m+1);
    printf("%I64d %I64d",min,max);
}