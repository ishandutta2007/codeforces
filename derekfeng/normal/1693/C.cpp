#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int t,n,m,f[200004];
vector<int>g[200004];
int deg[200004],lev[200004];
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int v,u;scanf("%d%d",&v,&u);
		g[u].push_back(v),deg[v]++;
	}
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	for(int i=1;i<=n;i++)f[i]=1e9;
	f[n]=0,pq.push({0,n});
	while(!pq.empty()){
		auto [W,x]=pq.top();pq.pop();
		if(W>f[x])continue;
		for(auto y:g[x]){
			int tmp=W+1+deg[y]-(++lev[y]);
			if(tmp<f[y])f[y]=tmp,pq.push({f[y],y});
		}
	}
	printf("%d",f[1]);
}