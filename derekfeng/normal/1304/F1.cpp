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
int n,m,K,d[53][20004],dp[53][20004],num[20004],num1[20004],ans=0;
int main(){
	read(n),read(m),read(K);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) read(d[i][j]),d[i][j]+=d[i][j-1];
	for (int i=1;i+K-1<=m;i++) dp[1][i]=d[1][i+K-1]-d[1][i-1];
	for (int i=2;i<=n;i++){
		for (int j=1;j+K-1<=m;j++) num[j]=max(num[j-1],dp[i-1][j]+d[i][j+K-1]-d[i][j-1]);
		for (int j=m-K+1;j>=1;j--) num1[j]=max(num1[j+1],dp[i-1][j]+d[i][j+K-1]-d[i][j-1]);
		for (int j=1;j+K-1<=m;j++){
			if (j>K) dp[i][j]=num[j-K]+d[i][j+K-1]-d[i][j-1];
			if (j+2*K-1<=m) dp[i][j]=max(dp[i][j],num1[j+K]+d[i][j+K-1]-d[i][j-1]); 
			for (int l=max(1,j-K+1),r=l+K-1;l<=j+K-1 && r<=m;l++,r++){
				int ld=min(l,j),rd=max(r,j+K-1);
				dp[i][j]=max(dp[i][j],dp[i-1][l]+d[i][rd]-d[i][ld-1]);
			}
		}
	}
	for (int i=1;i+K-1<=m;i++) ans=max(ans,dp[n][i]);
	write(ans);
}