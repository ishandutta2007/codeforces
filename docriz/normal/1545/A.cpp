#include<bits/stdc++.h>
using namespace std;
int sum[100005],tr[100005],n,T,a[100005],st[100005],tp;
vector<int>xq[100005];
int lowbit(int p){return p&-p;}
int ask(int p)
{
	int ans=0;
	while(p)
	{
		ans+=tr[p];
		p-=lowbit(p);
	}
	return ans;
}
void modify(int p,int v)
{
	while(p<=100000)
	{
		tr[p]+=v;
		p+=lowbit(p);
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int ok=0;
		for(int i=1;i<=100000;i++)tr[i]=sum[i]=0,xq[i].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=n;i;i--)
		{
			sum[i]+=ask(a[i]-1);
			//printf("%d\n",sum[i]);
			modify(a[i],1);
		}
		for(int i=1;i<=100000;i++)tr[i]=0;
		for(int i=1;i<=n;i++)
		{
			sum[i]+=i-1-ask(a[i]);
			//printf("%d\n",sum[i]);
			modify(a[i],1);
		}
		for(int i=1;i<=n;i++)
		{
			if(sum[i]%2)xq[a[i]].push_back(1);
			else xq[a[i]].push_back(0);
		}
		for(int i=1;i<=100000;i++)
		{
			tp=0;
			for(int j=0;j<xq[i].size();j++)
			{
				if(tp&&st[tp]==xq[i][j])tp--;
				else st[++tp]=xq[i][j];
			}
			if(tp>1||(tp&&st[tp]==1))ok=1;
		}
		if(ok)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}