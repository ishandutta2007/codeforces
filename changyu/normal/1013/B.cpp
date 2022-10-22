#include<cstdio>
int n,m,b[100001],b1[100001],a[100001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
	  scanf("%d",i+a);
	  if(b[a[i]])return 0*puts("0");
	  b[a[i]]++;b1[a[i]&m]++;
	}
	for(int i=1;i<=n;i++)
	  if(b[a[i]&m]==1&&(a[i]&m)!=a[i]||b[a[i]&m]>1)return 0*puts("1");
	for(int i=0;i<=100000;i++)
	  if(b1[i]>=2)return 0*puts("2");
	return 0*puts("-1");
}