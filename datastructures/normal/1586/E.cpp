#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;
int n,m,q,book[1000005];
int u[1000005],v[1000005],first[1000005],nxt[1000005];
vector<int> e[1000005];
int fa[1000005],depth[1000005];
vector<int> d[1000005];
vector<int> _d[1000005];
int c[1000005],f[1000005],g[1000005];
void dfs1(int now,int d){
	book[now]=1;
	depth[now]=d;
	for (int i=first[now];i;i=nxt[i]){
		if (book[v[i]]==1)continue;
		fa[v[i]]=now;
		dfs1(v[i],d+1);
		e[now].push_back(v[i]);
	}
	return;
}
int lca(int a,int b){
	if (depth[a]<depth[b])swap(a,b);
	while(depth[a]>depth[b])a=fa[a];
	if (a==b)return a;
	while(fa[a]!=fa[b])a=fa[a],b=fa[b];
	return fa[a];
}
void dfs2(int now){
	int awa=0,quq=0;
	for (int i=0,len=e[now].size();i<len;i++){
		dfs2(e[now][i]);
		f[now]+=f[e[now][i]];
		if (c[e[now][i]]==0)f[now]+=g[e[now][i]];
		if (c[e[now][i]]==1)awa++;
	}
	if (quq>=awa){
		if (quq>awa)g[now]=1;
		else g[now]=0;
	}
	else{
		awa-=quq;
		if (awa&1){
			f[now]+=awa/2;
			g[now]=1;
		}
		else{
			f[now]+=awa/2;
			g[now]=0;
		}
	}
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	dfs1(1,1);
	cin>>q;
	for (int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int qwq=lca(x,y);
		while(x!=qwq)d[i].push_back(x),c[x]^=1,x=fa[x];
		d[i].push_back(qwq);
		while(y!=qwq)_d[i].push_back(y),c[y]^=1,y=fa[y];
		for (int j=_d[i].size()-1;j>=0;j--)d[i].push_back(_d[i][j]);
	}
	dfs2(1);
	if (f[1]+g[1]==0){
		puts("YES");
		for (int i=1;i<=q;i++){
			int len=d[i].size();
			printf("%d\n",len);
			for (int j=0;j<len;j++)printf("%d ",d[i][j]);
			puts("");
		}
	}
	else{
		puts("NO");
		cout<<f[1]+g[1]<<endl;
	}
	return 0;
}