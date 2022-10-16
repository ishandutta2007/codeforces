#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int n,k,root,m,u[1000005],v[1000005],first[1000005],nxt[1000005],du[1000005],book[1000005];
int fa[1000005],to[1000005],fg,tot,ans[1000005],in[1000005];
inline void add(register int a,register int b){
	register int i=++m;
	u[i]=a,v[i]=b;
	nxt[i]=first[u[i]],first[u[i]]=i;
	du[v[i]]++;
	return;
}
inline void dfs(register int now){
	if (book[now]==1)return;
	ans[++tot]=now;
	book[now]=1;
	for (register int i=first[now];i;i=nxt[i])
		du[v[i]]--;
	if (to[now]!=0){
		if (du[to[now]]!=0){
			fg=1;
			return;
		}
		dfs(to[now]);
	} 
	for (register int i=first[now];i;i=nxt[i])
		if (du[v[i]]==0&&v[i]!=to[now])dfs(v[i]);
	return;
} 
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		scanf("%d",&fa[i]);
		if (fa[i]!=0)add(fa[i],i);
		else root=i;
	}
	for (int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (to[x]!=0){
			cout<<0<<endl;
			return 0;
		}
		if (book[y]!=0){
			cout<<0<<endl;
			return 0;
		}
		book[y]=1;
		to[x]=y;
		if (fa[y]!=x)add(x,y);
	}
	for (register int i=1;i<=n;i++){
		if (book[i]==1)continue;
		for (register int j=to[i];j;j=to[j])in[j]=1;
		for (register int j=to[i];j;j=to[j]){
			if (in[fa[j]]==1)continue; 
			if (fa[j]!=i&&fa[j]!=fa[i])add(fa[j],i);
		}
		for (register int j=to[i];j;j=to[j])in[j]=0;
	}
	memset(book,0,sizeof(book)); 
	dfs(root);
	if (fg==1||tot!=n){
		cout<<0<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)printf("%d ",ans[i]);
	cout<<endl;
	return 0;
}