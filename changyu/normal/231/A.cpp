#include<cstdio>
int n,a,b,c,s;
int main(){
	scanf("%d",&n);
	while(n--)
	  scanf("%d%d%d",&a,&b,&c),s+=a+b+c>1;
	printf("%d",s);
	return 0;
}