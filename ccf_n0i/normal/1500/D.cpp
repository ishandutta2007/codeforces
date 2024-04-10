#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int mc=1505*1505+5;
int n,q,i,j,a[1505][1505],vis[mc];
int f[2][1505][12],g[2][1505][12],tf[12],tg[12];
long long ans[1505],res[1505];
void merge(int a,int b,int c,int d){
	int i=1,j=1,k=1,p;
	rep(p,q){
		tf[p]=tg[p]=0x3f3f3f3f;
	}
	while(i<=q||j<=q){
		int cf,cg;
		if(i<=q&&(j>q||g[a][b][i]<g[c][d][j]+1)){
			cf=f[a][b][i];cg=g[a][b][i];
			i++;
		}
		else{
			cf=f[c][d][j];cg=g[c][d][j]+1;
			j++;
		}
		if(cf>mc||vis[cf]){
			continue;
		}
		vis[cf]=1;
		tf[k]=cf;tg[k]=cg;
		k++;if(k>q) break;
	}
	memcpy(f[a][b],tf,sizeof(tf));
	memcpy(g[a][b],tg,sizeof(tg));
	rep(p,k-1) vis[tf[p]]=0;
}
int main(){
	scanf("%d%d",&n,&q);q++;
	rep(i,n)rep(j,n) scanf("%d",&a[i][j]);
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(i=n;i>=1;i--){
		for(j=n;j>=1;j--){
			memset(g[i&1][j],0x3f,sizeof(g[i&1][j]));
			f[i&1][j][1]=a[i][j];
			g[i&1][j][1]=0;
			if(i<n)merge(i&1,j,(i+1)&1,j);
			if(j<n)merge(i&1,j,i&1,j+1);
			if(i<n&&j<n)merge(i&1,j,(i+1)&1,j+1);
			int len=min(min(n-i+1,n-j+1),g[i&1][j][q]);
			ans[len]++;
		}
	}
	for(i=n;i>=1;i--){
		ans[i]+=ans[i+1];
	}
	rep(i,n) printf("%I64d\n",ans[i]);
	return 0;
}