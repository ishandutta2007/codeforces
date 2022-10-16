#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t,n,k,u[1000005],v[1000005],w[1000005],first[1000005],nxt[1000005];
int size[1000005];
int ans1,ans2;
inline void dfs1(int now,int fa,int d){
	ans2+=d;
	size[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs1(v[i],now,d+w[i]);
		size[now]+=size[v[i]];
	}
	return;
}
inline void dfs2(int now,int fa){
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs2(v[i],now);
		if (size[v[i]]%2==1)ans1+=w[i];
	}
	return;
}
inline void dfs3(int now,int fa,int rest){
	if (rest==0)return;
	int mx=0,id=0,maxw=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		if (size[v[i]]>mx)mx=size[v[i]],id=v[i],maxw=w[i];
	}
	if (mx<=size[now]-mx)return;
	if (size[now]-mx>=rest)return;
	ans2-=2*(rest-(size[now]-mx))*maxw;
	dfs3(id,now,rest-(size[now]-mx));
	return; 
}
signed main(){
	cin>>t;
	while(t--){
		cin>>k;
		n=k*2;
		for (int i=1;i<n;i++){
			scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		ans1=ans2=0;
		dfs1(1,0,0);
		dfs2(1,0);
		dfs3(1,0,k);
		cout<<ans1<<' '<<ans2<<endl;
		for (int i=1;i<=2*n;i++)first[i]=nxt[i]=0;
	}
	return 0;
}