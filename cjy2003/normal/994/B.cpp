#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,dl[11],mini;
long long ans[100001];
struct knight
{
	int num;
	int pow;
	int mon;
}x[100001];
bool cmp(knight a,knight b)
{
	return a.pow<b.pow;
}
int main()
{
	dl[0]=0x7fffffff;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i].pow);
	for(int i=1;i<=n;i++)
	{
		x[i].num=i;
		scanf("%d",&x[i].mon);	
	}
	sort(x+1,x+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		ans[x[i].num]=x[i].mon;
		for(int j=1;j<=k;j++)
			ans[x[i].num]+=dl[j];
		if(i<=k)dl[i]=x[i].mon;
		else
		{
			mini=0;
			for(int j=1;j<=k;j++)
				if(dl[j]<dl[mini])mini=j;
			if(dl[mini]<x[i].mon)dl[mini]=x[i].mon;	
		}
	}
	for(int i=1;i<=n;i++)
	printf("%I64d ",ans[i]);
	return 0;
}