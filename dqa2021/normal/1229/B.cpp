#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;

int n; ll w[100010];
ll gcd(ll x,ll y)
{
	return y?gcd(y,x%y):x;
}
int ans;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
ll bin[100010][60];
int sum[100010][60];
int tot[100010];
void dfs(int cur,int fat,int dep)
{
	for (int i=1;i<=tot[cur];i++)
	{
		bin[cur][i]=gcd(bin[cur][i],w[cur]);
	}
	bin[cur][++tot[cur]]=w[cur]; sum[cur][tot[cur]]=dep;
	
	int tmp=0;
	for (int i=1;i<=tot[cur];i++)
	{
		if (i==1||bin[cur][i]!=bin[cur][i-1])
		{
			bin[cur][++tmp]=bin[cur][i];
			sum[cur][tmp]=sum[cur][i];
		}
		else
		{
			sum[cur][tmp]=sum[cur][i];
		}
	}
	tot[cur]=tmp;
	
	//printf("dfs %d %d %d\n",cur,fat,dep);
	//for (int i=1;i<=tot[cur];i++) printf("%I64d %d\n",bin[cur][i],sum[cur][i]);
	
	for (int i=1;i<=tot[cur];i++) ans=(ans+bin[cur][i]%Mod*(sum[cur][i]-sum[cur][i-1]))%Mod;
	
	for (int i=last[cur];i;i=edge[i].nxt)
	{
		if (edge[i].to==fat) continue;
		tot[edge[i].to]=tot[cur];
		for (int j=1;j<=tot[cur];j++) bin[edge[i].to][j]=bin[cur][j],sum[edge[i].to][j]=sum[cur][j];
		dfs(edge[i].to,cur,dep+1);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",w+i);
	for (int i=2,x,y;i<=n;i++) scanf("%d%d",&x,&y),addedge(x,y);
	dfs(1,0,1);
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}