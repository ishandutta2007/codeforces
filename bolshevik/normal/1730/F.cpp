#include<cstdio>
#include<iostream>
using namespace std;
const int o=5010,inf=1e9,chk=3e8;
inline void upd(int&a,int b){if(a>b) a=b;}
int n,K,p[o],q[o],f[o][9][1<<8],a[o][o];
inline int calc(int mx,int S,int app){
	int res=a[max(mx-K-1,0)][q[app]]+(q[mx]>q[app]);
	for(int i=1;i<=K&&mx-i;++i) if((S>>(i-1))&1) res+=(q[mx-i]>q[app]);
	return res;
}
int main(){
	scanf("%d%d",&n,&K);K=min(K,n-1);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]),q[p[i]]=i;
	for(int i=1;i<=n;++a[i][q[i]],++i) for(int j=1;j<=n;++j) a[i][j]=a[i-1][j];
	for(int i=1;i<=n;++i) for(int j=n;j;--j) a[i][j]+=a[i][j+1];
	for(int i=1;i<=n;++i) for(int j=0;j<=K;++j) for(int k=0;k<(1<<K);++k) f[i][j][k]=inf;
	for(int i=0;i<=K;++i) f[1][i][0]=0;
	for(int i=1;i<n;++i) for(int j=0;j<=K;++j) for(int k=0;k<(1<<K);++k) if(f[i][j][k]<chk){
		for(int $=1;$<=K&&i+j-$;++$) if(!((k>>($-1))&1)) upd(f[i+1][j-1][k|(1<<($-1))],f[i][j][k]+calc(i+j,k,i+j-$));
		for(int $=1;$<=K+1&&i+j+$<=n&&(i+j-K+$-1<1||$>K||((k>>(K-$))&1));++$)
			upd(f[i+1][j+$-1][((k<<$)|(1<<($-1)))&((1<<K)-1)],f[i][j][k]+calc(i+j,k,i+j+$));
	}
	printf("%d",f[n][0][(1<<K)-1]);
	return 0;
}