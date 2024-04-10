#include<bits/stdc++.h>
using namespace std;
int n,x,p[200004];
vector<int>tr[200004];
int f[200004],len;
bool vis[200004];
void dfs(int x,int p){
	f[x]=0;
	for(auto y:tr[x])if(y!=p){
		dfs(y,x),len=max(len,f[x]+f[y]+1);
		f[x]=max(f[x],f[y]+1);
	}
}
void sol(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)tr[i].clear();
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		tr[u].push_back(v),tr[v].push_back(u);
	}
	for(int i=1,x;i<=n;i++)scanf("%d",&x),p[x]=i;
	len=0,dfs(1,0);
	if(len>2){puts("Alice");return;}
	int rt;for(int i=1;i<=n;i++)if(tr[i].size()>1)rt=i;
	if(p[rt]!=rt&&x==rt){puts("Bob");return;}
	if(p[rt]!=rt){
		int pos;
		for(int i=1;i<=n;i++)if(p[i]==rt)pos=i;
		if(x==pos){puts("Bob");return;}
		swap(p[pos],p[rt]),x=rt;
	}
	fill(vis+1,vis+n+1,0);
	int ans=n;
	for(int i=1;i<=n;i++)if(!vis[i]){
		int cur=i;
		while(!vis[cur])vis[cur]=1,cur=p[cur];
		ans--;
	}
	if(ans==1&&x!=rt&&p[x]==x){puts("Alice");return;}
	if(ans==0){puts("Alice");return;}
	int t=x==rt?0:1;
	if(t^(ans&1))puts("Alice");
	else puts("Bob");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}