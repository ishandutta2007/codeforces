#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int q,n,a[300030],id[300030],idnum,last[300030],dp[300030];
long long ans;
map<int,int>mp[300030];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		ans=0;
		memset(last+1,-1,n<<2);
		for(int i=1;i<=n;++i)
		{
			if(a[i]==a[i-1])
			{
				last[i]=i-2;
				if(id[i-2])id[i]=id[i-2];
				else id[i]=++idnum;
				mp[id[i]][a[i-2]]=i-2;
			}
			else if(mp[id[i-1]].count(a[i]))last[i]=mp[id[i-1]][a[i]]-1,id[i]=id[last[i]]?id[last[i]]:++idnum,mp[id[i]][a[last[i]]]=last[i];
			if(~last[i])dp[i]=dp[last[i]]+1,ans+=dp[i];
		//	printf("%d %d %d\n",last[i],dp[i],id[i]);
		}
		printf("%lld\n",ans);
		memset(dp+1,0,n<<2);
		memset(id+1,0,n<<2);
		for(int i=1;i<=idnum;++i)mp[i].clear();idnum=0;
	}
	return 0;
}