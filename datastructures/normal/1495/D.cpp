#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
using namespace std;
int n,m,c[405][405],tot[405];
int dis[405][405];
int main(){
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		c[u][++tot[u]]=v;
		c[v][++tot[v]]=u;
		dis[u][v]=dis[v][u]=1;
	}
	for (int i=1;i<=n;i++)dis[i][i]=0;
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int ans=1;
			int num=0;
			for (int k=1;k<=n;k++)
				if (dis[i][k]+dis[k][j]==dis[i][j])num++;
			if (num!=dis[i][j]+1){
				ans=0;
				printf("%d ",ans);
				continue;
			}
			for (int k=1;k<=n;k++){
				if (dis[i][k]+dis[k][j]==dis[i][j])continue;
				int s=0;
				for (int l=1;l<=tot[k];l++){
					int f=c[k][l];
					if (dis[i][k]==dis[i][f]+1&&dis[j][k]==dis[j][f]+1)s++;
				}
				ans=1ll*ans*s%mod;
			}
			printf("%d ",ans);
		}
		puts("");
	}
	return 0;
}