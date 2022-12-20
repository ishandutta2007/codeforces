#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 2005
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int nn,mm,n,a[N],h[N][N][3],g[N][3],f[N][3],ans;

int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	f[1][a[1]]=1;
	for(int i=2; i<=n; ++i){
		if(a[i]==1)f[i][1]=f[i-1][1]+1,f[i][2]=f[i-1][2];
		else f[i][1]=f[i-1][1],f[i][2]=max(f[i-1][2],f[i-1][1])+1;
	}
	g[n][a[n]]=1;
	for(int i=n-1; i; --i){
		if(a[i]==2)g[i][2]=g[i+1][2]+1,g[i][1]=g[i+1][1];
		else g[i][2]=g[i+1][2],g[i][1]=max(g[i+1][2],g[i+1][1])+1;
	}
	
//	for(int i=1; i<=n; ++i)if(a[i]==1)o[i]=o[i-1]+1,p[i]=p[i-1];
//	else o[i]=o[i-1],p[i]=p[i-1]+1;//op id pos //uoj 1  / /// //// //  /\_///(_)//
	
	ans=max(f[n][1],f[n][2]);
	
	for(int i=1; i<=n; ++i)
	{
		h[i][i][a[i]]=1;
		for(int j=i+1; j<=n; ++j)
		if(a[j]==2)h[i][j][2]=h[i][j-1][2]+1,h[i][j][1]=h[i][j-1][1];
		else h[i][j][2]=h[i][j-1][2],h[i][j][1]=max(h[i][j-1][1],h[i][j-1][2])+1;
	}
	
	a[0]=1; a[n+1]=2;
	nn=n-2;
	mm=n+1;
	for(int i=0; i<=nn; ++i)if(a[i]==1)
	for(int j=i+3; j<=mm; ++j)if(a[j]==2){
		ans=max(ans,f[i][1]+g[j][2]+h[i+1][j-1][1]);
	}
	printf("%d\n",ans);
}