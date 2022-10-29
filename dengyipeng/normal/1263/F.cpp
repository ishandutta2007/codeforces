#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 2005
#define maxp 11
using namespace std;

int n,i,j,k,f[maxn/2][maxn/2],p1[maxn],p2[maxn];
void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

struct graph{
	int n,em,e[maxn*2],nx[maxn*2],ls[maxn];
	int dep[maxn],f[maxn][maxp];
	void insert(int x,int y){
		em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
		em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
	}
	void DFS(int x,int p){
		f[x][0]=p,dep[x]=dep[p]+1;
		for(int i=1;i<maxp;i++) f[x][i]=f[f[x][i-1]][i-1];
		for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
			DFS(e[i],x);
	}
	int getlca(int x,int y){
		if (dep[x]<dep[y]) swap(x,y);
		for(int i=maxp-1;i>=0;i--) if (dep[f[x][i]]>=dep[y]) x=f[x][i];
		if (x==y) return x;
		for(int i=maxp-1;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}
	int Get(int x,int y){return dep[y]-dep[getlca(x,y)];}
} A,B;

int main(){
	read(n);
	read(A.n);
	for(i=2;i<=A.n;i++) read(k),A.insert(k,i);
	for(i=1;i<=n;i++) read(p1[i]); p1[0]=1;
	read(B.n);
	for(i=2;i<=B.n;i++) read(k),B.insert(k,i);
	for(i=1;i<=n;i++) read(p2[i]); p2[0]=1;
	A.DFS(1,0),B.DFS(1,0);
	memset(f,127,sizeof(f));
	f[0][0]=0;
	for(i=0;i<=n;i++) for(j=0;j<=n;j++) if (f[i][j]<1e9){
		k=max(i,j)+1;
		f[k][j]=min(f[k][j],f[i][j]+A.Get(p1[i],p1[k]));
		f[i][k]=min(f[i][k],f[i][j]+B.Get(p2[j],p2[k]));
	}
	int ans=1e9;
	for(i=0;i<n;i++) ans=min(ans,min(f[n][i],f[i][n])); 
	printf("%d",A.n-1+B.n-1-ans);
}