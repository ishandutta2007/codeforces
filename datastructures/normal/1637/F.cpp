#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
} 
int n,h[200005],u[500005],v[500005],first[500005],nxt[500005];
int deg[500005];
int mx[200005];
int idx,dfn[200005],dfo[200005];
int pre[200005],suf[200005];
int ans;
void dfs1(int now,int fa){
	++idx;
	dfn[now]=idx;
	pre[idx]=suf[idx]=h[now];
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa){
			dfs1(v[i],now);
			mx[now]=max(mx[now],mx[v[i]]);
		}
	if (mx[now]<h[now])ans+=h[now]-mx[now],mx[now]=h[now];
	dfo[now]=idx;
	return;
}
void dfs2(int now,int fa){
	int fi=-100000000,se=-100000000;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		if (mx[v[i]]>fi)se=fi,fi=mx[v[i]];
		else if (mx[v[i]]>se)se=mx[v[i]];
	}
	int qwq=max(se,max(pre[dfn[now]-1],suf[dfo[now]+1]));
	ans+=max(0ll,h[now]-qwq);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)dfs2(v[i],now);
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)h[i]=read();
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		deg[u[i]]++,deg[v[i]]++;
	}
	if (n==2){
		cout<<2*max(h[1],h[2])<<endl;
		return 0;
	}
	int root=0;
	for (int i=1;i<=n;i++)
		if (deg[i]>1)root=i;
	dfs1(root,0);
	for (int i=1;i<=n;i++)pre[i]=max(pre[i],pre[i-1]);
	for (int i=n;i>=1;i--)suf[i]=max(suf[i],suf[i+1]);
	dfs2(root,0);
	cout<<ans<<endl;
	return 0;
}