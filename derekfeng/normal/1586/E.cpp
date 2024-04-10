#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[300004],tr[300004];
vector<int>id[300004],ID[300004];
bool vis[300004];
int f[300004];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i],I=id[x][i];
		if(vis[y])continue;
		dfs(y);
		tr[x].push_back(y),tr[y].push_back(x);
		ID[x].push_back(I),ID[y].push_back(I);
	}
}
vector<int>ans[300004];
bool pa(int x,int fa,int s,int qq){
	ans[qq].push_back(x);
	if(x==s)return 1;
	for(int i=0;i<tr[x].size();i++){
		int y=tr[x][i],I=ID[x][i];
		if(y==fa)continue;
		f[I]^=1;
		if(pa(y,x,s,qq))return 1;
		f[I]^=1;
	}
	ans[qq].pop_back();
	return 0;
}
int res;
int dfs(int x,int fa){
	int tmp=0;
	for(int i=0;i<tr[x].size();i++){
		int y=tr[x][i],I=ID[x][i];
		if(y==fa)continue;
		int z=f[I],p=dfs(y,x);
		if(z==0&&p==0)continue;
		if(z==0&&p)res++;
		else tmp++;
	}
	res+=tmp/2;
	return tmp%2;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
		id[u].push_back(i),id[v].push_back(i);
	}
	dfs(1);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int a,b;scanf("%d%d",&a,&b);
		pa(a,0,b,i);
	}
	bool ok=0;
	for(int i=0;i<m;i++)if(f[i])ok=1;
	if(!ok){
		puts("YES");
		for(int i=0;i<q;i++){
			printf("%d\n",ans[i].size());
			for(auto x:ans[i])printf("%d ",x);
			puts("");
		}
		return 0;
	}
	printf("NO\n");
	res+=dfs(1,0);
	printf("%d",res);
}