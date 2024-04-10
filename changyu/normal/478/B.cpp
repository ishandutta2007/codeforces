#include<cstdio>
int n,m; 
int main(){
	scanf("%d%d",&n,&m);
	printf("%I64d %I64d",1ll*(n/m+1)*(n/m)/2*(n%m)+1ll*(n/m)*(n/m-1)/2*(m-n%m),1ll*(n-m+1)*(n-m)/2);
	return 0;
}