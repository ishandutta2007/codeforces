#include<cstdio>
int a[50],n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	while(a[m]==a[m-1])m++;
	while(a[m-1]<=0&&m)m--;
	printf("%d\n",m);
	return 0;
}