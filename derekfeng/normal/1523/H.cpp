#include<bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int n,m,a[20001];
int L[20001],R[20001],K[20001];
int f[15][31][20001],ans[20001];
int g[20001][31],ng[20001][31];
int st[15][20001],lg[20001];
void init(int *a){
	memcpy(st[0],a,(n+1)<<2);
	for(int t=1;t<15;t++)
		for(int i=1,j=(1<<(t-1))+1,k=1<<t;k<=n;i++,j++,k++)
			st[t][i]=max(st[t-1][i],st[t-1][j]);
}
int qry(int l,int r){
	int d=lg[r-l];
	return max(st[d][l],st[d][r-(1<<d)+1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)for(int j=0;j<31;j++)
		f[0][j][i]=min(i+a[i]+j,n);
	for(int t=1;t<15;t++)for(int q=0;q<31;q++){
		init(f[t-1][q]);
		for(int p=0;p+q<31;p++)for(int i=1;i<=n;i++)
			f[t][p+q][i]=max(f[t][p+q][i],qry(i,f[t-1][p][i]));
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&L[i],&R[i],&K[i]);
		for(int j=0;j<31;j++)g[i][j]=L[i];
	}
	for(int t=14;~t;t--){
		memset(ng,0,sizeof(ng));
		for(int p=0;p<31;p++){
			init(f[t][p]);
			for(int i=1;i<=m;i++)for(int q=0;p+q<=K[i];q++)
				ng[i][p+q]=max(ng[i][p+q],qry(L[i],g[i][q]));
		}
		for(int i=1;i<=m;i++)if(ng[i][K[i]]<R[i])
			ans[i]+=(1<<t),memcpy(g[i],ng[i],124);
	}
	for(int i=1;i<=m;i++)printf("%d\n",L[i]==R[i]?0:ans[i]+1);
}