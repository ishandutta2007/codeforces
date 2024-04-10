#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,m,q,xa,ya,xb,yb,sum0[1005][1005],sum1[1005][1005];
char s[1005][1005];
inline int dfs(register int x,register int y,register int fg,register int posx,register int posy){
	if (posx==0||posy==0)return 0;
	if (posx==x){
		if (x==n){
			if (fg==0){
				if (posy%(2*m)<=m)return (sum0[n][m]+sum1[n][m])*(posy/(2*m))+sum0[n][posy%(2*m)];
				return (sum0[n][m]+sum1[n][m])*(posy/(2*m))+sum0[n][m]+sum1[n][posy%m];
			}
			if (posy%(2*m)<=m)return (sum0[n][m]+sum1[n][m])*(posy/(2*m))+sum1[n][posy%(2*m)];
			return (sum0[n][m]+sum1[n][m])*(posy/(2*m))+sum1[n][m]+sum0[n][posy%m];
		}
		return ((sum0[n][m]+sum1[n][m])*(posy/m)+(sum0[n][posy%m]+sum1[n][posy%m]))*(x/(2*n));
	}
	if (posy==y){
		if (y==m){
			if (fg==0){
				if (posx%(2*n)<=n)return (sum0[n][m]+sum1[n][m])*(posx/(2*n))+sum0[posx%(2*n)][m];
				return (sum0[n][m]+sum1[n][m])*(posx/(2*n))+sum0[n][m]+sum1[posx%n][m];
			}
			if (posx%(2*n)<=n)return (sum0[n][m]+sum1[n][m])*(posx/(2*n))+sum1[posx%(2*n)][m];
			return (sum0[n][m]+sum1[n][m])*(posx/(2*n))+sum1[n][m]+sum0[posx%n][m];
		}
		return ((sum0[n][m]+sum1[n][m])*(posx/n)+(sum0[posx%n][m]+sum1[posx%n][m]))*(y/(2*m));
	}
	if (x==n&&y==m){
		if (fg==0)return sum0[posx][posy];
		return sum1[posx][posy];
	}
	register int mx=x/2,my=y/2;
	if (posx<=mx){
		if (posy<=my)return dfs(mx,my,fg,posx,posy);
		return dfs(mx,my,fg,posx,my)+dfs(mx,my,fg^1,posx,posy-my);
	}
	else{
		if (posy<=my)return dfs(mx,my,fg,mx,posy)+dfs(mx,my,fg^1,posx-mx,posy);
		return dfs(mx,my,fg,mx,my)+dfs(mx,my,fg^1,mx,posy-my)+dfs(mx,my,fg^1,posx-mx,my)+dfs(mx,my,fg,posx-mx,posy-my);
	}
	return 0;
}
signed main(){
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			sum0[i][j]=sum0[i-1][j]+sum0[i][j-1]-sum0[i-1][j-1]+(s[i][j]=='1');
			sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+(s[i][j]=='0');
		}
	while(q--){
		scanf("%lld%lld%lld%lld",&xa,&ya,&xb,&yb);
		int x=n,y=m;
		while(x<xb||y<yb)x*=2,y*=2;
		printf("%lld\n",dfs(x,y,0,xb,yb)-dfs(x,y,0,xa-1,yb)-dfs(x,y,0,xb,ya-1)+dfs(x,y,0,xa-1,ya-1));
	}
	return 0;
}