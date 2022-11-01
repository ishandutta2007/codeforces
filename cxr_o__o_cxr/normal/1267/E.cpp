//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=104;
int n,m,mx,id,a[N][N],f[N],g[N][N],ans[N];
inline void dfs(int u,int v,int p){
	if(!u)return;
	if(!g[u][v]){
		ans[p]=u;
		dfs(u-1,v,p+1);
	}
	else dfs(u-1,v-1,p);
}
#define max_(a,b) (a>b?a:b)
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	mx=0;
	for(int i=1,now;i<n;i++){
		memset(f,0xcf,sizeof(f));
		f[0]=0;
		for(int u=1;u<=m;u++)
			for(int j=u;j>=1;j--)
				f[j]=max_(f[j],f[j-1]+a[u][i]-a[u][n]);
		now=0;
		for(int j=m;j>=0;j--)
			if(f[j]>=0){
				now=j;
				break;
			}
		if(now>mx){
			mx=now;
			id=i;
		}	
	}
	cout<<m-mx<<"\n";
	if(mx==m)return (0-0);
	memset(f,0xcf,sizeof(f));
	f[0]=0;
	for(int u=1,x;u<=m;u++)
		for(int j=u;j>=1;j--){
			x=f[j-1]+a[u][id]-a[u][n];
			if(f[j]<x){
				f[j]=x;
				g[u][j]=1;
			}
		}
	dfs(m,mx,1);
	for(int i=m-mx;i>=1;i--)
		cout<<ans[i]<<" ";
	return (0-0);
}