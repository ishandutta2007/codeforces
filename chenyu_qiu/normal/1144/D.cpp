#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+7;
int num[maxn];
int ti[maxn]={0};
int d[maxn]={0};
struct node
{
	int num;
	int l;
	int r;
};
node ans[maxn];
int main()
{
	int n;
	int maxs=-1;
	int tar;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		ti[num[i]]++;
		if(ti[num[i]]>maxs)
		{
			maxs=ti[num[i]];
			tar=i;//
		}
	}
	int c=0;
	for(int i=tar+1;i<=n;i++)//
	{
		if(num[i]>num[i-1])
		{
			ans[c].num=2;
			ans[c].l=i;
			ans[c].r=i-1;
			c++;
		}
		else if(num[i]<num[i-1])
		{
			ans[c].num=1;
			ans[c].l=i;
			ans[c].r=i-1;
			c++;
		}
		num[i]=num[tar];
	}
	for(int i=tar-1;i>=1;i--)//
	{
		if(num[i]<num[i+1])
		{
			ans[c].num=1;
			ans[c].r=i+1;
			ans[c].l=i;
			c++;
		}
		else if(num[i]>num[i+1])
		{
			ans[c].num=2;
			ans[c].r=i+1;
			ans[c].l=i;
			c++;
		}
		num[i]=num[tar];
	}
	printf("%d\n",c);
	for(int i=0;i<c;i++)
	{
		printf("%d %d %d\n",ans[i].num,ans[i].l,ans[i].r);
	}
	return 0;
}