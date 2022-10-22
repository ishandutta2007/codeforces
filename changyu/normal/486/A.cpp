#include<cstdio>
long long n;int main(){scanf("%I64d",&n);printf("%I64d",(n+1)/2*((~(n&1))*2+3));return 0;}