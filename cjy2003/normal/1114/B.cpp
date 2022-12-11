#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ys
{
	int va,id;
	friend bool operator < (const ys a,const ys b)
	{
		return a.va>b.va;
	}
}d[200020];
int n,m,k,sum,tot;
bool bj[200020];
long long ans;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&d[i].va),d[i].id=i;
	sort(d+1,d+1+n);
	for(int i=1;i<=m*k;++i)
		bj[d[i].id]=1,ans+=d[i].va;
	printf("%I64d\n",ans);
	tot=1;
	for(int i=1;i<=n;++i)
	{
		sum+=bj[i];
		if(sum==m&&tot<k)
		{
			printf("%d ",i);
			sum=0;++tot;
		}
	}
	return 0;
}