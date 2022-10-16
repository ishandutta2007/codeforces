#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int n,u[6005],v[6005],first[3005],nxt[6005];
int f[3005][3005],fa[3005][3005],size[3005][3005],ans;
inline void dfs1(register int now,register int f,register int root){
	size[root][now]=1,fa[root][now]=f;
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f){
			dfs1(v[i],now,root);
			size[root][now]+=size[root][v[i]];
		}
	return;
}
inline int dfs2(register int a,register int b){
	if (f[a][b]!=-1)return f[a][b];
	int now=size[a][b]*size[b][a];
	for (register int i=first[a];i;i=nxt[i])
		if (v[i]!=fa[b][a])now=max(now,dfs2(v[i],b)+size[a][b]*size[b][a]);
	for (register int i=first[b];i;i=nxt[i])
		if (v[i]!=fa[a][b])now=max(now,dfs2(a,v[i])+size[a][b]*size[b][a]);
	return f[a][b]=now; 
}
signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=1;i<=n;i++)dfs1(i,0,i);
	memset(f,-1,sizeof(f));
	for (int i=1;i<n;i++)ans=max(ans,dfs2(u[i],v[i]));
	cout<<ans<<endl;
	return 0;
}