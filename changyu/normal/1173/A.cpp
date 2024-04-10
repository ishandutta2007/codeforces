#include<cstdio>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a-b-c>0)return 0*puts("+");
	if(b-a-c>0)return 0*puts("-");
	if(a==b&&!c)return 0*puts("0");
	return 0*puts("?");
}