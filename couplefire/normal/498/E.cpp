#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
struct matrix
{
	int n,m;
	ll a[130][130];
};
matrix ways[10],cur,res;
bool vis[10];
ll dp[10][2];
int num;
vector<int> g[10];
ll dfs(int x,int n)
{
	vis[x]=1;
	dp[x][1]=1;
	if(x!=0&&x!=n)dp[x][0]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int to=g[x][i];
		if(vis[to])continue;
		dp[x][0]=dp[x][0]*dfs(to,n)%MOD;
		dp[x][1]=dp[x][1]*dp[to][0]%MOD;
	}
	return (dp[x][0]+dp[x][1])%MOD;
}
inline ll getways(int mask1,int mask2,int n)
{
	for(int i=0;i<=n;i++)
	{
		vis[i]=0;
		g[i].clear();
	}
	int mask=mask1&mask2;
	for(int i=0;i<n;i++)
		if(mask>>i&1)
		{
			g[i].emplace_back(i+1);
			g[i+1].emplace_back(i);
		}
	ll ans=1;
	for(int i=0;i<=n;i++)
		if(!vis[i])
		{
			ans=ans*1ll*dfs(i,n)%MOD;
		}
	return ans;
}
matrix mul(matrix A,matrix B)
{
	matrix C;
	C.n=A.n;
	C.m=B.m;
	for(int i=0;i<C.n;i++)for(int j=0;j<C.m;j++)
	{
		C.a[i][j]=0;
		for(int k=0;k<C.m;k++)
			C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%MOD)%MOD;
	}
	return C;
}
matrix quickpow(matrix Base,int ind)
{
	matrix ans;
	ans.n=Base.n;
	ans.m=Base.m;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=0;i<ans.n;i++)
		ans.a[i][i]=1;
	while(ind>0)
	{
		if(ind&1)ans=mul(ans,Base);
		ind>>=1;
		Base=mul(Base,Base);
	}
	return ans;
}
int main()
{
	for(int i=1;i<=7;i++)
	{
		ways[i].n=ways[i].m=1<<i;
		for(int mask1=0;mask1<(1<<i);mask1++)
		{
			for(int mask2=0;mask2<(1<<i);mask2++)
			{
				ways[i].a[mask1][mask2]=getways(mask1,mask2,i);
	//			cout<<i<<" "<<mask1<<" "<<mask2<<" "<<ways[mask1][mask2][i]<<endl;
			}
		}
	//	system("pause");
	}
	memset(res.a,0,sizeof(res.a));
	res.a[0][0]=1;
	int pre=0;
	for(int i=1;i<=7;i++)
	{
		scanf("%d",&num);
		if(!num)continue;
	//	num--;
		memset(cur.a,0,sizeof(cur.a));
		cur.n=1;
		cur.m=i;
		for(int msk=0;msk<(1<<pre);msk++)
		{
			int nmsk=msk;
			for(int j=pre;j<i;j++)
				nmsk|=(1<<j);
			cur.a[0][nmsk]=res.a[0][msk];
		//	cout<<msk<<" "<<nmsk<<" "<<cur.a[0][nmsk]<<endl;
		}
		res=mul(cur,quickpow(ways[i],num));
		pre=i;
		for(int msk=0;msk<(1<<i);msk++)
		{
		//	cout<<res.a[0][msk]<<endl;
		}
	}
	ll ans=res.a[0][(1<<pre)-1]%MOD;
	printf("%I64d\n",ans);
	return 0;
}