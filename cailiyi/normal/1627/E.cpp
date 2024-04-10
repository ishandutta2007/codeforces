#include<bits/stdc++.h>
#define N 100000
const long long inf=8e18;
using namespace std;
int T,n,m,k,x[N+5];
struct ladder
{
	int b,c,d,h;
	long long val;
	inline bool operator<(const ladder &_b) const
	{
		return b<_b.b;
	}
};
vector<ladder> lad[N+5];
vector<pair<int,long long> > node[N+5]; 
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;++i) scanf("%d",x+i);
		for(int i=1;i<=n;++i) lad[i].clear(),node[i].clear();
		for(int i=1,a,b,c,d,h;i<=k;++i)
			scanf("%d %d %d %d %d",&a,&b,&c,&d,&h),lad[a].push_back({b,c,d,h});
		node[1].push_back({1,0});
		for(int a=1;a<n;++a)
		{
			if(lad[a].empty() || node[a].empty()) continue;
			sort(lad[a].begin(),lad[a].end());
			sort(node[a].begin(),node[a].end());
			for(unsigned i=0;i<lad[a].size();++i) lad[a][i].val=inf;
			long long minn=inf;
			for(unsigned i=0,j=0;i<lad[a].size();++i)
			{
				for(;j<node[a].size() && node[a][j].first<=lad[a][i].b;++j)
					minn=min(minn,node[a][j].second-1ll*node[a][j].first*x[a]);
				lad[a][i].val=min(lad[a][i].val,minn+1ll*lad[a][i].b*x[a]);
			}
			minn=inf;
			for(int i=lad[a].size()-1,j=node[a].size()-1;i>=0;--i)
			{
				for(;j>=0 && node[a][j].first>=lad[a][i].b;--j)
					minn=min(minn,node[a][j].second+1ll*node[a][j].first*x[a]);
				lad[a][i].val=min(lad[a][i].val,minn-1ll*lad[a][i].b*x[a]);
			}
			for(ladder x:lad[a]) if(x.val<inf)
				node[x.c].push_back({x.d,x.val-x.h});
		}
		long long ans=inf;
		for(pair<int,long long> no:node[n])
			ans=min(ans,no.second+1ll*x[n]*(m-no.first));
		if(ans==inf) puts("NO ESCAPE");
		else printf("%lld\n",ans);
	}
	return 0;
}