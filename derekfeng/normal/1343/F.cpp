#include<bits/stdc++.h>
using namespace std;
int T,n,a[205];
bitset<205>f[205],g[205];
bool vis[205],used[205];
void sol(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		f[i].reset();
		int K,X;scanf("%d",&K);
		while(K--)scanf("%d",&X),f[i][X]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++)g[j]=f[j],vis[j]=used[j]=0;
		a[1]=i;
		bool ok=1;
		for(int j=1;j<n;j++){
			int x=a[j],cnt=0,tot=0,pos;
			for(int k=1;k<n;k++)if(!vis[k]){
				if(used[k]&&!g[k][x])ok=0;
				if(g[k][x]){
					g[k][x]=0,++tot,used[k]=1;
					if(g[k].count()==1)cnt++,pos=k;
				}
			}
			if(cnt!=1||tot==0){ok=0;break;}
			a[j+1]=g[pos]._Find_first(),vis[pos]=1;
		}
		if(ok){
			for(int j=1;j<=n;j++)printf("%d ",a[j]);
			puts("");return;
		}
	}
}
int main(){for(scanf("%d",&T);T--;sol());}