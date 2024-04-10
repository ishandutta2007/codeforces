#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int n,m,a[200005],u[500005],v[500005],first[500005],nxt[500005],root;
int depth[500005],ch[500005],val[500005],sum[500005],qwq,ans;
void dfs1(int now,int fa,int d){
	depth[now]=d;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		if (depth[v[i]]==0)dfs1(v[i],now,d+1);
		else if (depth[v[i]]<depth[now])ch[now]=1;
	}
	return;
}
void dfs2(int now){
	for (int i=first[now];i;i=nxt[i])
		if (depth[v[i]]==depth[now]+1){
			dfs2(v[i]);
			ch[now]+=ch[v[i]];
		}
	if (ch[now]==0)val[now]=a[now];
	else qwq+=a[now];
	return;
}
void dfs3(int now,int fa){
	sum[now]=val[now]+sum[fa];
	ans=max(ans,sum[now]);
	for (int i=first[now];i;i=nxt[i])
		if (depth[v[i]]==depth[now]+1)dfs3(v[i],now);
	return;
}
signed main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for (int i=1;i<=m;i++){
    	scanf("%lld%lld",&u[i],&v[i]);
    	nxt[i]=first[u[i]],first[u[i]]=i;
    	u[i+m]=v[i],v[i+m]=u[i];
    	nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	cin>>root;
	dfs1(root,0,1);
	dfs2(root);
	dfs3(root,0);
	cout<<qwq+ans<<endl;
    return 0;
}