#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=5*N,K=110;
int n,q;
int a[N],now[N];
double C[M][10];
double f[N][K];
signed main(){
	double res=0;
	C[0][0]=1;
	for(int i=1;i<M;i++)
		for(int j=0;j<=min(i,5);j++)
			if(j==0)C[i][j]=1;
			else C[i][j]=C[i-1][j]+C[i-1][j-1];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),f[i][now[i]=a[i]]=1,res+=f[i][0];
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		res-=f[u][0];
		for(int j=0;j<=a[u];j++){
			double _=0;
			for(int k=j;k<=min(j+w,a[u]);k++)
				_+=f[u][k]*C[k][k-j]*C[now[u]-k][w-(k-j)];
			f[u][j]=_/C[now[u]][w];
		}
		res+=f[u][0];
		now[u]-=w;
		now[v]+=w;
		printf("%.9lf\n",res);
	}
}