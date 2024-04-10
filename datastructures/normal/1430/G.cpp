#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,m,u,v,w,val[25],sum[300005],f[300005],last[300005],topo[300005],ans[25];
vector <int>e[25];
inline void gettopo(register int sta){
	for (register int i=0;i<n;i++){
		if ((sta&(1<<i))!=0)continue;
		register int len=e[i].size(),num=0;
		for (register int j=0;j<len;j++)
			if ((sta&(1<<e[i][j]))!=0)num++;
		if (num==len)topo[sta]|=(1<<i);
	}
	return;
}
inline void dfs(register int sta,register int now){
	if (sta==0)return;
	
	dfs(sta^last[sta],now+1);
	for (register int i=0;i<n;i++)
		if ((last[sta]&(1<<i))!=0)ans[i]=now;
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--,v--;
		val[u]+=w,val[v]-=w;
		e[v].push_back(u);
	}
	for (register int i=0;i<(1<<n);i++)
		for (register int j=0;j<n;j++)
			if ((i&(1<<j))!=0)sum[i]+=val[j];
	for (register int i=0;i<(1<<n);i++)
		gettopo(i);
	memset(f,0x7f,sizeof(f));
	f[0]=sum[(1<<n)-1]*(n-1);
	for (register int i=0;i<(1<<n);i++){
		if (f[i]>1e9)continue;
		for (register int j=topo[i];j;j=(j-1)&topo[i])
			if (f[i]-sum[((1<<n)-1)^(i|j)]<f[i|j])f[i|j]=f[i]-sum[((1<<n)-1)^(i|j)],last[i|j]=j;
	}
	dfs((1<<n)-1,0);
	for (int i=0;i<n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}