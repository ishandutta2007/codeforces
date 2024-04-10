#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,K;
vector<int>g[100004];
bool rt[100004];
int sz[100004],N;
int dfs(int x,int p){
	sz[x]=1;
	for(auto to:g[x])if(to!=p&&!rt[to])sz[x]+=dfs(to,x);
	return sz[x];
}
int findr(int x,int p){
	int maxs=0;
	for(auto to:g[x])if(to!=p&&!rt[to]){
		int tmp=findr(to,x);
		if(tmp>0)return tmp;
		maxs=max(maxs,sz[to]);
	}
	if(max(maxs,N-sz[x])<=N/2)return x;
	return -1;
}
char c[100004];
void daq(int x,int now){
	N=dfs(x,0);
	int root=findr(x,0);
	rt[root]=1;
	c[root]=now+'A';
	for(auto y:g[root])if(!rt[y])daq(y,now+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u); 
	}
	daq(1,0);
	for(int i=1;i<=n;i++)putchar(c[i]),putchar(' ');
}