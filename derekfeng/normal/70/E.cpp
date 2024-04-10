#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
#define INF (1<<29)
int N;
int K,d[200];
vector<int>edge[200],child[200];
int parent[200];
int dp[200][200];
int a[200];
int ans[200];
int make_tree(int p,int x){
	int i;
	if(p!=-1)child[p].push_back(x);
	parent[x]=p;
	REP(i,edge[x].size())if(edge[x][i]!=p)make_tree(x,edge[x][i]);
}
void dfs(int x){
	int y,i,j;
	REP(i,child[x].size())dfs(child[x][i]);
	dp[x][0]=INF;
	REP(y,N){
		int z=y;
		while(z!=-1&&z!=x)z=parent[z];
		if(z==-1)continue;
		ll tmp=0;
		z=y;
		int dist=0,prev=-1;
		while(1){
			tmp+=((dist==0)?K:d[dist]);
			REP(i,child[z].size())if(child[z][i]!=prev)tmp+=dp[child[z][i]][min(dist+1,N-1)];
			if(z==x)break;
			prev=z;z=parent[z];dist++;
		}
		if(tmp<dp[x][0]){a[x]=y;dp[x][0]=tmp;}
	}
	for(i=1;i<N;i++){
		dp[x][i]=dp[x][0];
		ll tmp=d[i];
		REP(j,child[x].size())tmp+=dp[child[x][j]][min(i+1,N-1)];
		if(tmp<dp[x][i])dp[x][i]=(int)tmp;
	}
}
void path(int x,int dist,int center){
	int i,j;
	if(dp[x][dist]!=dp[x][0]){
		ans[x]=center;
		REP(i,child[x].size())path(child[x][i],min(dist+1,N-1),center);
		return;
	}
	int y=a[x];
	i=y;
	while(1){
		ans[i]=y;
		if(i==x)break;
		i=parent[i];
	}
	int prev=-1;
	i=y;
	int dist2=0;
	while(1){
		REP(j,child[i].size())if(child[i][j]!=prev)path(child[i][j],dist2+1,y);
		if(i==x)break;
		prev=i;i=parent[i];dist2++;
	}
}
int main(void){
	int i;
	cin>>N>>K;
	REP(i,N-1)cin>>d[i+1];
	REP(i,N-1){
		int u,v;
		cin>>u>>v;u--;v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	make_tree(-1,0);
	dfs(0);
	cout<<dp[0][0]<<endl;
	path(0,0,-1);
	REP(i,N){
		cout<<ans[i]+1;
		if(i==N-1)cout<<endl;else cout<<' ';
	}
	return 0;
}