#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long rem[maxn];
long long cost[maxn];
long long ans[maxn];
int id[maxn];
bool cmp(int x,int y)
{
	if(cost[x]==cost[y]) return x<y;
	return cost[x]<cost[y];
}
int main()
{
	int n,m;
	long long all=0;
	int serve=1;
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {scanf("%lld",&rem[i]);all+=rem[i];id[i]=i;}
	for(int i=1;i<=n;i++) scanf("%lld",&cost[i]);
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		long long t,d;
		scanf("%lld%lld",&t,&d);
		if(all<d)
		{
			all=0;
			ans[i]=0;
			continue;
		}
		else if(rem[t]>=d)
		{
			ans[i]=cost[t]*d;
			all-=d;
			rem[t]-=d;
		}
		else {
			ans[i]+=rem[t]*cost[t];
			d-=rem[t];
			all-=rem[t];
			rem[t]=0;
			while(d)
			{
				if(!rem[id[serve]])
				{
					serve++;continue;
				}
				if(d<rem[id[serve]])
				{
					all-=d;
					rem[id[serve]]-=d;
					ans[i]+=d*cost[id[serve]];
					d=0;
				}
				else{
					all-=rem[id[serve]];
					d-=rem[id[serve]];
					ans[i]+=rem[id[serve]]*cost[id[serve]];
					rem[id[serve]]=0;
					serve++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);




}