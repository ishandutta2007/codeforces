#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,m,u[300005],v[300005],first[300005],nxt[300005];
int fa[300005],depth[300005],idx,dfn[300005],dfo[300005];
int x[300005],y[300005];
int ovo[300005],qwq[300005],c[300005],d[300005];
int sum[300005];
int fg,ans;
bool in(int a,int b){//whether a is in b
	if (dfn[a]>=dfn[b]&&dfn[a]<=dfo[b])return 1;
	return 0;
}
int gs(int l,int r){
	return sum[r]-sum[l-1];
}
void dfs1(int now,int f,int d){
	fa[now]=f;
	depth[now]=d;
	++idx;
	dfn[now]=idx;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs1(v[i],now,d+1);
	dfo[now]=idx;
	return;
}
void dfs2(int now,int f){
	int cnt=0,id=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs2(v[i],now);
		qwq[now]=max(qwq[now],qwq[v[i]]);
		if (d[v[i]]==1){
			d[now]=1;
			cnt++;
			id=v[i];
		}
	}
	if (cnt>1)qwq[now]=0;
	else if (cnt==1)qwq[now]=max(qwq[id],ovo[id]);
	if (qwq[now]==depth[now]){
		c[now]=1;
		d[now]=1;
		qwq[now]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=2;i<=n;i++){
		cin>>u[i];
		v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs1(1,0,1);
	for (int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		if (depth[x[i]]>depth[y[i]])swap(x[i],y[i]);
		if (x[i]==fa[y[i]]){
			cout<<-1<<endl;
			return 0;
		}
		if (in(y[i],x[i])){
			ovo[y[i]]=max(ovo[y[i]],depth[x[i]]+1);
			qwq[fa[y[i]]]=max(qwq[fa[y[i]]],depth[x[i]]+1);
		}
	}
	dfs2(1,0);
	for (int i=1;i<=n;i++){
		if (c[i]==1)ans++;
		sum[dfn[i]]=c[i];
	}
	for (int i=1;i<=n;i++)sum[i]+=sum[i-1];
	for (int i=1;i<=m;i++){
		if (!in(y[i],x[i]))
			if (gs(dfn[x[i]],dfo[x[i]])+gs(dfn[y[i]],dfo[y[i]])==sum[n])fg=1;
	}
	ans+=fg;
	cout<<ans<<endl;
	return 0;
}