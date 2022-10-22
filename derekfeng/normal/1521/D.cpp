#include<bits/stdc++.h>
using namespace std;
int T,f[100004][2],n;
vector<int>g[1000004];
void dfs(int x,int par){
	f[x][1]=0;
	int MX=0;
	for(auto y:g[x])if(y!=par)dfs(y,x),f[x][1]+=min(f[y][1],f[y][0])+1;
	for(auto y:g[x])if(y!=par)MX=max(min(f[y][0],f[y][1])+1-f[y][1],MX);
	f[x][1]-=MX;
	f[x][0]=0;
	int P1=0,P2=0;
	for(auto y:g[x])if(y!=par){
		f[x][0]+=min(f[y][1],f[y][0])+1;
		int tmp=min(f[y][0],f[y][1])+1-f[y][1];
		if(P1<tmp)P2=P1,P1=tmp;
		else if(P2<tmp)P2=tmp;
	}
	f[x][0]-=P1+P2;
}
int root,lst;
pair<int,int> dfs1(int x,int par,int typ){
	int P1=0,p1=-1,P2=0,p2=-1;
	for(auto y:g[x])if(y!=par){
		int tmp=min(f[y][0],f[y][1])+1-f[y][1];
		if(P1<tmp)P2=P1,p2=p1,P1=tmp,p1=y;
		else if(P2<tmp) P2=tmp,p2=y;
	}
	if(typ==0){
		for(auto y:g[x])if(y!=par&&y!=p1&&y!=p2){
			pair<int,int> tmp=dfs1(y,x,(f[y][0]>f[y][1]));
			printf("%d %d %d %d\n",x,y,tmp.first,lst);
			lst=tmp.second;
		}
		if(P1==0)return make_pair(x,x);
		if(P2==0)return make_pair(dfs1(p1,x,1).first,x);
		return make_pair(dfs1(p2,x,1).first,dfs1(p1,x,1).first);
	}else{
		for(auto y:g[x])if(y!=par&&y!=p1){
			pair<int,int> tmp=dfs1(y,x,(f[y][0]>f[y][1]));
			printf("%d %d %d %d\n",x,y,tmp.first,lst);
			lst=tmp.second;
		}
		if(P1==0)return make_pair(x,x);
		return make_pair(dfs1(p1,x,1).first,x);
	}
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(g[i].size()==1)root=i;
	dfs(root,0);
	lst=root;
	printf("%d\n",f[root][0]);
	dfs1(root,0,0);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}