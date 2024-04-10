#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 500
int n,a[MN+5];
long long ans=1LL<<60;
void cal(int x)
{
	if(!x)return;
	long long sum=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]%x==0||(a[i]/x>=x-1-a[i]%x))sum+=a[i]/x+bool(a[i]%x);
		else return;
	}
	ans=min(ans,sum);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i*i<=a[1];++i)cal(i),cal(a[1]/i),cal(a[1]/i-1),cal(a[1]/i+1);
	printf("%I64d",ans);
}