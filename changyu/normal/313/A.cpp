#include<cstdio>
int a,b,c;
int main(){
	scanf("%d",&a);
	if(a>0)return 0*printf("%d",a);
	b=a/10;
	c=a/100*100/10+a%10;
	printf("%d",(a>b?a:b)>c?(a>b?a:b):c);
	return 0;
}