#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int fa[200004];
int u[200004],v[200004],w[200004];
bool ok[200004];
int Fa(int u){
	return u==fa[u]?u:fa[u]=Fa(fa[u]);
}
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u[i],&v[i],&w[i]),ok[i]=1;
	int ans=0;
	for(int t=30;~t;t--){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)if(ok[i]&&((w[i]>>t)&1)==0)
			fa[Fa(u[i])]=Fa(v[i]);
		int num=0,ret=0;
		for(int i=1;i<=n;i++)if(Fa(i)==i)num++;
		if(num>1)ret=1,ans|=(1<<t);
		for(int i=1;i<=m;i++)if(((w[i]>>t)&1)>ret)ok[i]=0;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}