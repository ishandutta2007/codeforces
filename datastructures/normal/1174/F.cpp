#include <iostream>
#include <cstdio>
#define inf 1000000000
using namespace std;
int n,u[400005],v[400005],first[200005],nxt[400005],fa[200005],depth[200005],dx,book[200005];
int size[200005],sum,mn,root;
inline int askd(register int now){
	cout<<'d'<<' '<<now<<endl;
	register int x;
	cin>>x;
	return x;
}
inline int asks(register int now){
	cout<<'s'<<' '<<now<<endl;
	register int x;
	cin>>x;
	return x;
}
inline void getdf(register int now,register int f,register int d){
	fa[now]=f,depth[now]=d;
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)getdf(v[i],now,d+1);
	return;
}
inline void getroot(register int now,register int f){
	register int mx=0;
	size[now]=1;
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==f||book[v[i]]==1)continue;
		getroot(v[i],now);
		size[now]+=size[v[i]];
		mx=max(mx,size[v[i]]);
	}
	mx=max(mx,sum-size[now]);
	if (mx<=mn)mn=mx,root=now;
	return;
}
inline int dfs(register int now){
	book[now]=1;
	int d=askd(now);
	if (d==0)return now;
	int nxt=0;
	if (d==dx-depth[now])nxt=asks(now);
	else nxt=fa[now];
	getroot(now,0);
	sum=size[nxt],mn=inf,root=0;
	getroot(nxt,0);
	return dfs(root);
}
int main(){
	cin>>n;
	for (register int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	getdf(1,0,0);
	dx=askd(1);
	sum=n,mn=inf,root=0;
	getroot(1,0);
	int ans=dfs(root);
	cout<<'!'<<' '<<ans<<endl;
	return 0;
}