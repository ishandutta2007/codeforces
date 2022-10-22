#include<bits/stdc++.h>
using namespace std;
void chmin(int &x,int y){if(x>y)x=y;}
int n,m,q,ans=1e9,num[2];
int f[100005][2];
int g[100005][2];
char s[4][100005];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<4;i++)scanf("%s",s[i]+1);
	num[0]=num[1]=0;
	for(int i=1;i<=n;i++)num[s[0][i]=='B']++;
	f[1][0]=num[1]+(s[2][1]=='B')+(s[3][1]=='B');
	f[1][1]=num[0]+(s[2][1]=='R')+(s[3][1]=='R');
	for(int i=2;i<=m;i++){
		f[i][0]=f[i][1]=1e9;
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++){
				int t1=(s[2][i]=='B')^k;
				int t2=(s[3][i]=='B')^k;
				chmin(f[i][k],f[i-1][j]+t1+t2+(j^k)*n);
			}
	}
	num[0]=num[1]=0;
	for(int i=1;i<=n;i++)num[s[1][i]=='B']++;
	for(int i=0;i<2;i++)chmin(ans,f[m][i]+num[i^1]);
	num[0]=num[1]=0;
	for(int i=1;i<=m;i++)num[s[2][i]=='B']++;
	g[1][0]=num[1]+(s[0][1]=='B')+(s[1][1]=='B');
	g[1][1]=num[0]+(s[0][1]=='R')+(s[1][1]=='R');
	for(int i=2;i<=n;i++){
		g[i][0]=g[i][1]=1e9;
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++){
				int t1=(s[0][i]=='B')^k;
				int t2=(s[1][i]=='B')^k;
				chmin(g[i][k],g[i-1][j]+t1+t2+(j^k)*m);
			}
	}
	num[0]=num[1]=0;
	for(int i=1;i<=m;i++)num[s[3][i]=='B']++;
	for(int i=0;i<2;i++)chmin(ans,g[n][i]+num[i^1]);
	printf("%d",ans);
}