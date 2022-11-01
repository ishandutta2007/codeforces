#include<cstdio>
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",(a+b+c)/2);
	}
	return 0;
}