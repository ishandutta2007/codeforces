#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,u[200005],v[200005],first[100005],nxt[200005],sz[100005];
int cnt[100005],ans[100005];
void dfs(int now){
	if (first[now]==0)sz[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		dfs(v[i]);
		sz[now]+=sz[v[i]];
	}
	cnt[sz[now]]++;
	return;
}
int main(){
	cin>>n;
	for (int i=2;i<=n;i++){
		scanf("%d",&u[i]);
		v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs(1);
	for (int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
		for (int j=cnt[i-1]+1;j<=cnt[i];j++)ans[j]=i;
	}
	for (int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}