#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>up[100010];
int n,m,in[100010],out[100010],q;
long long ans;
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		if(x>y)swap(x,y);
		up[x].push_back(y);
		++out[x],++in[y];
	}
	for(int i=1;i<=n;++i)ans+=1ll*in[i]*out[i];
	printf("%lld\n",ans);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		ans-=1ll*in[x]*out[x];
		in[x]+=out[x];out[x]=0;
		for(auto p:up[x])
		{
			ans+=in[p]-out[p]-1;
			--in[p],++out[p];
			up[p].push_back(x);
		}
		up[x].clear();
		printf("%lld\n",ans);
	}
	return 0;
}