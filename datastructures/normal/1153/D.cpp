#include <iostream>
#include <cstdio>
using namespace std;
int u[300005],v[300005],nxt[300005],first[300005];
int n,size[300005],a[300005],f[300005];
inline void dfs(int now){
	if (!first[now]){
		size[now]=f[now]=1;
		return;
	}
	for (int i=first[now];i;i=nxt[i]){
		dfs(v[i]);
		size[now]+=size[v[i]];
	}
	if (a[now]==1){
		int s=size[now];
		for (int i=first[now];i;i=nxt[i])
			s=min(s,size[v[i]]-f[v[i]]);
		f[now]=size[now]-s;
	}
	else{
		int s=0;
		for (int i=first[now];i;i=nxt[i]){
//			cout<<now<<' '<<v[i]<<'x'<<endl;
			s+=f[v[i]]-1;
		}
		f[now]=s+1;
	}
//	cout<<now<<' '<<f[now]<<endl;
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=2;i<=n;i++){
		int fa;
		scanf("%d",&fa);
		u[i]=fa,v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs(1);
	cout<<f[1]<<endl;
	return 0;
}