#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long n,m,i,j,ans,x,vis[200005],cnt[500005],p[500005],q[500005],all;
vector<long long> num[200005];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		for (j=2;sqr(j)<=x;j++)
		{
			if (x%j==0)
			{
				num[i].push_back(j);
				while (x%j==0) x/=j;
			}
		}
		if (x>1) num[i].push_back(x);
		sort(num[i].begin(),num[i].end());
	}
	for (i=1;i<=500000;i++) p[i]=1;
	for (i=2;i<=500000;i++)
	{
		if (q[i]) continue;
		for (j=1;i*j<=500000;j++)
		{
			p[i*j]=-p[i*j];
			q[i*j]=1;
		}
	}
	while (m--)
	{
		scanf("%I64d",&x);
		if (!vis[x])
		{
			all++;
			for (i=1;i<(1<<num[x].size());i++)
			{
				long long t=1;
				for (j=0;j<num[x].size();j++) if ((i>>j)&1) t*=num[x][j];
				ans+=p[t]*cnt[t]*(cnt[t]-1)/2;
				cnt[t]++;
				ans-=p[t]*cnt[t]*(cnt[t]-1)/2;
			}
		}
		else
		{
			all--;
			for (i=1;i<(1<<num[x].size());i++)
			{
				long long t=1;
				for (j=0;j<num[x].size();j++) if ((i>>j)&1) t*=num[x][j];
				ans+=p[t]*cnt[t]*(cnt[t]-1)/2;
				cnt[t]--;
				ans-=p[t]*cnt[t]*(cnt[t]-1)/2;
			}
		}
		vis[x]^=1;
		printf("%I64d\n",(all*(all-1))/2-ans);
	}
	return 0;
}