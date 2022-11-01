//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=604,M=N*N;
int n,m,Q,ans,f[N][N],g[N],uu[M],vv[M],ww[M],in[M];
vector<pair<int,int> >vec[N];
signed main(){
	n=read();m=read();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1,u,v;i<=m;i++){
		u=uu[i]=read();v=vv[i]=read();
		f[u][v]=f[v][u]=ww[i]=read();
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	Q=read();
	for(int i=1,u,v,w;i<=Q;i++){
		u=read();v=read();w=read();
		vec[u].push_back(make_pair(v,w));
	}
	for(int i=1;i<=n;i++){
		memset(g,0,sizeof(g));
		for(auto v:vec[i]){
			for(int j=1;j<=n;j++)g[j]=max(g[j],v.second-f[j][v.first]);
		}
		for(int j=1;j<=m;j++)if(!in[j]){
			if(f[i][uu[j]]+ww[j]<=g[vv[j]]||f[i][vv[j]]+ww[j]<=g[uu[j]]){in[j]=1;ans++;}
		}
	}
	cout<<ans<<"\n";
	return (0-0);
}