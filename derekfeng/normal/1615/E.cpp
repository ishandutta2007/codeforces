#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K;
vector<int>g[200004];
priority_queue<int>f[200004];
void dfs(int x,int fa){
	bool leaf=1;
	for(auto y:g[x])if(y!=fa)
		leaf=0,dfs(y,x);
	if(leaf){
		f[x].push(1);
		return;
	}
	for(auto y:g[x])if(y!=fa){
		if(f[x].size()<f[y].size())swap(f[x],f[y]);
		while(!f[y].empty()){
			int u=f[y].top();f[y].pop();
			f[x].push(u);
		}
	}
	int u=f[x].top();f[x].pop();
	f[x].push(u+1),f[x].push(0);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int cnt=0;
	long long ans=-1e18;
	for(int i=0;i<=K;i++){
		if(i>0){
			if(f[1].empty())break;
			cnt+=f[1].top(),f[1].pop();
		}
		int L=0,R=n-cnt;
		int A=n-i,B=i;
		int T=(A+B)/2;
		ll Q=1e18;
		Q=min(Q,(ll)(A-L)*(B-L));
		Q=min(Q,(ll)(A-R)*(B-R));
		if(L<=T-1&&T-1<=R)
			Q=min(Q,(ll)(A-(T-1))*(B-(T-1)));
		if(L<=T&&T<=R)
			Q=min(Q,(ll)(A-T)*(B-T));
		if(L<=T+1&&T+1<=R)
			Q=min(Q,(ll)(A-(T+1))*(B-(T+1)));
		ans=max(ans,Q);
	}
	printf("%lld",ans);
}