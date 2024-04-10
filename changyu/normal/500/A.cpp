#include<cstdio>
int n,m,a[30001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)scanf("%d",a+i);
	a[n]=1;
	for(int i=1;i<=n;i+=a[i])
	  if(i==m)return 0*puts("YES");
	return 0*puts("NO");
}