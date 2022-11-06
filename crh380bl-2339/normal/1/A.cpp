#include<cstdio>
int main(){
	int a,n,m;
	scanf("%d%d%d",&n,&m,&a);
	n=(n+a-1)/a;
	m=(m+a-1)/a;
	printf("%lld\n",1LL*n*m);
	return 0;
}