#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,dp[103][103][2],a[103],s[103],num[2];
int main(){
	read(n);
	for (int i=1;i<=n;i++){
		read(a[i]);
		if (a[i])num[a[i]%2]++;
		else s[i]++;
		s[i]=s[i-1]+s[i];
	}
	num[0]=n/2-num[0],num[1]=(n+1)/2-num[1];
	for (int i=0;i<103;i++)for(int j=0;j<103;j++)for(int k=0;k<2;k++)dp[i][j][k]=1e9;
	if (a[1]){
		dp[1][0][a[1]%2]=0;
	}else{
		for (int i=0;i<2;i++){
			if (1>num[i]) continue;
			dp[1][i^1][i%2]=0;
		}
	}
	for (int i=2;i<=n;i++)
		for (int j=0;j<=s[i-1];j++)
			for (int k=0;k<2;k++){
				if (dp[i-1][j][k]==1e9)continue;
				if (j>num[0] || s[i-1]-j>num[1]) continue;
				if (a[i]){
					dp[i][j][a[i]%2]=min(dp[i][j][a[i]%2],dp[i-1][j][k]+(k^(a[i]%2)));
					continue;
				}
				for (int l=0;l<2;l++){
					if (j+(l^1)>num[0]) continue;
					int go=j+(l^1);
					dp[i][go][l]=min(dp[i][go][l],dp[i-1][j][k]+(k^l));
				}
			}
	write(min(dp[n][num[0]][0],dp[n][num[0]][1]));
}