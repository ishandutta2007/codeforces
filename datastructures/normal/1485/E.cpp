#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 1000000000
#define int long long
using namespace std;
int t,n,u[500005],v[500005],first[500005],nxt[500005],fa[500005],a[500005],v1[500005],v2[500005],v3[500005],v4[500005],f[500005];
struct node{
	int id,depth;
}c[500005];
bool cmp(node a,node b){
	return a.depth>b.depth;
}
inline void dfs(register int now,register int f,register int d){
	fa[now]=f,c[now].id=now,c[now].depth=d;
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1);
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=2;i<=n;i++){
			scanf("%lld",&u[i]);
			v[i]=i;
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		for (int i=2;i<=n;i++)scanf("%lld",&a[i]);
		dfs(1,0,1);
		sort(c+1,c+1+n,cmp);
		for (register int i=1;i<=n;i++)f[i]=0,v1[i]=v2[i]=v3[i]=v4[i]=-inf;
		for (register int i=1;i<=n;i++){
			register int now=c[i].id,nowd=c[i].depth;
			for (register int j=first[now];j;j=nxt[j])
				if (v[j]!=fa[now])f[now]=max(f[now],max(max(v1[nowd+1]+a[v[j]]+f[v[j]],v2[nowd+1]+a[v[j]]),max(v3[nowd+1]+f[v[j]]-a[v[j]],v4[nowd+1]-a[v[j]])));
			v1[nowd]=max(v1[nowd],-a[now]);
			v2[nowd]=max(v2[nowd],f[now]-a[now]);
			v3[nowd]=max(v3[nowd],a[now]);
			v4[nowd]=max(v4[nowd],f[now]+a[now]);
		}
		cout<<f[1]<<endl;
		for (int i=1;i<=2*n;i++)u[i]=v[i]=first[i]=nxt[i]=0;
	}
	return 0;
}