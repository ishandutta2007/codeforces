#include<cstdio>
long long a,l,mi=1e18;
int main(){
	scanf("%lld",&a);l=a-mi%a*9LL%a*9LL%a;
	printf("%lld %lld",l,l+mi-1);
	return 0;
}