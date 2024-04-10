#include<iostream>
#include<cstdio>

using namespace std;

const int Maxn=2e3+10,M=1e9+7;

int n,m,ans,vis[Maxn],tot,nex[Maxn<<2],head[Maxn],vet[Maxn<<2],dp1[Maxn][Maxn<<2],dp2[Maxn][Maxn<<2],sum2[Maxn][Maxn<<2],sum,a[Maxn],cnt;

void add(int u,int v){
	nex[++tot]=head[u];
	head[u]=tot;
	vet[tot]=v;
}

void dfs(int u,int pre,int siz){
	vis[u]=1;
	for (int i=head[u];i;i=nex[i])
		if (i!=(pre^1)){
			int v=vet[i];
			if (v==1) a[++cnt]=siz;
			else if (!vis[v]) dfs(v,i,siz+1);
		}
}

int mo1(int x){
	return (x>=M)?x-M:x;
}

int mo2(int x){
	return (x<0)?x+M:x;
}

int main(){
	scanf("%d%d",&n,&m);
	tot=1;
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	dp1[0][m]=1;
	sum=0;
	for (int i=1;i<=cnt;i++){
		for (int j=m-sum;j<=m+sum;j++){
			dp1[i][j-a[i]]=mo1(dp1[i][j-a[i]]+dp1[i-1][j]);
			dp1[i][j]=mo1(dp1[i][j]+dp1[i-1][j]);
			dp1[i][j+a[i]]=mo1(dp1[i][j+a[i]]+dp1[i-1][j]);
		}
		sum+=a[i];
	}
	dp2[cnt+1][m]=1;
	for (int i=0;i<=m+m;i++)
		sum2[cnt+1][i]=mo1(sum2[cnt+1][i-1]+dp2[cnt+1][i]);
	sum=0;
	for (int i=cnt;i;i--){
		for (int j=m-sum;j<=m+sum;j++){
			dp2[i][j-a[i]]=mo1(dp2[i][j-a[i]]+dp2[i+1][j]);
			dp2[i][j]=mo1(dp2[i][j]+dp2[i+1][j]);
			dp2[i][j+a[i]]=mo1(dp2[i][j+a[i]]+dp2[i+1][j]);
		}
		for (int j=0;j<=m+m;j++)
			sum2[i][j]=mo1(sum2[i][j-1]+dp2[i][j]);
		sum+=a[i];
	}
	ans=0;
	for (int i=1;i<=cnt;i++){
		for (int j=0;j<=m+m;j++)
			if (dp1[i-1][j])
				ans=mo2((ans+1ll*dp1[i-1][j]*(sum2[i+1][m+m+a[i]-2-j]-sum2[i+1][m+m-a[i]+1-j])*2)%M);
//		cout<<ans<<endl;
	}
	for (int i=1;i<=cnt;i++)
		for (int j=0;j<=m+m;j++)
			dp1[i][j]=dp2[i][j]=0;
	dp1[0][m]=1;
	sum=0;
	for (int i=1;i<=cnt;i++){
		for (int j=m-sum;j<=m+sum;j++){
			dp1[i][j-a[i]]=mo1(dp1[i][j-a[i]]+dp1[i-1][j]);
			dp1[i][j+a[i]]=mo1(dp1[i][j+a[i]]+dp1[i-1][j]);
		}
		sum+=a[i];
	}
	dp2[cnt+1][m]=1;
	sum=0;
	for (int i=cnt;i;i--){
		for (int j=m-sum;j<=m+sum;j++){
			dp2[i][j-a[i]]=mo1(dp2[i][j-a[i]]+dp2[i+1][j]);
			dp2[i][j+a[i]]=mo1(dp2[i][j+a[i]]+dp2[i+1][j]);
		}
		sum+=a[i];
	}
	for (int i=1;i<=cnt;i++){
		for (int j=0;j<=m+m;j++)
			if (dp1[i-1][j])
				ans=(ans+1ll*dp1[i-1][j]*(dp2[i+1][m+m+a[i]-1-j]+dp2[i+1][m+m-a[i]+1-j])*2)%M;
	}
	ans=mo1(ans+dp1[cnt][m]);
	printf("%d\n",ans);
	return 0;
}