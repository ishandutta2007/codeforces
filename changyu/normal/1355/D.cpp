#include<cstdio>
int n,s;
int main(){
	scanf("%d%d",&n,&s);
	if(n+n>s)return 0*puts("NO");
	puts("YES");
	for(int i=1;i<n;i++)printf("2 ");
	printf("%d\n1\n",s-2*n+2);
	return 0;
}