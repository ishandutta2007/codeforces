//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a,ans,depth[6400005],lson[6400005],rson[6400005],fa[6400005],cnt,tmp;
void build(int a,int now)
{
	if(depth[now]<0)
	{
		return;
	}
	if(a&(1ll<<depth[now]))
	{
		if(!rson[now])
		{
			depth[++cnt]=depth[now]-1;
			rson[now]=cnt;
			fa[cnt]=now;
		}
		build(a,rson[now]);
	}
	else
	{
		if(!lson[now])
		{
			depth[++cnt]=depth[now]-1;
			lson[now]=cnt;
			fa[cnt]=now;
		}
		build(a,lson[now]);
	}
}
void work(int l,int r,int v)
{
	if(tmp<=v)
	{
		return;
	}
	if(depth[l]<0)
	{
		tmp=v;
		return;
	}
	if(lson[l]&&lson[r])
	{
		work(lson[l],lson[r],v);
	}
	if(rson[l]&&rson[r])
	{
		work(rson[l],rson[r],v);
	}
	if(lson[l]&&rson[r])
	{
		work(lson[l],rson[r],v|(1ll<<depth[l]));
	}
	if(rson[l]&&lson[r])
	{
		work(rson[l],lson[r],v|(1ll<<depth[l]));
	}
}
void dfs(int now)
{
	if(lson[now]&&rson[now])
	{
		tmp=INF;
		work(lson[now],rson[now],1ll<<depth[now]);
		ans+=tmp;
//		cout<<now<<' '<<lson[now]<<' '<<rson[now]<<' '<<depth[now]<<' '<<tmp<<endl;
	}
	if(lson[now])
	{
		dfs(lson[now]);
	}
	if(rson[now])
	{
		dfs(rson[now]);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
//	freopen("1.in","r",stdin);
//	freopen("2.out","w",stdout);
	cin>>n;
	++cnt;
	depth[cnt]=31;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		build(a,1);
	}
//	for(int i=1;i<=cnt;++i)
//	{
//		cout<<i<<' '<<depth[i]<<' '<<lson[i]<<' '<<rson[i]<<endl;
//	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}