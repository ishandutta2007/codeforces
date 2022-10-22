#include<cstdio>
int m,a,s;
int main(){
	scanf("%d%d",&m,&a);
	int i=1;
	for(;i*i<a;i++)if(a%i==0&&i<=m&&a/i<=m)s+=2;
	if(i*i==a&&i<=m)s++;
	printf("%d\n",s);
	return 0;
}