#include<cstdio>
int a,b; 
int main(){
	scanf("%d%d",&a,&b);
	if(a==b)return 0*printf("%d00 %d01",a,b);
	if(a+1==b)return 0*printf("%d99 %d00",a,b);
	if(a==9&&b==1)return 0*printf("99 100");
	return 0*puts("-1");
}