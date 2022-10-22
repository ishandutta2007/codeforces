#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,K,a[103],p[103][103];
ll dp[103][103][103],ans=1e15;
int main(){
	for (int i=0;i<103;i++)for(int j=0;j<103;j++)for(int k=0;k<103;k++)dp[i][j][k]=1e15;
	read(n),read(m),read(K);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) read(p[i][j]);
	if (a[1]!=0) dp[1][a[1]][1]=0;
	else for (int i=1;i<=m;i++) dp[1][i][1]=p[1][i];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=K;k++){
				if (a[i]!=0){
					if (a[i]==j){
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
					}else{
						if (k+1>K) continue;
						dp[i][a[i]][k+1]=min(dp[i][a[i]][k+1],dp[i-1][j][k]);
					}
				}else{
					for (int c=1;c<=m;c++){
						if (j==c){
							dp[i][c][k]=min(dp[i][c][k],dp[i-1][j][k]+p[i][c]);
						}else{
							if (k+1>K) continue;
							dp[i][c][k+1]=min(dp[i][c][k+1],dp[i-1][j][k]+p[i][c]);
						}
					}
				}
			}
	for (int i=1;i<=m;i++) ans=min(ans,dp[n][i][K]);
	if (ans==1e15){
		puts("-1");return 0;
	}
	write(ans);
}