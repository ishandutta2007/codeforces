#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,u[1000005],v[1000005],first[500005],nxt[1000005];
int size[500005],sum,ans;
inline void dfs1(int now,int fa){
	size[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs1(v[i],now);
		size[now]+=size[v[i]];
	}
	sum+=size[now];
	return;
}
inline void dfs2(int now,int fa){
	ans=max(ans,sum);
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		int sn=size[now],sv=size[v[i]];
		sum-=sn+sv;
		size[now]-=size[v[i]],size[v[i]]=n;
		sum+=size[now]+size[v[i]];
		dfs2(v[i],now);
		sum-=size[now]+size[v[i]];
		size[now]=sn,size[v[i]]=sv;
		sum+=sn+sv;
	}
	return;
} 
signed main(){
	cin>>n;
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<endl;
	return 0;
}