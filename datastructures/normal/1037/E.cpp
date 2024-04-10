#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,m,k,u[1000005],v[1000005],first[1000005],nxt[1000005],deg[1000005];
int q[1000005],head,tail;
int del[1000005],ans,awa[1000005];
map<int,int> c[1000005];
void qwq(int now){
	for (int i=first[now];i;i=nxt[i]){
		if (c[u[i]][v[i]]==0)continue;
		c[u[i]][v[i]]=c[v[i]][u[i]]=0;
		deg[v[i]]--;
		if (deg[v[i]]<k&&del[v[i]]==0)q[++tail]=v[i],del[v[i]]=1,ans++;
	}
	return;
}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		c[u[i]][v[i]]++,c[v[i]][u[i]]++;
		deg[u[i]]++,deg[v[i]]++;
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	head=1,tail=0;
	for (int i=1;i<=n;i++)
		if (deg[i]<k)q[++tail]=i,del[i]=1,ans++;
	for (int i=m;i>=1;i--){
		while(head<=tail)qwq(q[head]),head++;
		awa[i]=n-ans;
		if (c[u[i]][v[i]]==1)c[u[i]][v[i]]=c[v[i]][u[i]]=0,deg[u[i]]--,deg[v[i]]--;
		if (deg[u[i]]<k&&del[u[i]]==0)q[++tail]=u[i],del[u[i]]=1,ans++;
		if (deg[v[i]]<k&&del[v[i]]==0)q[++tail]=v[i],del[v[i]]=1,ans++;
	}
	for (int i=1;i<=m;i++)printf("%d\n",awa[i]);
	return 0;
}