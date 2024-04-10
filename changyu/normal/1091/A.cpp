#include<cstdio>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a+1<=b&&a+2<=c)return 0*printf("%d",a*3+3);
	if(b-1<=a&&b+1<=c)return 0*printf("%d",b*3);
	if(c-2<=a&&c-1<=b)return 0*printf("%d",c*3-3);
}