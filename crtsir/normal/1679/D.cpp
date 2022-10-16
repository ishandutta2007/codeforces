#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003],x[200003],y[200003];
long long k;
int dp[200003];
struct scc{
	vector<int>g[200003],rg[200003],V;
	int col[200003],cntt,idx[200003];
	bool used[200003]; 
	void init(){
		for(int i=0;i<n;i++)g[i].clear(),rg[i].clear();
	}
	void addedge(int x,int y){
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	void dfs(int x){
		used[x]=1;
		for(int i=0;i<g[x].size();i++)
			if(!used[g[x][i]])
				dfs(g[x][i]);
		V.push_back(x);
	}
	void rdfs(int x,int k){
		used[x]=1;col[x]=k;
		for(int i=0;i<rg[x].size();i++)
			if(!used[rg[x][i]])
				rdfs(rg[x][i],k);
	}
	void calc(){
		memset(used,0,sizeof(used));
		cntt=0;V.clear();
		for(int i=0;i<n;i++)
			if(!used[i])
				dfs(i);
		memset(used,0,sizeof(used));
		cntt=0;
		for(int i=V.size()-1;i>=0;i--)
			if(!used[V[i]])
				rdfs(V[i],cntt++);
	}
}gr;
vector<int>v[200003];
inline void dfs(int nw){
	if(dp[nw]!=-1)return;dp[nw]=1;
	for(int i=0;i<v[nw].size();i++)
		dfs(v[nw][i]),
		dp[nw]=max(dp[nw],dp[v[nw][i]]+1);
}
bool check(int nw){
	memset(dp,-1,sizeof(dp));
	gr.init();
	for(int i=0;i<n;i++)v[i].clear();
	for(int i=0;i<m;i++)
		if(a[x[i]]<=nw&&a[y[i]]<=nw){
			v[x[i]].push_back(y[i]);
			gr.addedge(x[i],y[i]);
		}
	gr.calc();
	if(gr.cntt!=n)return 1;
	for(int i=0;i<n;i++)
		if(a[x[i]]<=nw)
			dfs(i);
	for(int i=0;i<n;i++)
		if(dp[i]>=k)return 1;return 0;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<m;i++)
		scanf("%d%d",x+i,y+i),x[i]--,y[i]--;
	int l=1,r=1000000001,mid;
	while(l!=r){
		mid=(l+r>>1);
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	if(l<=1000000000)
		cout<<l;
	else
		cout<<-1; 
}