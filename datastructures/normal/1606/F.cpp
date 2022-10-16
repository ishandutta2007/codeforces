#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
	int v,k,id;
	bool operator <(const node &x)const{
		return k<x.k;
	}
}c[200005];
int n,q,u[400005],v[400005],first[400005],nxt[400005];
int depth[200005],fa[200005],g[200005][105],h[105],dp[105];
int ans[200005];
int B=80;
void dfs(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs(v[i],now,d+1);
		for (int j=1;j<=B;j++)h[j]=g[v[i]][j-1];
		h[0]=1;
		memset(dp,0,sizeof(dp));
		for (int j=0;j<=B;j++){
			if (h[j]==0)continue;
			for (int k=0;j+k<=B;k++)
				dp[j+k]=max(dp[j+k],h[j]+g[now][k]);
		}
		for (int j=0;j<=B;j++)g[now][j]=dp[j];
	}
	return;
}
int id[200005];
bool cmp(int a,int b){
	return depth[a]>depth[b];
}
int f[200005];
int qtot,qfirst[200005],qnxt[200005],qv[200005];
void qadd(int a,int b){
	int i=++qtot;
	qv[i]=b;
	qnxt[i]=qfirst[a],qfirst[a]=i;
	return;
}
void solve(int k){
	for (int i=1;i<=n;i++){
		int now=id[i];
		f[now]=0;
		for (int j=qfirst[now];j;j=qnxt[j])f[now]+=max(f[qv[j]]-k,1);
	}
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
	dfs(1,0,1);
	for (int i=1;i<=n;i++)id[i]=i;
	sort(id+1,id+1+n,cmp);
	cin>>q;
	for (int i=1;i<=q;i++)scanf("%d%d",&c[i].v,&c[i].k),c[i].id=i;
	sort(c+1,c+1+q);
	for (int i=1;i<=n;i++)
		for (int j=first[i];j;j=nxt[j])
			if (v[j]!=fa[i])qadd(i,v[j]);
	for (int i=1;i<=q;i++){
		if (c[i].k<=n/B){
			solve(c[i].k);
			int j=i;
			while(j<q&&c[j+1].k==c[i].k)j++;
			for (int k=i;k<=j;k++)ans[c[k].id]=f[c[k].v];
			i=j;
		}
		else{
			int now=c[i].v,nowk=c[i].k;
			for (int j=0;j<=B;j++)ans[c[i].id]=max(ans[c[i].id],g[now][j]-nowk*j);
		}
	}
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}