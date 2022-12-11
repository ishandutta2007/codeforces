#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
struct bian
{
	int nxt,to,c1,c2;
}bi[200020];
int n,m,a[2],cnt,tag[100010],head[100010],num,st[100010],tp,d[100010],dp[100010][2][2],c[100010][2],s[100010][2],tot,cur[2],ans;
bool vis[100010],used[100010];
inline void addedge(int from,int to,int c1,int c2){bi[++num]=bian{head[from],to,c1,c2};head[from]=num;++d[to];}
int main()
{
	scanf("%d %d",&n,&m);
	memset(tag,-1,sizeof(tag));
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;++j)scanf("%d",&a[j]);
		if(k==1)a[1]=a[0];
		if(abs(a[0])==abs(a[1]))
		{
			if(a[0]==a[1])tag[abs(a[0])]=(a[0]>0);
			else ++cnt,vis[abs(a[0])]=1;
		}
		else
		{
			addedge(abs(a[0]),abs(a[1]),a[0]>0,a[1]>0);
			addedge(abs(a[1]),abs(a[0]),a[1]>0,a[0]>0);
		}
	}
	int x;
	s[0][0]=1;
	for(int i=1;i<=m;++i)
		if(d[i]<=1&&!vis[i])
		{
			vis[i]=1;
			tp=0,st[++tp]=i;
			while(1)
			{
				x=st[tp];
				bool flag=0;
				for(int j=head[x];j;j=bi[j].nxt)
					if(!vis[bi[j].to]&&!used[(j+1)/2])used[(j+1)/2]=1,flag=1,vis[bi[j].to]=1,c[tp][0]=bi[j].c1,c[tp][1]=bi[j].c2,st[++tp]=bi[j].to;
				if(!flag)break;
			}
			dp[1][0][0]=dp[1][0][1]=dp[1][1][0]=dp[1][1][1]=0;
			dp[1][0][tag[st[1]]==0]=dp[1][1][tag[st[1]]==1]=1;
			for(int j=2;j<=tp;++j)
			{
				dp[j][0][0]=dp[j][0][1]=dp[j][1][0]=dp[j][1][1]=0;
				for(int t=0;t<=1;++t)
					for(int k=0;k<=1;++k)
						for(int l=0;l<=1;++l)
							add(dp[j][l][t^(k==c[j-1][0]||l==c[j-1][1])^(l==tag[st[j]])],dp[j-1][k][t]);
			}
			++tot;
			for(int j=0;j<=1;++j)
				for(int k=0;k<=1;++k)
					s[tot][j^k]=(s[tot][j^k]+1ll*s[tot-1][j]*(dp[tp][0][k]+dp[tp][1][k]))%mod;
		}
	for(int i=1;i<=m;++i)
		if(!vis[i])
		{
			st[tp=1]=i;
			while(1)
			{
				x=st[tp];
				bool flag=0;
				for(int j=head[x];j;j=bi[j].nxt)
					if(!vis[bi[j].to]&&!used[(j+1)/2])
					{
						used[(j+1)/2]=1,flag=1,vis[bi[j].to]=1,c[tp][0]=bi[j].c1,c[tp][1]=bi[j].c2,st[++tp]=bi[j].to;
						break;
					}
				if(!flag)break;
			}
		//	for(int j=1;j<=tp;++j)printf("%d ",st[j]);printf("\n");
			dp[1][0][0]=dp[1][0][1]=dp[1][1][0]=dp[1][1][1]=0;
			dp[1][0][0]=1;
			for(int j=2;j<=tp;++j)
			{
				dp[j][0][0]=dp[j][0][1]=dp[j][1][0]=dp[j][1][1]=0;
				for(int t=0;t<=1;++t)
					for(int k=0;k<=1;++k)
						for(int l=0;l<=1;++l)
							add(dp[j][l][t^(k==c[j-1][0]||l==c[j-1][1])],dp[j-1][k][t]);
		//		for(int k=0;k<=1;++k)
		//			for(int t=0;t<=1;++t)printf("%d %d %d\n",k,t,dp[j][k][t]);
		//		printf("\n");
			}
			cur[0]=dp[tp][0][0];
			cur[1]=dp[tp][0][1];
			dp[1][0][0]=dp[1][0][1]=dp[1][1][0]=dp[1][1][1]=0;
			dp[1][1][0]=1;
			for(int j=2;j<=tp;++j)
			{
				dp[j][0][0]=dp[j][0][1]=dp[j][1][0]=dp[j][1][1]=0;
				for(int t=0;t<=1;++t)
					for(int k=0;k<=1;++k)
						for(int l=0;l<=1;++l)
							add(dp[j][l][t^(k==c[j-1][0]||l==c[j-1][1])],dp[j-1][k][t]);
			}
			add(cur[0],dp[tp][1][0]);
			add(cur[1],dp[tp][1][1]);
		//	printf("%d %d\n",cur[0],cur[1]);
			++tot;
			for(int j=0;j<=1;++j)
				for(int k=0;k<=1;++k)
					s[tot][j^k]=(s[tot][j^k]+1ll*s[tot-1][j]*cur[k])%mod;
		}
	int ans=s[tot][!(cnt&1)];
	while(cnt)add(ans,ans),--cnt;
	printf("%d",ans);
	return 0;
}