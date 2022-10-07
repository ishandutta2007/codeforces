#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=600005,M=998244353;
int n,m,i,j,a[N],s,t,u,d[N];
long long ans;
map<int,int> g[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d %d",&s,&t,&u);
		if(g[s][t])
		{
			ans+=min(d[g[s][t]],a[g[s][t]]);
			--d[g[s][t]];
			ans-=min(d[g[s][t]],a[g[s][t]]);
		}
		g[s][t]=u;
		ans+=min(d[u],a[u]);
		++d[u];
		ans-=min(d[u],a[u]);
		printf("%lld\n",ans);
	}
}