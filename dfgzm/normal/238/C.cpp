#include<bits/stdc++.h>
#define A(x) min(x[0],x[1])
using namespace std;
const int maxn=3010;
struct edge{
	int next,to,w;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y,int z){
	e[++len]={head[x],y,z};
	head[x]=len;
}int i,j,k,n,m,ci[maxn],w,x,ans,root,vis[maxn],can;
void dfs(int now,int fa){
	vis[now]=1;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		if(vis[u])ci[now]=1;
		else dfs(u,now);
		if(ci[u]==1)ci[now]=1;
		if(ci[now])++w,x+=e[i].w;
	}
}
int dp[maxn][5][2];
void dfs2(int now,int fa){
	dp[now][1][0]=0;
	int tmp[5][2];
//	cout<<"dfs2.. "<<now<<endl;
	for(int i=head[now];i;i=e[i].next){
		int u=e[i].to;
		if(u==fa)continue;
		dfs2(u,now);
//		cout<<now<<" -> "<<u<<endl;
		memset(tmp,0x2f,sizeof(tmp));
		if(e[i].w==1){
//			cout<<"1"<<endl;
			for(int j=0;j<=2;j++){
				for(int k=0;k<=j;k++){
					tmp[j][0]=min(tmp[j][0],dp[now][j-k][0]+min(dp[u][k+1][0],dp[u][k][1]));
					tmp[j][1]=min(tmp[j][1],min(dp[now][j-k+1][0]+min(dp[u][k][0],dp[u][k][1])+1,
									  dp[now][j-k][1]+min(dp[u][k+1][0],dp[u][k][1])));
				}
			}
		}
		if(e[i].w==0){
//			cout<<"0"<<endl;
			for(int j=0;j<=2;j++){
				for(int k=0;k<=j;k++){
					tmp[j][0]=min(tmp[j][0],dp[now][j-k][0]+min(dp[u][k+1][0],dp[u][k][1])+1);
					tmp[j][1]=min(tmp[j][1],min(dp[now][j-k+1][0]+min(dp[u][k][0],dp[u][k][1]),
									  dp[now][j-k][1]+min(dp[u][k+1][0]+1,min(dp[u][k][0],dp[u][k][1]))));
				}
			}
		}
		for(int j=0;j<=2;j++)for(int k=0;k<=1;k++)dp[now][j][k]=tmp[j][k];
//		cout<<"checking .."<<now<<endl;
//		cout<<dp[now][0][0]<<' '<<dp[now][0][1]<<endl;
//		cout<<dp[now][1][0]<<' '<<dp[now][1][1]<<endl;
//		cout<<dp[now][2][0]<<' '<<dp[now][2][1]<<endl;
	}
//	cout<<"END .."<<now<<endl;
//	cout<<dp[now][0][0]<<' '<<dp[now][0][1]<<endl;
//	cout<<dp[now][1][0]<<' '<<dp[now][1][1]<<endl;
//	cout<<dp[now][2][0]<<' '<<dp[now][2][1]<<endl;
}
int main(){
	cin>>n;
	for(i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);add(y,x,0);
	}
	memset(dp,0x2f,sizeof(dp));
	for(i=1;i<=n;i++)
		if(!vis[i]){
			w=0;x=0;
			dfs(i,0);
			if(ci[i]){
				can+=min(x,w-x);
				ans+=min(x,w-x);
			}else root=i;
		}
	dfs2(root,0);
	cout<<min(min(A(dp[root][0])+ans-min(can,2),A(dp[root][1])+ans-min(can,1)),A(dp[root][2])+ans)<<endl;
//	cout<<A(dp[root][0])+ans-min(can,2)<<endl;
//	cout<<A(dp[root][1])+ans-min(can,1)<<endl;
	return 0;
}