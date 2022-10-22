#include<cstdio>
#define min(a,b)((a)<(b)?(a):(b))
long long a,b,c;
int main(){
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d %I64d",(a+b)/c,a/c+b/c==(a+b)/c?0:min((c-a%c)%c,(c-b%c)%c));
	return 0;
}