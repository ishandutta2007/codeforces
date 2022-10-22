#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n;string s;
int dp[503][503];
int main(){
	for (int i=0;i<503;i++)for (int j=0;j<503;j++)dp[i][j]=1e8;
	read(n),reads(s);
	s=" "+s;
	for (int k=1;k<=n;k++)
		for (int i=1;i+k-1<=n;i++){
			int j=i+k-1;
			if (k==1){
				dp[i][j]=1;
				continue;
			}
			if (s[i]==s[j]) dp[i][j]=dp[i+1][j];
			for (int l=i;l<j;l++)
				dp[i][j]=min(dp[i][j],dp[i][l]+dp[l+1][j]);
		}
	write(dp[1][n]);
}