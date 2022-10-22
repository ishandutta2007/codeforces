#include<cstdio>
#include<iostream>
using namespace std;
const int o=260,O=2500;
int T,n,m,e[o][o],f[O][o],cnt,pos[o],id,ans[o];
inline void opt(){
	for(int i=cnt;i>id;--i) if(f[i][m+1]){printf("-1");return;}
	for(int i=1;i<=id;++i) ans[pos[i]]=f[i][m+1];
	for(int i=1;i<=m;++i) printf("%d ",ans[i]+3*!ans[i]);
}
int main(){
	for(scanf("%d",&T);T--;opt(),putchar('\n'),cnt=id=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) e[i][j]=0;
		for(int i=1;i<O;++i) for(int j=1;j<o;++j) f[i][j]=0;
		for(int i=1,u,v,w;i<=m;++i){
			scanf("%d%d%d",&u,&v,&w);e[u][v]=e[v][u]=i;
			if(w+1) f[++cnt][i]=1,f[cnt][m+1]=w%3;
		}
		for(int i=1;i<n;++i) for(int j=n;j>i;--j) for(int k=n;k>j;--k)
			if(e[i][j]&&e[j][k]&&e[k][i]) f[++cnt][e[i][j]]=1,f[cnt][e[j][k]]=f[cnt][e[k][i]]=1;
		for(int i=1,j;i<=m;++i){
			for(j=id+1;j<=cnt;++j) if(f[j][i]) break;
			if(j>cnt){ans[i]=0;continue;}
			pos[++id]=i;
			for(int k=1;k<=m+1;++k) swap(f[id][k],f[j][k]);
			if(f[id][i]^1) for(j=i;j<=m+1;++j) f[id][j]^=3;
			for(j=1;j<=cnt;++j) if(f[j][i]&&j-id)
				for(int k=m+1;k>=i;--k) f[j][k]=(f[j][k]-f[id][k]*f[j][i]+9)%3;
		}
	}
	return 0;
}