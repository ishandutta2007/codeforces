#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define inf 1000000000000000
using namespace std;
struct node{
	int a,b;
	node operator +(const node &x)const{
		node ans;
		ans.a=a+x.a;
		ans.b=b+x.b;
		return ans;
	}
	bool operator <(const node &x){
		return (a<x.a)||(a==x.a&&b<x.b);
	}
}c,nowc,f[3005][3005];
int t,n,m,b[3005],w[3005],u[6005],v[6005],first[3005],nxt[6005],size[3005];
inline int dfs(register int now,register int fa){
	register int size=1;
	for (register int i=0;i<=m;i++)f[now][i].a=f[now][i].b=-inf;
	f[now][1].a=0,f[now][1].b=w[now]-b[now];
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		int sv=dfs(v[i],now);
		for (register int j=m;j>=1;j--){
			nowc.a=nowc.b=-inf;
			for (register int k=max(1ll,j-sv);k<=size&&k<=j;k++){
				if (k<=j){
					c=f[now][k]+f[v[i]][j-k+1];
					if (nowc<c)nowc=c;
				}
				if (k<j){
					c.a=f[now][k].a+f[v[i]][j-k].a+(f[v[i]][j-k].b>0),c.b=f[now][k].b;
					if (nowc<c)nowc=c;
				}
			}
			f[now][j]=nowc;
		}
		size+=sv;
	}
	return size;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)scanf("%lld",&b[i]);
		for (int i=1;i<=n;i++)scanf("%lld",&w[i]);
		memset(first,0,sizeof(first));
		memset(nxt,0,sizeof(nxt));
		for (int i=1;i<n;i++){
			scanf("%lld%lld",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs(1,0);
		cout<<f[1][m].a+(f[1][m].b>0)<<endl;
	}
	return 0;
}