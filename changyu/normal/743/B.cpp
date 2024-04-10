#include<cstdio>
long long a;
int main(){
	scanf("%I64d%I64d",&a,&a);
	printf("%d",64-__builtin_clzll(a&-a));
	return 0;
}