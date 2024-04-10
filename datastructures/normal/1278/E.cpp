#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,u[1000005],v[1000005],first[500005],nxt[1000005],id[1000005],l[1000005],r[1000005];
int tot;
inline void dfs(int now,int fa){
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
	}
	id[++tot]=now;
	int l,r;
	l=tot+1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		id[++tot]=v[i];
	}
	r=tot;
	for (int i=l,j=r;i<j;i++,j--)swap(id[i],id[j]);
	if (now==1)id[++tot]=now;
	return;
} 
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0);
	for (int i=1;i<=2*n;i++)
		if (l[id[i]]==0)l[id[i]]=i;
		else r[id[i]]=i;
	for (int i=1;i<=n;i++)printf("%d %d\n",l[i],r[i]);
	return 0;
}