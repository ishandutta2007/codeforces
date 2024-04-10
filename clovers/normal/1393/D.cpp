#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=2005;
int dx[]={0,0};
int dy[]={1,-1};

char s[N][N];
int dp[N][N][2],n,m,vis[N][N];
long long ans=0;
int L[N][N],A[N][N];

void dfs(int x,int y,int dir)
{
	vis[x][y]=1; dp[x][y][dir]=1;
	int xx=x+dx[dir],yy=y+dy[dir];
	if(xx>n||yy>m||xx<1||yy<1) return;
	if(s[xx][yy]!=s[x][y]) return;
	dfs(xx,yy,dir); 
	dp[x][y][dir]=dp[xx][yy][dir]+1;
}

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=m;j++) if(!vis[i][j]) dfs(i,j,0);
		for(int j=1;j<=m;j++) vis[i][j]=0;
		for(int j=m;j>=1;j--) if(!vis[i][j]) dfs(i,j,1);
		for(int j=1;j<=m;j++) L[i][j]=min(dp[i][j][0],dp[i][j][1]),A[i][j]=L[i][j];
	}
	for(int j=1;j<=m;j++)
	{
		int mi=inf,up=1;
		for(int i=1;i<=n;i++) 
		{
			mi=min(mi,n-i+L[i][j]);
			A[i][j]=min(A[i][j],mi-(n-i));
			A[i][j]=min(A[i][j],up);
			if(s[i+1][j]!=s[i][j]) mi=inf,up=1;
			else up++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int mi=inf,down=1;
		for(int i=n;i>=1;i--)
		{
			mi=min(i+L[i][j],mi);
			A[i][j]=min(A[i][j],mi-i);
			A[i][j]=min(A[i][j],down);
			if(s[i-1][j]!=s[i][j]) mi=inf,down=1;
			else down++;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ans+=A[i][j];
	cout<<ans<<endl;
	return 0;
}