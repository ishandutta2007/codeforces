#include <cstdio>
#include <iostream>
#include <cmath>
long int a[100010],n,i,j;
using namespace std;
int main(){
scanf("%ld",&n);
for(i=1;i<=n;i++)a[i]=0;
for(i=1;i<n;i++){
    scanf("%ld",&j);
    a[j]=1;
}
for(i=1;i<=n;i++)
   if(a[i]==0)printf("%ld",i);
return 0;
}