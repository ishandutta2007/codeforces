#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int f[505][505],pos[505][505],a[505];
int merge(int x,int y){ return a[x]<a[y]?x:y; }
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i){
		pos[i][i]=i; 
		f[i][i]=f[i][i-1]=f[i][i+1]=f[i+1][i]=f[i-1][i]=1;
		for(int j=i+1;j<=m;++j)
			pos[i][j]=merge(pos[i][j-1],j);
	}
	for(int l=1;l<=m;++l)
		for(int i=1;i<=m-l+1;++i){
			int j=i+l-1,k1=0,k2=0,p=pos[i][j];
			for(int k=i;k<=p;++k)
				k1=(k1+1ll*f[i][k-1]*f[k][p-1])%MOD;
			for(int k=p;k<=j;++k)
				k2=(k2+1ll*f[p+1][k]*f[k+1][j])%MOD;
			f[i][j]=1ll*k1*k2%MOD;
		}
	printf("%d\n",f[1][n]);
	return 0;
}