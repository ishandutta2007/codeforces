#include <iostream> 
#include <cstdio>
using namespace std;
int n,k,u[2000005],v[2000005],first[1000005],nxt[2000005];
int book[1000005],depth[1000005],fa[1000005][25];
inline void dfs(int now,int f,int d){
	depth[now]=d;
	fa[now][0]=f;
	for (register int i=1;i<=20;i++)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1);
	return;
}
int main(){
	cin>>n>>k;
	k=n-k;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	book[0]=book[n]=1;k--;
	dfs(n,0,1);
	for (int i=n-1;i>=1;i--){
		int now=i;
		if (book[now]==1)continue;
		for (int j=20;j>=0;j--)
			if (book[fa[now][j]]==0)now=fa[now][j];
		now=fa[now][0];
		if (k<depth[i]-depth[now])continue;
		k-=depth[i]-depth[now];
		now=i;
		while(book[now]==0)book[now]=1,now=fa[now][0]; 
	}
	for (int i=1;i<=n;i++)
		if (book[i]==0)printf("%d ",i);
	cout<<endl;
	return 0;
}