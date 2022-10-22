#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
int n,k;
short dp[1003][2006];
int fr[1003][2006];
char s[1003];
void paths(int now,int x){
	if (now!=1) paths(now-1,fr[now][x]);
	if (fr[now][x]==x-1) putchar('W');
	if (fr[now][x]==x) putchar('D');
	if (fr[now][x]==x+1) putchar('L');
}
int main(){
	read(n),read(k);
	for (int i=1;i<=n;i++)
		s[i]=getchar();
	dp[0][k]=1;
	for (int i=1;i<=n;i++){
		if (s[i]=='W'){
			for (int j=2;j<=2*k;j++)
				if(dp[i-1][j-1]){
					dp[i][j]=1;
					fr[i][j]=j-1;
				}
		}
		if (s[i]=='D'){
			for (int j=1;j<2*k;j++)
				if(dp[i-1][j]){
					dp[i][j]=1;
					fr[i][j]=j;
				}
		}
		if (s[i]=='L'){
			for (int j=0;j<2*k-1;j++)
				if(dp[i-1][j+1]){
					dp[i][j]=1;
					fr[i][j]=j+1;
				}
		}
		if (s[i]=='?'){
			for (int j=2;j<=2*k;j++)
				if(dp[i-1][j-1]){
					dp[i][j]=1;
					fr[i][j]=j-1;
				}
			for (int j=1;j<2*k;j++)
				if(dp[i-1][j]){
					dp[i][j]=1;
					fr[i][j]=j;
				}
			for (int j=0;j<2*k-1;j++)
				if(dp[i-1][j+1]){
					dp[i][j]=1;
					fr[i][j]=j+1;
				}
		}
	}
	if (dp[n][0]==1){
		paths(n,0);return 0;
	}
	if (dp[n][2*k]==1){
		paths(n,2*k);return 0;
	}
	puts("NO");
}