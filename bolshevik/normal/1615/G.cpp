#include<cstdio>
#include<iostream>
using namespace std;
const int o=3e5+10;
int yny[o*10],whx;
	namespace TreeWithFlower{
inline void read(int&a){a=yny[++whx];}
const int o=2e6;
#define ptn p
int n,m,h[o],cnt,ans,vis[o],ptn[o],asd;char s[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
bool dfs(int nw){
	vis[nw]=asd;
	for(int i=h[nw],j;i;i=e[i].p) if(vis[ptn[e[i].v]]^asd){
		ptn[j=ptn[e[i].v]]=0;ptn[ptn[nw]=e[i].v]=nw;
		if(!j||dfs(j)) return true;
		ptn[ptn[j]=e[i].v]=j;ptn[nw]=0;
	}
	return false;
}
inline void slv(){
	whx=0;read(n);read(m);
	for(int u,v;m--;){
		read(u);read(v);
		if(u^v) ad(u,v),ad(v,u);
	}
	for(int T=5;T--;){
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=1;i<=n;++i) if(!ptn[i]) if(dfs(asd=i)) T=5;
	}
}
	}
int n,a[o],M,x[o],y[o],cnt,tot,id[o],z;bool vis[o],e[610][610],t[o];
inline int New(){for(++z;t[z];++z);return z;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),M=max(M,a[i]),t[a[i]]=1;
	for(int i=1;i<n;++i) if(a[i]&&a[i]==a[i+1]&&!vis[a[i]]) vis[x[++cnt]=a[i]]=1,y[cnt]=++M;
	tot=M;
	for(int i=1,j;i<=n;++i) if(!a[i]){
		for(j=i;j<n&&!a[j+1];++j);
		if(i==1&&j==n){
			for(int k=0;k<n;++k) printf("%d ",k/2+1);
			return 0;
		}
		if(i==1){if((j-i+1)&1) x[++cnt]=a[j+1],y[cnt]=++tot;}
		else if(j==n){if((j-i+1)&1) x[++cnt]=a[i-1],y[cnt]=++tot;}
		else if((j-i)&1) x[++cnt]=a[i-1],y[cnt]=a[j+1];
		else x[++cnt]=++tot,y[cnt]=a[i-1],x[++cnt]=tot,y[cnt]=a[j+1];
		i=j;
	}
	yny[++whx]=tot;yny[++whx]=cnt;
	for(int i=1;i<=cnt;++i) yny[++whx]=x[i],yny[++whx]=y[i];
	TreeWithFlower::slv();
	for(int i=1,j;i<=n;++i) if(!a[i]){
		for(j=i;j<n&&!a[j+1];++j);
		if(i==1){
			for(int k=1;k<j;k+=2) a[k]=a[k+1]=New();
			if((j-i+1)&1) a[j]=a[j+1],++M;
		}
		else if(j==n){
			for(int k=n;k>i;k-=2) a[k]=a[k-1]=New();
			if((j-i+1)&1) a[i]=a[i-1],++M;
		}
		else if((j-i)&1) if(TreeWithFlower::p[a[i-1]]==a[j+1]&&!e[a[i-1]][a[j+1]]){
			a[i]=a[i-1];a[j]=a[j+1];e[a[i]][a[j]]=e[a[j]][a[i]]=1;
			for(int k=i+1;k<j;k+=2) a[k]=a[k+1]=New();
		}
		else for(int k=i;k<j;k+=2) a[k]=a[k+1]=New();
		else if(TreeWithFlower::p[++M]==a[i-1]){a[i]=a[i-1];for(int k=j;k>i;k-=2) a[k]=a[k-1]=New();}
		else{a[j]=a[j+1];for(int k=i;k<j;k+=2) a[k]=a[k+1]=New();}
		i=j;
	}
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}