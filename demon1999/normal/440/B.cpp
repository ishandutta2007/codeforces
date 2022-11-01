#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
long long int a[50002],s=0,ko=0,k=0;
long int i,j,n;
using namespace std;
int main(){
scanf("%ld",&n);
for(i=1;i<=n;i++){
    scanf("%I64d",&a[i]);s+=a[i];
}
s=s/n;
for(i=1;i<=n;i++){
    k=k+s-a[i];
    ko+=abs(k);}
printf("%I64d",ko);                      
return 0;
}