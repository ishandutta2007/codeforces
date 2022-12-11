#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 50
int a[MN+5],f[MN+5][2];
int main()
{
	int n,i,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i];
	for(i=n;i;--i)f[i][0]=max(f[i+1][0],f[i+1][1]+a[i]),f[i][1]=min(f[i+1][0],f[i+1][1]+a[i]);
	printf("%d %d",s-f[1][0],f[1][0]);
}