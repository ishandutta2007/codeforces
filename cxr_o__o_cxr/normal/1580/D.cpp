//starusc
#include<bits/stdc++.h>
using namespace std;
#define O(x) cerr<<(x)<<" : "<<#x<<"\n"
#define int long long
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=4004,inf=1e18;
int n,m,rt,a[N],lc[N],rc[N],siz[N],f[N][N];
int build(int l,int r){
	if(l>r)return 0;
	int p=l;
	for(int i=l+1;i<=r;i++)if(a[i]<a[p])p=i;
	lc[p]=build(l,p-1);
	rc[p]=build(p+1,r);
	return p;	
}
void dfs(int p){
	if(lc[p])dfs(lc[p]);
	if(rc[p])dfs(rc[p]);
	siz[p]=siz[lc[p]]+siz[rc[p]]+1;
	for(int i=0;i<=siz[lc[p]];i++)
		for(int j=0;j<=siz[rc[p]];j++){
			f[p][i+j]=max(f[p][i+j],f[lc[p]][i]+f[rc[p]][j]-i*j*2*a[p]);
			f[p][i+j+1]=max(f[p][i+j+1],f[lc[p]][i]+f[rc[p]][j]+(m-(i+1)*(j+1)*2+1)*a[p]);
		}
}
signed main(){	
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)f[i][j]=-inf;
	f[0][0]=0;
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	rt=build(1,n);
	dfs(rt);
	cout<<f[rt][m]<<"\n";
	return (0-0);
}