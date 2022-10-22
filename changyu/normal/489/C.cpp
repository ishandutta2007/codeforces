#include<cstdio>
int n,m,t,r[101],k;
int main(){
	scanf("%d%d",&n,&m);
	if(m>n*9)return 0*puts("-1 -1");
	if(n==1)return 0*printf("%d %d",m,m);
	if(!m)return 0*puts("-1 -1");
	printf("%d",t=m>9*n-8?m-9*n+9:1);
	t=m-t;
	for(int i=1;i<n;i++)
	  r[k++]=t<9?t:9,t-=t<9?t:9;
	for(;k--;)printf("%d",r[k]);
	putchar(32);
	for(int i=1;i<=n;i++)printf("%d",m<9?m:9),m-=m<9?m:9;
	return 0;
}