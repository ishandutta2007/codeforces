#include<cstdio>
long long k,n;int main(){scanf("%I64d%I64d",&n,&k);printf("%I64d",k<=(n+1)/2?2*k-1:(k-(n+1)/2)*2);return 0;}