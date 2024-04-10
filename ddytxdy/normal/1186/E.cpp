#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
int n,m,q,s[N][N],a[N][N],f[N][N][2],g[N][N][2],h[N][N][2];char c[N];
int Sum(int x,int y){
	// for(int i=)
	int d1=x/n,d2=y/m,k=0,dat=0,ret=0;
	for(int i=30;i;i--)if(d1>>i&1)
		dat+=(1<<i-1)*n*m,k^=1;
	if(d1&1)dat+=k?n*m-s[n][m]:s[n][m],k^=1;
	dat+=k?x%n*m-s[x%n][m]:s[x%n][m];k=0;//printf("%d %d %d\n",x,y,dat);
	for(int i=30;i;i--)if(d2>>i&1)
		ret+=(1<<i-1)*x*m,k^=1;
	if(d2&1)ret+=k?x*m-dat:dat,k^=1;
	for(int i=30;i;i--)if(d1>>i&1)
		ret+=(1<<i-1)*(y%m)*n,k^=1;
	if(d1&1)ret+=(k?y%m*n-s[n][y%m]:s[n][y%m]),k^=1;
	ret+=k?(x%n)*(y%m)-s[x%n][y%m]:s[x%n][y%m];
	// if(x==8&&y==5)printf("%d %d %d\n",x,y,ret);
	return ret;
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		for(int j=1;j<=m;j++)a[i][j]=c[j]-'0';
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]=s[i][j-1]+a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)s[i][j]+=s[i-1][j];
	// f[0][0][0]=s[n][m];f[0][0][1]=n*m-s[n][m];
	// for(int i=1;i<=30;i++)f[0][i][0]=
	for(int i=1,x1,y1,x2,y2;i<=q;i++){
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		printf("%lld\n",Sum(x2,y2)-Sum(x1-1,y2)-Sum(x2,y1-1)+Sum(x1-1,y1-1));
	}
}

// 2 3 1
// 100
// 101
// 8 6 8 12
// 1ll*(mod-mod/i)*inv[mod%i]%mod;
// mod-1ll*mod/i*inv[mod%i]%mod;