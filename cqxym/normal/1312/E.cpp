#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
vector<int>G[1020][501],V[502];
int f[502];
int main(){
	int n,x;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",&x);
		G[x][i].push_back(i);
	}
	for(R i=1;i!=1020;i++){
		for(R j=2;j<=n;j++){
			int l=G[i][j].size();
			for(R k=0;k!=l;k++){
				int u=G[i][j][k]-1;
				int tem=G[i][u].size();
				for(R p=0;p!=tem;p++){
					G[i+1][j].push_back(G[i][u][p]);
				}
			}
		}
	}
	for(R i=1;i!=1020;i++){
		for(R j=1;j<=n;j++){
			int l=G[i][j].size();
			for(R k=0;k!=l;k++){
				V[j].push_back(G[i][j][k]);
			}
		}
	}
	for(R i=1;i<=n;i++){
		f[i]=1e9;
		int l=V[i].size();
		for(R j=0;j!=l;j++){
			if(f[V[i][j]-1]+1<f[i]){
				f[i]=f[V[i][j]-1]+1;
			}
		}
	}
	printf("%d",f[n]);
	return 0;
}