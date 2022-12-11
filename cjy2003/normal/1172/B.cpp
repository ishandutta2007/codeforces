#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
struct bian
{
	int to,nxt;
}bi[400040];
int n,head[200020],num,jc[200020],ans;
void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void dfs(int v,int fa)
{
	int u;
	int cnt=0;
	for(int i=head[v];i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		++cnt;
		dfs(u,v);
	}
	if(v==1)ans=1ll*ans*jc[cnt]%mod;
	else ans=1ll*ans*jc[cnt+1]%mod;
}
int main()
{
	scanf("%d",&n);
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod;
	ans=1;
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	printf("%d",1ll*ans*n%mod);
	return 0;
}