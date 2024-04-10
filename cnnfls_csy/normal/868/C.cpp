#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt[16],sum[4],n,m,x,sz,i,j,k;
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		int mask=0;
		for (j=0;j<m;j++)
		{
			scanf("%d",&x);
			mask|=((1<<j)*x);
		}
		cnt[mask]=1;
	}
	for (i=1;i<(1<<(1<<m));i++)
	{
		sz=0;
		bool ok=1;
		memset(sum,0,sizeof(sum));
		for (j=0;j<(1<<m);j++)
		{
			if (!((1<<j)&i)) continue;
			if (!cnt[j]){ok=0;break;}
			for (k=0;k<m;k++)
			{
				if ((1<<k)&j) sum[k]++;
			}
			sz++;
		}
		for (int j=0;j<4;j++)
		{
			if (sum[j]*2>sz) ok=0;
		}
		if (ok)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}