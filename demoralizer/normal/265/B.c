#include <stdio.h>
int mod(int a){
	return a>0?a:-a;
}
int main()
{
	int n,s,t,a;
	scanf("%d %d",&n,&s);
	a=2*n-1+s;
	for(int i=1;i<n;i++){
		scanf("%d",&t);
		a+=mod(t-s);
		s=t;
	}
	printf("%d",a);
}