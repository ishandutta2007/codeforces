#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#define ll long long
#pragma GCC optimize(2)
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
unordered_map<ll,int> pos[3];
int n,a[2][1000005],pre[3][1000005],prer[3][1000005];
ll sum[3][1000005];
unordered_map<int,int> f[1000005];
int g[1000005];
int dfs(int p0,int p1){
	if (p0==p1)return g[p0];
	if ((pre[0][p0]==-1||prer[0][p0]<=p1)&&(pre[1][p1]==-1||prer[1][p1]<=p0))return g[min(p0,p1)];
	int val=f[p0][p1];
	if (val!=0)return val-1;
	int ans=g[min(p0,p1)];
	if (pre[0][p0]!=-1&&p0>=p1&&prer[0][p0]>p1)ans=max(ans,1+dfs(pre[0][p0],p1));
	else if (pre[1][p1]!=-1&&prer[1][p1]>p0)ans=max(ans,1+dfs(p0,pre[1][p1]));
	f[p0][p1]=ans+1;
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[0][i]=read();
	for (int i=1;i<=n;i++)a[1][i]=read();
	pre[0][0]=pre[1][0]=pre[2][0]=-1;
	prer[0][0]=prer[1][0]=prer[2][0]=-1;
	pos[0][0]=pos[1][0]=pos[2][0]=1;
	for (int i=1;i<=n;i++){
		sum[0][i]=sum[0][i-1]+a[0][i];
		sum[1][i]=sum[1][i-1]+a[1][i];
		sum[2][i]=sum[2][i-1]+a[0][i]+a[1][i];
		pre[0][i]=pre[0][i-1],prer[0][i]=prer[0][i-1];
		pre[1][i]=pre[1][i-1],prer[1][i]=prer[1][i-1];
		pre[2][i]=pre[2][i-1],prer[2][i]=prer[2][i-1];
		int v0=pos[0][sum[0][i]]-1,v1=pos[1][sum[1][i]]-1,v2=pos[2][sum[2][i]]-1;
		if (v0>pre[0][i])pre[0][i]=v0,prer[0][i]=i;
		if (v1>pre[1][i])pre[1][i]=v1,prer[1][i]=i;
		if (v2>pre[2][i])pre[2][i]=v2,prer[2][i]=i;
		pos[0][sum[0][i]]=i+1;
		pos[1][sum[1][i]]=i+1;
		pos[2][sum[2][i]]=i+1;
	}
	for (int i=1;i<=n;i++){
		g[i]=max(g[i],g[i-1]);
		if (pre[2][i]!=-1)g[i]=max(g[i],g[pre[2][i]]+1);
		if (prer[0][i]==i)g[i]=max(g[i],1+dfs(pre[0][i],i));
		if (prer[1][i]==i)g[i]=max(g[i],1+dfs(i,pre[1][i]));
	}
	cout<<g[n]<<endl;
	return 0;
}