#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,q,a,b;
int u[200005],v[200005],first[100005],nxt[200005];
int size[100005],depth[100005],fa[100005][25];
inline void add(int i){
	nxt[i]=first[u[i]];
	first[u[i]]=i;
	return;
}
inline void dfs(int now,int f,int d){
	fa[now][0]=f;
	depth[now]=d;
	size[now]=1;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1),size[now]+=size[v[i]];
	return;
}
inline int ask(int x,int y){
	for (int i=20;i>=0;i--)
		if (depth[fa[x][i]]>=depth[y])x=fa[x][i];
	for (int i=20;i>=0;i--)
		if (depth[fa[y][i]]>=depth[x])y=fa[y][i];
	if (x==y)return x;
	for (int i=20;i>=0;i--)
		if (fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
//	freopen("519E.in","r",stdin);
//	freopen("519E.out","w",stdout);
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		add(i);
		u[i+n]=v[i],v[i+n]=u[i];
		add(i+n);
	}
	memset(depth,-1,sizeof(depth));
	dfs(1,0,0);
	cin>>q;
	while(q--){
		scanf("%d%d",&a,&b);
		int lca=ask(a,b);
		int lenth=(depth[a]-depth[lca])+(depth[b]-depth[lca]);
		if (a==b){
			printf("%d\n",size[1]);
			continue;
		}
		if (depth[a]==depth[b]){
			for (int i=20;i>=0;i--)
				if (depth[fa[a][i]]>depth[lca])a=fa[a][i],b=fa[b][i];
			printf("%d\n",size[1]-size[a]-size[b]);
			continue;
		}
		if (lenth%2!=0){
			printf("0\n");
			continue;
		}
		if (lenth%2==0){
			if (lenth/2<=(depth[a]-depth[lca])){
				int s=lenth/2;
				for(int i=20;i>=0;i--)
					if (s>(1<<i))a=fa[a][i],s-=(1<<i);
				printf("%d\n",size[fa[a][0]]-size[a]);
			}
			else{
				int s=lenth/2;
				for (int i=20;i>=0;i--)
					if (s>(1<<i))b=fa[b][i],s-=(1<<i);
				printf("%d\n",size[fa[b][0]]-size[b]);
			}
		}
	}
	return 0;
}