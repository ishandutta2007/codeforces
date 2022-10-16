#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,k,t,u[1000005],v[1000005],w[1000005],first[1000005],nxt[1000005];
int f[500005][2],d[500005],tot;
inline bool cmp(int a,int b){
	return a>b;
}
inline void dfs(int now,int fa){
	int num=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
		num+=f[v[i]][0];
	}
	tot=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		d[++tot]=f[v[i]][1]+w[i]-f[v[i]][0];
	}
	sort(d+1,d+1+tot,cmp);
	int sum=0;
	f[now][0]=f[now][1]=num;
	for (int i=1;i<=tot;i++){
		sum+=d[i];
		if (i<=k)f[now][0]=max(f[now][0],num+sum);
		if (i<k)f[now][1]=max(f[now][1],num+sum);
	}
	return;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<n;i++){
			scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i],w[i+n]=w[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs(1,0);
		cout<<f[1][0]<<endl;
		for (int i=1;i<=n;i++)f[i][0]=f[i][1]=0;
		for (int i=1;i<=n*2;i++)first[i]=nxt[i]=0; 
	}
	return 0;
}