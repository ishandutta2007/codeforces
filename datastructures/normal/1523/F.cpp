#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000
using namespace std;
struct node{
	int c,d,t;
	bool operator <(const node &x)const{
		return t<x.t;
	}
}qwq[105];
int n,m,a[105],b[105],c[105],d[105],t[105];
int d1[16384][15],d2[16384][105],f[16384][105],g[105];
int dis(int a,int b,int c,int d){
	int ans=max(a,c)-min(a,c);
	ans+=max(b,d)-min(b,d);
	return ans;
}
void dp(int s){
	for (int i=1;i<=m;i++)
		for (int j=1;j<i;j++)
			if (min(dis(c[i],d[i],c[j],d[j]),d2[s][i])<=t[i]-t[j])g[i]=max(g[i],g[j]+1);
	return;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)cin>>a[i]>>b[i];
	for (int i=1;i<=m;i++)cin>>qwq[i].c>>qwq[i].d>>qwq[i].t;
	sort(qwq+1,qwq+1+m);
	for (int i=1;i<=m;i++)c[i]=qwq[i].c,d[i]=qwq[i].d,t[i]=qwq[i].t;
	memset(d1,0x3f,sizeof(d1));
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				if (i&(1<<k))d1[i][j]=min(d1[i][j],dis(a[k],b[k],a[j],b[j]));
	memset(d2,0x3f,sizeof(d2));
	for (int i=0;i<(1<<n);i++)
		for (int j=1;j<=m;j++)
			for (int k=0;k<n;k++)
				if (i&(1<<k))d2[i][j]=min(d2[i][j],dis(a[k],b[k],c[j],d[j]));
	memset(f,0x3f,sizeof(f));
	for (int i=0;i<=m;i++)g[i]=-inf;
	for (int i=1;i<=m;i++)g[i]=1;
	dp(0);
	for (int i=1;i<=m;i++){
		if (g[i]<0)continue;
		f[0][g[i]]=min(f[0][g[i]],t[i]);
		for (int k=0;k<n;k++)
			f[(1<<k)][g[i]]=min(f[(1<<k)][g[i]],t[i]+dis(a[k],b[k],c[i],d[i]));
	}
	for (int i=0;i<n;i++)f[(1<<i)][0]=0;
	for (int s=0;s<(1<<n);s++){
		for (int i=0;i<=m;i++)
			for (int j=0;j<n;j++)
				if (!(s&(1<<j)))f[s|(1<<j)][i]=min(f[s|(1<<j)][i],f[s][i]+d1[s][j]);
		for (int i=0;i<=m;i++)g[i]=-inf;
		for (int i=0;i<=m;i++){
			for (int j=1;j<=m;j++)
				if (d2[s][j]<=t[j]-f[s][i])g[j]=max(g[j],i+1);
		}
		dp(s);
		for (int i=1;i<=m;i++){
			if (g[i]<0)continue;
			f[s][g[i]]=min(f[s][g[i]],t[i]);
			for (int j=0;j<n;j++)
				if (!(s&(1<<j)))f[s|(1<<j)][g[i]]=min(f[s|(1<<j)][g[i]],t[i]+min(d1[s][j],dis(a[j],b[j],c[i],d[i])));
		}
	}
	int ans=0;
	for (int i=0;i<(1<<n);i++)
		for (int j=1;j<=m;j++)
			if (f[i][j]<=inf)ans=max(ans,j);
	cout<<ans<<endl;
}