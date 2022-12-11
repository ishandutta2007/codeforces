#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int &y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-=mod:x;}
int T,n,m;
vector<int>E[110];
int C[110][110];
int cnt[110][110],tot,dp[110];
void getdis(int x,int fa,int dis)
{
	++cnt[tot][dis];
	for(auto y:E[x])
	{
		if(y==fa)continue;
		getdis(y,x,dis+1);
	}
}
int main()
{
	C[0][0]=1;
	for(int i=1;i<=100;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=pl(C[i-1][j-1],C[i-1][j]);
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1,x,y;i<n;++i)
		{
			scanf("%d %d",&x,&y);
			E[x].emplace_back(y);
			E[y].emplace_back(x);
		}
		if(m==2)
		{
			printf("%d\n",n*(n-1)/2);
			for(int i=1;i<=n;++i)E[i].clear();
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(auto x:E[i])++tot,getdis(x,i,1);
			for(int j=1;j<=n;++j)//dis
			{
				int cnt1=0;
				for(int k=1;k<=tot;++k)cnt1+=cnt[k][j]!=0;
				if(cnt1<m)break;
				dp[0]=1;
				for(int k=1;k<=tot;++k)
					for(int l=k;l;--l)
						dp[l]=(dp[l]+1ll*dp[l-1]*cnt[k][j])%mod;
				add(ans,dp[m]);
				memset(dp,0,tot+1<<2);
			}
			for(int j=1;j<=tot;++j)memset(cnt[j]+1,0,n<<2);
			tot=0;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)E[i].clear();
	}
	return 0;
}