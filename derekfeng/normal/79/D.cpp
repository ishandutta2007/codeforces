#include<bits/stdc++.h>
using namespace std;
int n,k,m,a[105],N;
int d[10005],dis[22][10005];
int dp[1100000];
vector<int>v;
void bfs(int *dis,int s){
	fill(dis,dis+n+2,1e9);
	queue<int>q;
	dis[s]=0,q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=m;i++){
			int L=a[i];
			if(u+L<=n+1&&dis[u+L]>dis[u]+1)
				dis[u+L]=dis[u]+1,q.push(u+L);
			if(u-L>0&&dis[u-L]>dis[u]+1)
				dis[u-L]=dis[u]+1,q.push(u-L);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1,x;i<=k;i++)scanf("%d",&x),d[x]=1;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++)if(d[i]^d[i-1])v.push_back(i);
	N=v.size();
	for(int i=0;i<N;i++)bfs(dis[i],v[i]);
	for(int i=1;i<(1<<N);i++)dp[i]=1e9;
	for(int i=1;i<(1<<N);i++)if(__builtin_parity(i)==0){
		int f=__builtin_ffs(i)-1;
		for(int j=0;j<N;j++)if(j!=f&&((1<<j)&i))
			dp[i]=min(dp[i],dp[i^(1<<f)^(1<<j)]+dis[j][v[f]]);
	}
	if(dp[(1<<N)-1]==1e9)puts("-1");
	else printf("%d",dp[(1<<N)-1]);
}