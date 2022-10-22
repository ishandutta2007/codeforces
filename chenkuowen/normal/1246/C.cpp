#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2005,MOD=1e9+7;
typedef long long ll;
int a[MAX_N][MAX_N],top[MAX_N][MAX_N][2];
int d[MAX_N][MAX_N][2],f[MAX_N][MAX_N][2];
char s[MAX_N];
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			if(s[j]=='.') a[i][j]=0;
			else a[i][j]=1;
	}
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j){
			top[i][j][0]=top[i][j+1][0]+a[i][j];
			top[i][j][1]=top[i+1][j][1]+a[i][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			top[i][j][0]=m-top[i][j][0]+a[i][j];
			top[i][j][1]=n-top[i][j][1]+a[i][j];
		}
/*	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("(%d)",top[i][j][0]);
		puts("");
	}
	puts("----------");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("(%d)",top[i][j][1]);
		puts("");
	}
*/	f[1][1][0]=f[1][1][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
	/*		for(int x=j+1;x<=top[i][j][0];++x)
				mo(f[i][x][1]+=f[i][j][0]);
			for(int y=i+1;y<=top[i][j][1];++y)
				mo(f[y][j][0]+=f[i][j][1]);
	*/		
			mo(f[i][j][0]+=d[i][j][1]);
			mo(f[i][j][1]+=d[i][j][0]);
			mo(d[i+1][j][1]+=d[i][j][1]);
			mo(d[i][j+1][0]+=d[i][j][0]);
			d[i][j][0]=d[i][j][1]=0;
			if(j+1<=top[i][j][0]){
				mo(d[i][j+1][0]+=f[i][j][0]);
				mo(d[i][top[i][j][0]+1][0]+=MOD-f[i][j][0]);
			}
			if(i+1<=top[i][j][1]){
				mo(d[i+1][j][1]+=f[i][j][1]);
				mo(d[top[i][j][1]+1][j][1]+=MOD-f[i][j][1]);
			}
		}
/*	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("|%d|",f[i][j][0]);
		puts("");
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			printf("|%d|",f[i][j][1]);
		puts("");
	}*/
	if(n==1&&m==1) puts("1");
	else printf("%d\n",(f[n][m][0]+f[n][m][1])%MOD);
	return 0;
}