#include<bits/stdc++.h>
using namespace std;
int tot=1,n,m[11],a[11][200004],q;
map<int,int>son[1000004];
int f[12][1000004],fr[12][1000004];
void dfs(int x,int y){
	if(x==0)return;
	int tmp=fr[x][y],ret=f[x-1][tmp];
	dfs(x-1,tmp);
	for(int i=1;i<=m[x];i++)
		if(ret+a[x][i]==f[x][y])printf("%d ",i);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m[i]);
		for(int j=1;j<=m[i];j++)scanf("%d",&a[i][j]);
	}
	scanf("%d",&q);
	while(q--){
		int cur=1;
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			if(!son[cur][x])son[cur][x]=++tot;
			cur=son[cur][x];
		}
	}
	for(int i=0;i<12;i++)for(int j=0;j<1000004;j++)f[i][j]=-1e9;
	f[0][1]=0;
	for(int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]+a[i][m[i]];
		fr[i][0]=0;
		for(int j=1;j<=tot;j++)if(f[i-1][j]>=0){
			int s=m[i];
			while(son[j][s]>0){
				int tmp=son[j][s];
				if(f[i-1][j]+a[i][s]>f[i][tmp]){
					f[i][tmp]=f[i-1][j]+a[i][s];
					fr[i][tmp]=j;
				}
				s--;
			}
			if(s){
				if(f[i-1][j]+a[i][s]>f[i][0]){
					f[i][0]=f[i-1][j]+a[i][s];
					fr[i][0]=j;
				}
			}
		}
	}
	dfs(n,0);
}